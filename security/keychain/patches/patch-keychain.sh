$NetBSD: patch-keychain.sh,v 1.2 2025/11/03 16:37:52 vins Exp $

Handle an empty (or unset) SSH_ASKPASS variable.

--- keychain.sh.orig	2025-05-16 14:58:02.000000000 +0000
+++ keychain.sh
@@ -1040,6 +1040,7 @@ load_ssh_keys() {
 	IFS="$IFS_BAK"
 	[ $# -eq 0 ] && return
 	mesg "Adding ${CYANN}$#${OFF} ssh key(s): ${CYANN}$*${OFF}"
+	[ -z "${SSH_ASKPASS++}" ] && SSH_ASKPASS="##ASKPASS##"
 	if $noguiopt || [ -z "$SSH_ASKPASS" ] || [ -z "$DISPLAY" ]; then
 		unset DISPLAY		# DISPLAY="" can cause problems
 		unset SSH_ASKPASS	# make sure ssh-add doesn't try SSH_ASKPASS
