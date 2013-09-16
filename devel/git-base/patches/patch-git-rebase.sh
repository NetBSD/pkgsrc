$NetBSD: patch-git-rebase.sh,v 1.1 2013/09/16 10:48:05 prlw1 Exp $

Rebase: fix run_specific_rebase's use of "return" on FreeBSD

Since a1549e1, git-rebase--am.sh uses the shell's "return" statement, to
mean "return from the current file inclusion", which is POSIXly correct,
but badly interpreted on FreeBSD, which returns from the current
function, hence skips the finish_rebase statement that follows the file
inclusion.

Make the use of "return" portable by using the file inclusion as the last
statement of a function.

https://github.com/git/git/commit/99855dd

--- git-rebase.sh.orig	2013-08-23 19:38:43.000000000 +0000
+++ git-rebase.sh
@@ -167,13 +167,22 @@ You can run "git stash pop" or "git stas
 	rm -rf "$state_dir"
 }
 
-run_specific_rebase () {
+run_specific_rebase_internal () {
 	if [ "$interactive_rebase" = implied ]; then
 		GIT_EDITOR=:
 		export GIT_EDITOR
 		autosquash=
 	fi
+	# On FreeBSD, the shell's "return" returns from the current
+	# function, not from the current file inclusion.
+	# run_specific_rebase_internal has the file inclusion as a
+	# last statement, so POSIX and FreeBSD's return will do the
+	# same thing. 
 	. git-rebase--$type
+}
+
+run_specific_rebase () {
+	run_specific_rebase_internal
 	ret=$?
 	if test $ret -eq 0
 	then
