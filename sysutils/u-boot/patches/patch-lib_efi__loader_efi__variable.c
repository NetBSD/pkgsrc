$NetBSD: patch-lib_efi__loader_efi__variable.c,v 1.1 2019/04/12 07:08:15 skrll Exp $

--- lib/efi_loader/efi_variable.c.orig	2019-04-06 16:01:44.521947778 +0000
+++ lib/efi_loader/efi_variable.c
@@ -8,6 +8,10 @@
 #include <malloc.h>
 #include <charset.h>
 #include <efi_loader.h>
+#include <hexdump.h>
+#include <environment.h>
+#include <search.h>
+#include <uuid.h>
 
 #define READ_ONLY BIT(31)
 
@@ -98,6 +102,19 @@ static char *mem2hex(char *hexstr, const
 	return hexstr;
 }
 
+/**
+ * efi_to_native() - convert the UEFI variable name and vendor GUID to U-Boot
+ *		     variable name
+ *
+ * The U-Boot variable name is a concatenation of prefix 'efi', the hexstring
+ * encoded vendor GUID, and the UTF-8 encoded UEFI variable name separated by
+ * underscores, e.g. 'efi_8be4df61-93ca-11d2-aa0d-00e098032b8c_BootOrder'.
+ *
+ * @native:		pointer to pointer to U-Boot variable name
+ * @variable_name:	UEFI variable name
+ * @vendor:		vendor GUID
+ * Return:		status code
+ */
 static efi_status_t efi_to_native(char **native, const u16 *variable_name,
 				  efi_guid_t *vendor)
 {
@@ -116,6 +133,15 @@ static efi_status_t efi_to_native(char *
 	return EFI_SUCCESS;
 }
 
+/**
+ * prefix() - skip over prefix
+ *
+ * Skip over a prefix string.
+ *
+ * @str:	string with prefix
+ * @prefix:	prefix string
+ * Return:	string without prefix, or NULL if prefix not found
+ */
 static const char *prefix(const char *str, const char *prefix)
 {
 	size_t n = strlen(prefix);
@@ -124,7 +150,16 @@ static const char *prefix(const char *st
 	return NULL;
 }
 
-/* parse attributes part of variable value, if present: */
+/**
+ * parse_attr() - decode attributes part of variable value
+ *
+ * Convert the string encoded attributes of a UEFI variable to a bit mask.
+ * TODO: Several attributes are not supported.
+ *
+ * @str:	value of U-Boot variable
+ * @attrp:	pointer to UEFI attributes
+ * Return:	pointer to remainder of U-Boot variable value
+ */
 static const char *parse_attr(const char *str, u32 *attrp)
 {
 	u32 attr = 0;
@@ -162,7 +197,21 @@ static const char *parse_attr(const char
 	return str;
 }
 
-/* http://wiki.phoenix.com/wiki/index.php/EFI_RUNTIME_SERVICES#GetVariable.28.29 */
+/**
+ * efi_efi_get_variable() - retrieve value of a UEFI variable
+ *
+ * This function implements the GetVariable runtime service.
+ *
+ * See the Unified Extensible Firmware Interface (UEFI) specification for
+ * details.
+ *
+ * @variable_name:	name of the variable
+ * @vendor:		vendor GUID
+ * @attributes:		attributes of the variable
+ * @data_size:		size of the buffer to which the variable value is copied
+ * @data:		buffer to which the variable value is copied
+ * Return:		status code
+ */
 efi_status_t EFIAPI efi_get_variable(u16 *variable_name, efi_guid_t *vendor,
 				     u32 *attributes, efi_uintn_t *data_size,
 				     void *data)
@@ -241,17 +290,179 @@ efi_status_t EFIAPI efi_get_variable(u16
 	return EFI_EXIT(EFI_SUCCESS);
 }
 
-/* http://wiki.phoenix.com/wiki/index.php/EFI_RUNTIME_SERVICES#GetNextVariableName.28.29 */
+static char *efi_variables_list;
+static char *efi_cur_variable;
+
+/**
+ * parse_uboot_variable() - parse a u-boot variable and get uefi-related
+ *			    information
+ * @variable:		whole data of u-boot variable (ie. name=value)
+ * @variable_name_size: size of variable_name buffer in byte
+ * @variable_name:	name of uefi variable in u16, null-terminated
+ * @vendor:		vendor's guid
+ * @attributes:		attributes
+ *
+ * A uefi variable is encoded into a u-boot variable as described above.
+ * This function parses such a u-boot variable and retrieve uefi-related
+ * information into respective parameters. In return, variable_name_size
+ * is the size of variable name including NULL.
+ *
+ * Return:		EFI_SUCCESS if parsing is OK, EFI_NOT_FOUND when
+			the entire variable list has been returned,
+			otherwise non-zero status code
+ */
+static efi_status_t parse_uboot_variable(char *variable,
+					 efi_uintn_t *variable_name_size,
+					 u16 *variable_name,
+					 const efi_guid_t *vendor,
+					 u32 *attributes)
+{
+	char *guid, *name, *end, c;
+	unsigned long name_len;
+	u16 *p;
+
+	guid = strchr(variable, '_');
+	if (!guid)
+		return EFI_INVALID_PARAMETER;
+	guid++;
+	name = strchr(guid, '_');
+	if (!name)
+		return EFI_INVALID_PARAMETER;
+	name++;
+	end = strchr(name, '=');
+	if (!end)
+		return EFI_INVALID_PARAMETER;
+
+	name_len = end - name;
+	if (*variable_name_size < (name_len + 1)) {
+		*variable_name_size = name_len + 1;
+		return EFI_BUFFER_TOO_SMALL;
+	}
+	end++; /* point to value */
+
+	/* variable name */
+	p = variable_name;
+	utf8_utf16_strncpy(&p, name, name_len);
+	variable_name[name_len] = 0;
+	*variable_name_size = name_len + 1;
+
+	/* guid */
+	c = *(name - 1);
+	*(name - 1) = '\0'; /* guid need be null-terminated here */
+	uuid_str_to_bin(guid, (unsigned char *)vendor, UUID_STR_FORMAT_GUID);
+	*(name - 1) = c;
+
+	/* attributes */
+	parse_attr(end, attributes);
+
+	return EFI_SUCCESS;
+}
+
+/**
+ * efi_get_next_variable_name() - enumerate the current variable names
+ * @variable_name_size:	size of variable_name buffer in byte
+ * @variable_name:	name of uefi variable's name in u16
+ * @vendor:		vendor's guid
+ *
+ * This function implements the GetNextVariableName service.
+ *
+ * See the Unified Extensible Firmware Interface (UEFI) specification for
+ * details: http://wiki.phoenix.com/wiki/index.php/
+ *		EFI_RUNTIME_SERVICES#GetNextVariableName.28.29
+ *
+ * Return: status code
+ */
 efi_status_t EFIAPI efi_get_next_variable_name(efi_uintn_t *variable_name_size,
-					       u16 *variable_name,
-					       efi_guid_t *vendor)
+                                               u16 *variable_name,
+                                               efi_guid_t *vendor)
 {
+	char *native_name, *variable;
+	ssize_t name_len, list_len;
+	char regex[256];
+	char * const regexlist[] = {regex};
+	u32 attributes;
+	int i;
+	efi_status_t ret;
+
 	EFI_ENTRY("%p \"%ls\" %pUl", variable_name_size, variable_name, vendor);
 
-	return EFI_EXIT(EFI_DEVICE_ERROR);
+	if (!variable_name_size || !variable_name || !vendor)
+		return EFI_EXIT(EFI_INVALID_PARAMETER);
+
+	if (variable_name[0]) {
+		/* check null-terminated string */
+		for (i = 0; i < *variable_name_size; i++)
+			if (!variable_name[i])
+				break;
+		if (i >= *variable_name_size)
+			return EFI_EXIT(EFI_INVALID_PARAMETER);
+
+		/* search for the last-returned variable */
+		ret = efi_to_native(&native_name, variable_name, vendor);
+		if (ret)
+			return EFI_EXIT(ret);
+
+		name_len = strlen(native_name);
+		for (variable = efi_variables_list; variable && *variable;) {
+			if (!strncmp(variable, native_name, name_len) &&
+			    variable[name_len] == '=')
+				break;
+
+			variable = strchr(variable, '\n');
+			if (variable)
+				variable++;
+		}
+
+		free(native_name);
+		if (!(variable && *variable))
+			return EFI_EXIT(EFI_INVALID_PARAMETER);
+
+		/* next variable */
+		variable = strchr(variable, '\n');
+		if (variable)
+			variable++;
+		if (!(variable && *variable))
+			return EFI_EXIT(EFI_NOT_FOUND);
+	} else {
+		/*
+		 *new search: free a list used in the previous search
+		 */
+		free(efi_variables_list);
+		efi_variables_list = NULL;
+		efi_cur_variable = NULL;
+
+		snprintf(regex, 256, "efi_.*-.*-.*-.*-.*_.*");
+		list_len = hexport_r(&env_htab, '\n',
+				     H_MATCH_REGEX | H_MATCH_KEY,
+				     &efi_variables_list, 0, 1, regexlist);
+		/* 1 indicates that no match was found */
+		if (list_len <= 1)
+			return EFI_EXIT(EFI_NOT_FOUND);
+
+		variable = efi_variables_list;
+	}
+
+	ret = parse_uboot_variable(variable, variable_name_size, variable_name,
+				   vendor, &attributes);
+
+	return EFI_EXIT(ret);
 }
 
-/* http://wiki.phoenix.com/wiki/index.php/EFI_RUNTIME_SERVICES#SetVariable.28.29 */
+/**
+ * efi_efi_set_variable() - set value of a UEFI variable
+ *
+ * This function implements the SetVariable runtime service.
+ *
+ * See the Unified Extensible Firmware Interface (UEFI) specification for
+ * details.
+ *
+ * @variable_name:	name of the variable
+ * @vendor:		vendor GUID
+ * @attributes:		attributes of the variable
+ * @data_size:		size of the buffer with the variable value
+ * @data:		buffer with the variable value
+ * Return:		status code
+ */
 efi_status_t EFIAPI efi_set_variable(u16 *variable_name, efi_guid_t *vendor,
 				     u32 attributes, efi_uintn_t data_size,
 				     void *data)
