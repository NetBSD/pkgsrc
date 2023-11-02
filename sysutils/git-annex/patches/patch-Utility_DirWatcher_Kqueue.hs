$NetBSD: patch-Utility_DirWatcher_Kqueue.hs,v 1.1 2023/11/02 03:15:01 pho Exp $

Fix build with GHC 9.6.

--- Utility/DirWatcher/Kqueue.hs.orig	2023-11-02 02:54:22.254338562 +0000
+++ Utility/DirWatcher/Kqueue.hs
@@ -82,8 +82,8 @@ getDirInfo dir = do
 	return $ DirInfo dir contents
   where
 	getDirEnt f = catchMaybeIO $ do
-		s <- getSymbolicLinkStatus (dir </> f)
-		return $ DirEnt f (fileID s) (isDirectory s)
+		s <- Posix.getSymbolicLinkStatus (dir </> f)
+		return $ DirEnt f (Posix.fileID s) (Posix.isDirectory s)
 
 {- Difference between the dirCaches of two DirInfos. -}
 (//) :: DirInfo -> DirInfo -> [Change]
@@ -266,4 +266,4 @@ runHooks kq hooks = do
 		Just a -> a (changedFile change) s
 
 	withstatus change a = maybe noop (a change) =<<
-		(catchMaybeIO (getSymbolicLinkStatus (changedFile change)))
+		(catchMaybeIO (Posix.getSymbolicLinkStatus (changedFile change)))
