$NetBSD: patch-contrib_completion_git-completion.zsh,v 1.1 2022/10/21 17:31:18 schmonz Exp $

Find pkgsrc-provided bash completion.

--- contrib/completion/git-completion.zsh.orig	2022-10-02 23:02:46.000000000 +0000
+++ contrib/completion/git-completion.zsh
@@ -30,7 +30,7 @@ if [ -z "$script" ]; then
 	local e bash_completion
 
 	bash_completion=$(pkg-config --variable=completionsdir bash-completion 2>/dev/null) ||
-		bash_completion='/usr/share/bash-completion/completions/'
+		bash_completion='@PREFIX@/share/bash-completion/completions/'
 
 	locations=(
 		"$(dirname ${funcsourcetrace[1]%:*})"/git-completion.bash
