$NetBSD: patch-squirrel-sql.sh,v 1.1.1.1 2015/07/19 20:26:18 asau Exp $

--- squirrel-sql.sh.orig	2014-10-12 16:43:18.000000000 +0000
+++ squirrel-sql.sh
@@ -33,11 +33,7 @@ esac
 # the script cannot be modified by the installer to hard-code the install path.  We prefer to specify squirrel
 # home as an absolute path, so that the command will work when exec'd from any location. So we attempt to 
 # detect the absolute path using dirname "$0", which should work in most cases.  
-if $macosx ; then
-        SQUIRREL_SQL_HOME=`dirname "$0"`/Contents/Resources/Java
-else 
-        SQUIRREL_SQL_HOME=`dirname "$0"`
-fi
+SQUIRREL_SQL_HOME=@SQUIRREL_SQL_HOME@
 
 # SQuirreL home in Unix format.
 if $cygwin ; then
