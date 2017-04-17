$NetBSD: patch-auto__uids.c,v 1.1.2.1 2017/04/17 16:08:22 bsiegert Exp $

Look up user/group IDs at runtime. Based on Paul Fox's getpwnam.patch.

--- auto_uids.c.orig	2017-04-04 06:28:23.000000000 +0000
+++ auto_uids.c
@@ -0,0 +1,52 @@
+#include <pwd.h>
+#include <grp.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include "auto_uids.h"
+
+struct group *getgrnam();
+struct passwd *getpwnam();
+
+static int ids[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
+
+static int
+name2uid(name)
+char *name;
+{
+  struct passwd *pw;
+  pw = getpwnam(name);
+  if (!pw) _exit(113);
+  return (int)(pw->pw_uid);
+}
+
+static int
+name2gid(name)
+char *name;
+{
+  struct group *gr;
+  gr = getgrnam(name);
+  if (!gr) _exit(113);
+  return (int)(gr->gr_gid);
+}
+
+int
+qm_id(id)
+int id;
+{
+  if (ids[id] >= 0) return ids[id];
+
+  switch(id) {
+  case ID_OWNER:   ids[id] = name2uid("@QMAIL_ROOT_USER@"); break;
+  case ID_ALIAS:   ids[id] = name2uid("@QMAIL_ALIAS_USER@"); break;
+  case ID_DAEMON:  ids[id] = name2uid("@QMAIL_DAEMON_USER@"); break;
+  case ID_LOG:     ids[id] = name2uid("@QMAIL_LOG_USER@"); break;
+  case ID_PASSWD:  ids[id] = name2uid("@QMAIL_PASSWD_USER@"); break;
+  case ID_QUEUE:   ids[id] = name2uid("@QMAIL_QUEUE_USER@"); break;
+  case ID_REMOTE:  ids[id] = name2uid("@QMAIL_REMOTE_USER@"); break;
+  case ID_SEND:    ids[id] = name2uid("@QMAIL_SEND_USER@"); break;
+  case ID_QMAIL:   ids[id] = name2gid("@QMAIL_QMAIL_GROUP@"); break;
+  case ID_NOFILES: ids[id] = name2gid("@QMAIL_NOFILES_GROUP@"); break;
+  default: _exit(113);
+  }
+  return ids[id];
+}
