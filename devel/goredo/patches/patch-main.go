$NetBSD: patch-main.go,v 1.1 2022/01/06 11:25:25 schmonz Exp $

Avoid CONFLICTS with other redo implementations.

--- main.go.orig	2021-11-20 14:43:11.000000000 +0000
+++ main.go
@@ -41,20 +41,19 @@ import (
 )
 
 const (
-	CmdNameGoredo       = "goredo"
-	CmdNameRedo         = "redo"
-	CmdNameRedoAffects  = "redo-affects"
-	CmdNameRedoAlways   = "redo-always"
-	CmdNameRedoCleanup  = "redo-cleanup"
-	CmdNameRedoDot      = "redo-dot"
-	CmdNameRedoIfchange = "redo-ifchange"
-	CmdNameRedoIfcreate = "redo-ifcreate"
-	CmdNameRedoLog      = "redo-log"
-	CmdNameRedoOOD      = "redo-ood"
-	CmdNameRedoSources  = "redo-sources"
-	CmdNameRedoStamp    = "redo-stamp"
-	CmdNameRedoTargets  = "redo-targets"
-	CmdNameRedoWhichdo  = "redo-whichdo"
+	CmdNameRedo         = "goredo"
+	CmdNameRedoAffects  = "goredo-affects"
+	CmdNameRedoAlways   = "goredo-always"
+	CmdNameRedoCleanup  = "goredo-cleanup"
+	CmdNameRedoDot      = "goredo-dot"
+	CmdNameRedoIfchange = "goredo-ifchange"
+	CmdNameRedoIfcreate = "goredo-ifcreate"
+	CmdNameRedoLog      = "goredo-log"
+	CmdNameRedoOOD      = "goredo-ood"
+	CmdNameRedoSources  = "goredo-sources"
+	CmdNameRedoStamp    = "goredo-stamp"
+	CmdNameRedoTargets  = "goredo-targets"
+	CmdNameRedoWhichdo  = "goredo-whichdo"
 )
 
 var (
@@ -105,10 +104,9 @@ func main() {
 		fmt.Println("goredo", Version, "built with", runtime.Version())
 		return
 	}
-	if cmdName == CmdNameGoredo && *symlinks {
+	if cmdName == CmdNameRedo && *symlinks {
 		rc := 0
 		for _, cmdName := range []string{
-			CmdNameRedo,
 			CmdNameRedoAffects,
 			CmdNameRedoAlways,
 			CmdNameRedoCleanup,
@@ -122,8 +120,8 @@ func main() {
 			CmdNameRedoTargets,
 			CmdNameRedoWhichdo,
 		} {
-			fmt.Println(os.Args[0], "<-", cmdName)
-			if err := os.Symlink(os.Args[0], cmdName); err != nil {
+			fmt.Println(CmdNameRedo, "<-", cmdName)
+			if err := os.Symlink(CmdNameRedo, cmdName); err != nil {
 				rc = 1
 				log.Println(err)
 			}
