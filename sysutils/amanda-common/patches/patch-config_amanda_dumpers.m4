$NetBSD: patch-config_amanda_dumpers.m4,v 1.2 2018/11/23 22:33:13 spz Exp $

* Add '--with-dump-use-snapshot' code.

--- config/amanda/dumpers.m4.orig	2012-02-21 11:36:49.000000000 +0000
+++ config/amanda/dumpers.m4
@@ -484,6 +484,44 @@ AC_DEFUN([AMANDA_PROG_DUMP_RESTORE],
 		    [Define this if dump accepts -h for honoring nodump. ])
 	    fi
 	])
+	AC_ARG_WITH(dump-use-snapshot,
+	[  --with-dump-use-snapshot  if dump supports -X, use it],
+	[ if test -x $DUMP; then
+	    AC_CACHE_CHECK(
+	    [whether $DUMP supports -X (use filesystem snapshot)],
+	    amanda_cv_use_snapshot,
+	    [ case "$DUMP" in
+	    *dump)
+		AC_TRY_COMMAND($DUMP 9Xf /dev/null /dev/null/invalid/fs 2>&1
+		    | $GREP -v Dumping
+		    | $GREP -v Date
+		    | $GREP -v Label >conftest.d-x 2>&1)
+		cat conftest.d-x >&AS_MESSAGE_LOG_FD()
+		AC_TRY_COMMAND($DUMP 9f /dev/null /dev/null/invalid/fs 2>&1
+		    | $GREP -v Dumping
+		    | $GREP -v Date
+		    | $GREP -v Label >conftest.d 2>&1)
+		cat conftest.d >&AS_MESSAGE_LOG_FD()
+		if AC_TRY_COMMAND(diff conftest.d-x conftest.d 1>&2); then
+		    amanda_cv_use_snapshot=yes
+		else
+		    amanda_cv_use_snapshot=no
+		fi
+		rm -f conftest.d conftest.d-x
+		;;
+	    *) amanda_cv_use_snapshot=no
+		;;
+	    esac
+	    ])
+	else
+	    AC_MSG_WARN([*** $DUMP is not executable, cannot run -X test])
+	    amanda_cv_use_snapshot=no
+	fi
+	if test "$amanda_cv_use_snapshot" = yes; then
+	  AC_DEFINE(HAVE_DUMP_SNAPSHOT,1,[Define this if dump accepts -X for using snapshots. ])
+	fi
+	])
+
     fi
 
     AC_SUBST(AIX_BACKUP)
