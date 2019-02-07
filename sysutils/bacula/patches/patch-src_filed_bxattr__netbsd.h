$NetBSD: patch-src_filed_bxattr__netbsd.h,v 1.1 2019/02/07 11:29:31 markd Exp $

NetBSD has xattr.

--- /dev/null	2019-02-04 11:33:03.884708092 +0000
+++ src/filed/bxattr_netbsd.h
@@ -0,0 +1,85 @@
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
+#ifndef __BXATTR_NetBSD_H_
+#define __BXATTR_NetBSD_H_
+
+#if defined(HAVE_NETBSD_OS)
+#include <sys/types.h>
+
+/* check if XATTR support is enabled */
+#if defined(HAVE_XATTR)
+
+#if (!defined(HAVE_EXTATTR_GET_LINK) && !defined(HAVE_EXTATTR_GET_FILE)) || \
+    (!defined(HAVE_EXTATTR_SET_LINK) && !defined(HAVE_EXTATTR_SET_FILE)) || \
+    (!defined(HAVE_EXTATTR_LIST_LINK) && !defined(HAVE_EXTATTR_LIST_FILE)) || \
+    !defined(HAVE_EXTATTR_NAMESPACE_TO_STRING) || \
+    !defined(HAVE_EXTATTR_STRING_TO_NAMESPACE)
+#error "Missing full support for the extattr functions."
+#endif
+
+#ifdef HAVE_SYS_EXTATTR_H
+#include <sys/types.h>
+#include <sys/extattr.h>
+#else
+#error "Missing sys/extattr.h header file"
+#endif
+
+#ifdef HAVE_LIBUTIL_H
+#include <libutil.h>
+#endif
+
+#if !defined(HAVE_EXTATTR_GET_LINK) && defined(HAVE_EXTATTR_GET_FILE)
+#define extattr_get_link extattr_get_file
+#endif
+#if !defined(HAVE_EXTATTR_SET_LINK) && defined(HAVE_EXTATTR_SET_FILE)
+#define extattr_set_link extattr_set_file
+#endif
+#if !defined(HAVE_EXTATTR_LIST_LINK) && defined(HAVE_EXTATTR_LIST_FILE)
+#define extattr_list_link extattr_list_file
+#endif
+
+/*
+ *
+ *
+ */
+class BXATTR_NetBSD : public BXATTR {
+private:
+   bRC_BXATTR os_backup_xattr (JCR *jcr, FF_PKT *ff_pkt);
+   bRC_BXATTR os_restore_xattr (JCR *jcr, int stream, char *content, uint32_t length);
+   bRC_BXATTR os_get_xattr_names_local (JCR *jcr, const int ns, POOLMEM **list, uint32_t *length);
+   bRC_BXATTR os_get_xattr_value_local (JCR *jcr, const int ns, char * name, char ** pvalue, uint32_t * plen);
+   bRC_BXATTR os_set_xattr (JCR *jcr, BXATTR_xattr *xattr);
+public:
+   BXATTR_NetBSD ();
+};
+
+#endif /* HAVE_XATTR */
+
+#endif /* HAVE_NETBSD_OS */
+
+#endif /* __BXATTR_NetBSD_H_ */
