$NetBSD: patch-github_editor.go,v 1.1 2018/06/10 10:42:56 leot Exp $

Avoid vim-isms.

vi(1) is not always vim, avoid to treat it as such and to pass to
it possible not supported arguments.

--- github/editor.go.orig	2018-05-29 13:34:37.000000000 +0000
+++ github/editor.go
@@ -129,7 +129,7 @@ func (e *Editor) readContent() (content 
 
 func openTextEditor(program, file string) error {
 	editCmd := cmd.New(program)
-	r := regexp.MustCompile(`\b(?:[gm]?vim|vi)(?:\.exe)?$`)
+	r := regexp.MustCompile(`\b(?:[gm]?vim)(?:\.exe)?$`)
 	if r.MatchString(editCmd.Name) {
 		editCmd.WithArg("--cmd")
 		editCmd.WithArg("set ft=gitcommit tw=0 wrap lbr")
