$NetBSD: patch-.._.._ipxe_src_interface_efi_efi_snp.c,v 1.1.1.1 2016/07/04 07:30:49 jnemeth Exp $

--- ../../ipxe/src/interface/efi/efi_snp.c.orig	2015-01-25 20:37:13.000000000 +0000
+++ ../../ipxe/src/interface/efi/efi_snp.c
@@ -984,15 +984,16 @@ efi_snp_package_list ( struct efi_snp_de
 		struct efi_snp_formset formset;
 		union {
 			EFI_HII_STRING_PACKAGE_HDR strings;
-			uint8_t pad[strings_len];
 		} __attribute__ (( packed )) strings;
-		EFI_HII_PACKAGE_HEADER end;
 	} __attribute__ (( packed )) *package_list;
+	EFI_HII_PACKAGE_HEADER *end;
+	size_t plen = sizeof(*package_list) + strings_len + sizeof(*end);
 
 	/* Allocate package list */
-	package_list = zalloc ( sizeof ( *package_list ) );
+	package_list = zalloc ( plen );
 	if ( ! package_list )
 		return NULL;
+	end = (char *)package_list + plen - sizeof(*end);
 
 	/* Create a unique GUID for this package list and formset */
 	efi_snp_formset.FormSet.FormSet.Guid.Data1++;
@@ -1001,13 +1002,13 @@ efi_snp_package_list ( struct efi_snp_de
 	memcpy ( &package_list->header.PackageListGuid,
 		 &efi_snp_formset.FormSet.FormSet.Guid,
 		 sizeof ( package_list->header.PackageListGuid ) );
-	package_list->header.PackageLength = sizeof ( *package_list );
+	package_list->header.PackageLength = plen;
 	memcpy ( &package_list->formset, &efi_snp_formset,
 		 sizeof ( package_list->formset ) );
 	efi_snp_strings ( &package_list->strings.strings,
-			  sizeof ( package_list->strings ), snpdev );
-	package_list->end.Length = sizeof ( package_list->end );
-	package_list->end.Type = EFI_HII_PACKAGE_END;
+			  strings_len, snpdev );
+	end->Length = sizeof ( *end );
+	end->Type = EFI_HII_PACKAGE_END;
 
 	return &package_list->header;
 }
