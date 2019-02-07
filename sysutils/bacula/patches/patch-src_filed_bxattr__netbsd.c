$NetBSD: patch-src_filed_bxattr__netbsd.c,v 1.1 2019/02/07 11:29:31 markd Exp $

NetBSD has xattr.

--- /dev/null	2019-02-04 11:43:19.480511265 +0000
+++ src/filed/bxattr_netbsd.c
@@ -0,0 +1,465 @@
+/*
+   Bacula(R) - The Network Backup Solution
+
+   Copyright (C) 2000-2016 Kern Sibbald
+
+   The original author of Bacula is Kern Sibbald, with contributions
+   from many others, a complete list can be found in the file AUTHORS.
+
+   You may use this file and others of this release according to the
+   license defined in the LICENSE file, which includes the Affero General
+   Public License, v3.0 ("AGPLv3") and some additional permissions and
+   terms pursuant to its AGPLv3 Section 7.
+
+   This notice must be preserved when any source code is
+   conveyed and/or propagated.
+
+   Bacula(R) is a registered trademark of Kern Sibbald.
+ */
+/**
+ * Major refactoring of XATTR code written by:
+ *
+ *  Radosław Korzeniewski, MMXVI
+ *  radoslaw@korzeniewski.net, radekk@inteos.pl
+ *  Inteos Sp. z o.o. http://www.inteos.pl/
+ *
+ */
+
+#include "bacula.h"
+#include "filed.h"
+#include "bxattr_netbsd.h"
+
+#if defined(HAVE_NETBSD_OS)
+
+/* check if XATTR support is enabled */
+#if defined(HAVE_XATTR)
+
+/*
+ * Define the supported XATTR streams for this OS
+ */
+static const int os_xattr_streams[] = {
+   STREAM_XACL_NETBSD_XATTR,
+   0
+};
+
+static const int os_xattr_namespaces[] = {
+   EXTATTR_NAMESPACE_USER,
+   EXTATTR_NAMESPACE_SYSTEM,
+   -1
+};
+
+static const char *os_xattr_acl_skiplist[] = {
+   "system.posix1e.acl_access",
+   "system.posix1e.acl_default",
+   "system.nfs4.acl",
+   NULL
+};
+
+static const char *os_xattr_skiplist[] = {
+   NULL
+};
+
+/*
+ * OS specific constructor
+ */
+BXATTR_NetBSD::BXATTR_NetBSD()
+{
+   set_xattr_streams(os_xattr_streams);
+   set_xattr_skiplists(os_xattr_skiplist, os_xattr_acl_skiplist);
+};
+
+/*
+ * Perform OS specific extended attribute backup
+ *
+ * in/out - check API at bxattr.h
+ */
+bRC_BXATTR BXATTR_NetBSD::os_backup_xattr (JCR *jcr, FF_PKT *ff_pkt){
+
+   bRC_BXATTR rc;
+   POOLMEM *xlist;
+   uint32_t xlen;
+   char *name;
+   uint32_t name_len;
+   POOLMEM *value;
+   uint32_t value_len;
+   POOLMEM *name_gen;
+   uint32_t name_gen_len;
+   char * namespace_str;
+   int namespace_len;
+   bool skip;
+   alist *xattr_list = NULL;
+   int xattr_count = 0;
+   uint32_t len = 0;
+   BXATTR_xattr *xattr;
+   int a;
+
+   for (a = 0; os_xattr_namespaces[a] != -1; a++){ // loop through all available namespaces
+      /* xlist is allocated as POOLMEM by os_get_xattr_names_local */
+      rc = os_get_xattr_names_local(jcr, os_xattr_namespaces[a], &xlist, &xlen);
+      switch (rc){
+         case bRC_BXATTR_ok:
+            /* it's ok, so go further */
+            break;
+         case bRC_BXATTR_skip:
+         case bRC_BXATTR_cont:
+            /* no xattr available, so skip rest of it */
+            return bRC_BXATTR_ok;
+         default:
+            return rc;
+      }
+
+      /* get a string representation of the namespace */
+      if (extattr_namespace_to_string(os_xattr_namespaces[a], &namespace_str) != 0){
+         Mmsg2(jcr->errmsg, _("Failed to convert %d into namespace on file \"%s\"\n"), os_xattr_namespaces[a], jcr->last_fname);
+         Dmsg2(100, "Failed to convert %d into namespace on file \"%s\"\n", os_xattr_namespaces[a], jcr->last_fname);
+         goto bail_out;
+      }
+      namespace_len = strlen(namespace_str);
+
+      /* follow the list of xattr names and get the values */
+      for (name = xlist; (name - xlist) + 1 < xlen; name = strchr(name, '\0') + 1){
+         name_len = strlen(name);
+         name_gen = get_pool_memory(PM_FNAME);
+         name_gen = check_pool_memory_size(name_gen, name_len + namespace_len + 2);
+         bsnprintf(name_gen, name_len + namespace_len + 2, "%s.%s", namespace_str, name);
+         name_gen_len = strlen(name_gen);
+
+         skip =  check_xattr_skiplists(jcr, ff_pkt, name_gen);
+         if (skip || name_len == 0){
+            Dmsg1(100, "Skipping xattr named %s\n", name_gen);
+            continue;
+         }
+
+         /* value is allocated as POOLMEM by os_get_xattr_value_local */
+         rc = os_get_xattr_value_local(jcr, os_xattr_namespaces[a], name, &value, &value_len);
+         switch (rc){
+            case bRC_BXATTR_ok:
+               /* it's ok, so go further */
+               break;
+            case bRC_BXATTR_skip:
+               /* no xattr available, so skip rest of it */
+               rc = bRC_BXATTR_ok;
+               goto bail_out;
+            default:
+               /* error / fatal */
+               goto bail_out;
+         }
+
+         /*
+          * we have a name of the extended attribute in the name variable
+          * and value of the extended attribute in the value variable
+          * so we need to build a list
+          */
+         xattr = (BXATTR_xattr*)malloc(sizeof(BXATTR_xattr));
+         xattr->name_len = name_gen_len;
+         xattr->name = name_gen;
+         xattr->value_len = value_len;
+         xattr->value = value;
+         /*       magic              name_len          name        value_len       value */
+         len += sizeof(uint32_t) + sizeof(uint32_t) + name_gen_len + sizeof(uint32_t) + value_len;
+
+         if (xattr_list == NULL){
+            xattr_list = New(alist(10, not_owned_by_alist));
+         }
+         xattr_list->append(xattr);
+         xattr_count++;
+      }
+      if (xattr_count > 0){
+         /* serialize the stream */
+         rc = serialize_xattr_stream(jcr, len, xattr_list);
+         if (rc != bRC_BXATTR_ok){
+            Mmsg(jcr->errmsg, _("Failed to serialize extended attributes on file \"%s\"\n"), jcr->last_fname);
+            Dmsg1(100, "Failed to serialize extended attributes on file \"%s\"\n", jcr->last_fname);
+            goto bail_out;
+         } else {
+            /* send data to SD */
+            rc = send_xattr_stream(jcr, STREAM_XACL_NETBSD_XATTR);
+         }
+      } else {
+         rc = bRC_BXATTR_ok;
+      }
+   }
+bail_out:
+   /* free allocated data */
+   if (xattr_list != NULL){
+      foreach_alist(xattr, xattr_list){
+         if (xattr == NULL){
+            break;
+         }
+         if (xattr->name){
+            free_pool_memory(name_gen);
+         }
+         if (xattr->value){
+            free(xattr->value);
+         }
+         free(xattr);
+      }
+      delete xattr_list;
+   }
+   if (xlist != NULL){
+      free(xlist);
+   }
+
+   return rc;
+};
+
+/*
+ * Perform OS specific XATTR restore. Runtime is called only when stream is supported by OS.
+ *
+ * in/out - check API at bxattr.h
+ */
+bRC_BXATTR BXATTR_NetBSD::os_restore_xattr (JCR *jcr, int stream, char *content, uint32_t length){
+   return generic_restore_xattr(jcr, stream);
+};
+
+/*
+ * Return a list of xattr names in newly allocated pool memory and a length of the allocated buffer.
+ * It allocates a memory with poolmem subroutines every time a function is called, so it must be freed
+ * when not needed.
+ *
+ * in/out - check API at bxattr.h
+ *
+ * As a FreeBSD uses a different attributes name schema/format then this method is a very different
+ * from a standard generic method because it uses a namespace (ns) value for os dependent optimization.
+ */
+bRC_BXATTR BXATTR_NetBSD::os_get_xattr_names_local (JCR *jcr, int ns, POOLMEM ** pxlist, uint32_t * xlen){
+
+   int len;
+   POOLMEM * list;
+   int a;
+   int stra;
+   POOLMEM * genlist;
+
+   /* check input data */
+   if (jcr == NULL || xlen == NULL || pxlist == NULL){
+      return bRC_BXATTR_inval;
+   }
+   /* get the length of the extended attributes */
+   len = extattr_list_link(jcr->last_fname, ns, NULL, 0);
+   switch (len){
+      case -1: {
+         berrno be;
+
+         switch (errno){
+            case ENOENT:
+               /* no file available, skip it */
+               return bRC_BXATTR_skip;
+            case EOPNOTSUPP:
+               /* no xattr supported on filesystem, clear a flag and skip it */
+               clear_flag(BXATTR_FLAG_NATIVE);
+               set_content(NULL);
+               return bRC_BXATTR_skip;
+            case EPERM:
+               if (ns == EXTATTR_NAMESPACE_SYSTEM){
+                  return bRC_BXATTR_cont;
+               } /* else show error */
+            default:
+               Mmsg2(jcr->errmsg, _("extattr_list_link error on file \"%s\": ERR=%s\n"), jcr->last_fname, be.bstrerror());
+               Dmsg2(100, "extattr_list_link error file=%s ERR=%s\n", jcr->last_fname, be.bstrerror());
+               return bRC_BXATTR_error;
+         }
+         break;
+      }
+      case 0:
+         /* xattr available but empty, skip it */
+         return bRC_BXATTR_skip;
+      default:
+         break;
+   }
+
+   /*
+    * allocate memory for the extented attribute list
+    * default size is a 4k for PM_BSOCK, which should be sufficient on almost all
+    * Linux system where xattrs a limited in size to single filesystem block ~4kB
+    * so we need to check required size
+    */
+   list = get_pool_memory(PM_BSOCK);
+   list = check_pool_memory_size(list, len + 1);
+   memset(list, 0, len + 1);
+
+   /* get the list of extended attributes names for a file */
+   len = extattr_list_link(jcr->last_fname, ns, list, len);
+   switch (len){
+   case -1: {
+      berrno be;
+
+      switch (errno){
+      case ENOENT:
+         /* no file available, skip it, first release allocated memory */
+         free_pool_memory(list);
+         return bRC_BXATTR_skip;
+         case EPERM:
+            if (ns == EXTATTR_NAMESPACE_SYSTEM){
+               return bRC_BXATTR_cont;
+            } /* else show error */
+      default:
+         Mmsg2(jcr->errmsg, _("extattr_list_link error on file \"%s\": ERR=%s\n"), jcr->last_fname, be.bstrerror());
+         Dmsg2(100, "extattr_list_link error file=%s ERR=%s\n", jcr->last_fname, be.bstrerror());
+         free_pool_memory(list);
+         return bRC_BXATTR_error;
+      }
+      break;
+   }
+   default:
+      break;
+   }
+   /* convert FreeBSD list type to the generic one */
+   genlist = get_pool_memory(PM_BSOCK);
+   genlist = check_pool_memory_size(genlist, len + 1);
+   memset(genlist, 0, len + 1);
+   for (a = 0; a < len; a += list[a] + 1){
+      stra = list[a];
+      memcpy(genlist + a, list + a + 1, stra);
+      genlist[a + stra] = '\0';
+   }
+   free_pool_memory(list);
+   /* setup return data */
+   *pxlist = genlist;
+   *xlen = len;
+   return bRC_BXATTR_ok;
+};
+
+/*
+ * Return a value of the requested attribute name and a length of the allocated buffer.
+ * It allocates a memory with poolmem subroutines every time a function is called, so it must be freed
+ * when not needed.
+ *
+ * in/out - check API at bxattr.h
+ *
+ * As a FreeBSD uses a different attributes name schema/format then this method is a very different
+ * from a standard generic method because it uses a namespace (ns) value for os dependent optimization.
+ */
+bRC_BXATTR BXATTR_NetBSD::os_get_xattr_value_local (JCR *jcr, int ns, char * name, char ** pvalue, uint32_t * plen){
+
+   int len;
+   POOLMEM * value;
+
+   /* check input data */
+   if (jcr == NULL || name == NULL || plen == NULL || pvalue == NULL){
+      return bRC_BXATTR_inval;
+   }
+   /* get the length of the value for extended attribute */
+   len = extattr_get_link(jcr->last_fname, ns, name, NULL, 0);
+   switch (len){
+      case -1: {
+         berrno be;
+
+         switch (errno){
+            case ENOENT:
+               /* no file available, skip it */
+               return bRC_BXATTR_skip;
+            default:
+               /* XXX: what about ENOATTR error value? */
+               Mmsg2(jcr->errmsg, _("extattr_get_link error on file \"%s\": ERR=%s\n"), jcr->last_fname, be.bstrerror());
+               Dmsg2(100, "extattr_get_link error file=%s ERR=%s\n", jcr->last_fname, be.bstrerror());
+               return bRC_BXATTR_error;
+         }
+         break;
+      }
+      default:
+         break;
+   }
+
+   if (len > 0){
+      /*
+       * allocate memory for the extented attribute value
+       * default size is a 256B for PM_MESSAGE, so we need to check required size
+       */
+      value = get_pool_memory(PM_MESSAGE);
+      value = check_pool_memory_size(value, len + 1);
+      memset(value, 0, len + 1);
+      /* value is not empty, get a data */
+      len = extattr_get_link(jcr->last_fname, ns, name, value, len);
+      switch (len){
+      case -1: {
+         berrno be;
+
+         switch (errno){
+         case ENOENT:
+            /* no file available, skip it, first release allocated memory */
+            free_pool_memory(value);
+            return bRC_BXATTR_skip;
+         default:
+            Mmsg2(jcr->errmsg, _("extattr_get_link error on file \"%s\": ERR=%s\n"), jcr->last_fname, be.bstrerror());
+            Dmsg2(100, "extattr_get_link error file=%s ERR=%s\n", jcr->last_fname, be.bstrerror());
+            free_pool_memory(value);
+            return bRC_BXATTR_error;
+         }
+         break;
+      }
+      default:
+         break;
+      }
+      /* ensure a value is nul terminated */
+      value[len] = '\0';
+   } else {
+      /* empty value */
+      value = NULL;
+      len = 0;
+   }
+   /* setup return data */
+   *pvalue = value;
+   *plen = len;
+   return bRC_BXATTR_ok;
+};
+
+/*
+ * Low level OS specific runtime to set extended attribute on file
+ *
+ * in/out - check API at bxattr.h
+ *
+ * xattr->name should be in '<namespace>.<name>' format which
+ * function handle without problem, otherwise it returns an error
+ * TODO: it is possible to handle a different attributes name format
+ * for OS portability where default namespace 'user' can be used
+ */
+bRC_BXATTR BXATTR_NetBSD::os_set_xattr (JCR *jcr, BXATTR_xattr *xattr){
+
+   char * name;
+   char * nspace;
+   int ns;
+   int rc;
+
+   /* check input data */
+   if (jcr == NULL || xattr == NULL){
+      return bRC_BXATTR_inval;
+   }
+
+   /* search for attribute namespace which is distinguished from attribute name by a dot '.' character */
+   if ((name = strchr(xattr->name, '.')) == (char *)NULL){
+      Mmsg2(jcr->errmsg, _("Failed to split %s into namespace and name part on file \"%s\"\n"), xattr->name, jcr->last_fname);
+      Dmsg2(100, "Failed to split %s into namespace and name part on file \"%s\"\n", xattr->name, jcr->last_fname);
+      return bRC_BXATTR_error;
+   }
+
+   /* split namespace and name of the attribute */
+   nspace = xattr->name;
+   *name++ = '\0';
+
+   /* check if namespace is valid on this system */
+   if (extattr_string_to_namespace(nspace, &ns) != 0){
+      Mmsg2(jcr->errmsg, _("Failed to convert %s into namespace on file \"%s\"\n"), nspace, jcr->last_fname);
+      Dmsg2(100, "Failed to convert %s into namespace on file \"%s\"\n", nspace, jcr->last_fname);
+      return bRC_BXATTR_error;
+   }
+
+   /* set extattr on file */
+   rc = extattr_set_link(jcr->last_fname, ns, name, xattr->value, xattr->value_len);
+   if (rc < 0 || rc != (int)xattr->value_len){
+      berrno be;
+
+      switch (errno){
+      case ENOENT:
+         break;
+      default:
+         Mmsg2(jcr->errmsg, _("extattr_set_link error on file \"%s\": ERR=%s\n"), jcr->last_fname, be.bstrerror());
+         Dmsg2(100, "extattr_set_link error file=%s ERR=%s\n", jcr->last_fname, be.bstrerror());
+         return bRC_BXATTR_error;
+      }
+   }
+   return bRC_BXATTR_ok;
+};
+
+#endif /* HAVE_XATTR */
+
+#endif /* HAVE_NETBSD_OS */
