$NetBSD: patch-main.go,v 1.5 2024/02/19 21:04:39 schmonz Exp $

Avoid CONFLICTS with other redo implementations.

--- main.go.orig	2024-02-19 17:57:37.000000000 +0000
+++ main.go
@@ -39,23 +39,22 @@ import (
 )
 
 const (
-	CmdNameGoredo       = "goredo"
-	CmdNameRedo         = "redo"
-	CmdNameRedoAffects  = "redo-affects"
-	CmdNameRedoAlways   = "redo-always"
-	CmdNameRedoCleanup  = "redo-cleanup"
-	CmdNameRedoDep2Rec  = "redo-dep2rec"
-	CmdNameRedoDepFix   = "redo-depfix"
-	CmdNameRedoDot      = "redo-dot"
-	CmdNameRedoIfchange = "redo-ifchange"
-	CmdNameRedoIfcreate = "redo-ifcreate"
-	CmdNameRedoInode    = "redo-inode"
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
+	CmdNameRedoDep2Rec  = "goredo-dep2rec"
+	CmdNameRedoDepFix   = "goredo-depfix"
+	CmdNameRedoDot      = "goredo-dot"
+	CmdNameRedoIfchange = "goredo-ifchange"
+	CmdNameRedoIfcreate = "goredo-ifcreate"
+	CmdNameRedoInode    = "goredo-inode"
+	CmdNameRedoLog      = "goredo-log"
+	CmdNameRedoOOD      = "goredo-ood"
+	CmdNameRedoSources  = "goredo-sources"
+	CmdNameRedoStamp    = "goredo-stamp"
+	CmdNameRedoTargets  = "goredo-targets"
+	CmdNameRedoWhichdo  = "goredo-whichdo"
 )
 
 var (
@@ -84,7 +83,7 @@ func mustParseFd(v, name string) *os.Fil
 }
 
 func CmdName() string {
-	return path.Base(os.Args[0])
+	return path.Base(CmdNameRedo)
 }
 
 func main() {
@@ -93,11 +92,11 @@ func main() {
 
 	var symlinks *bool
 	cmdName := CmdName()
-	if cmdName == CmdNameGoredo {
+	if cmdName == CmdNameRedo {
 		symlinks = flag.Bool("symlinks", false, "create necessary symlinks in current directory")
 	}
 
-	flag.Usage = func() { usage(os.Args[0]) }
+	flag.Usage = func() { usage(CmdNameRedo) }
 
 	BuildUUIDStr := os.Getenv(EnvBuildUUID)
 	IsTopRedo = BuildUUIDStr == ""
@@ -118,10 +117,9 @@ func main() {
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
@@ -138,8 +136,8 @@ func main() {
 			CmdNameRedoTargets,
 			CmdNameRedoWhichdo,
 		} {
-			fmt.Println(os.Args[0], "<-", cmdName)
-			if err := os.Symlink(os.Args[0], cmdName); err != nil {
+			fmt.Println(CmdNameRedo, "<-", cmdName)
+			if err := os.Symlink(CmdNameRedo, cmdName); err != nil {
 				rc = 1
 				log.Print(err)
 			}
