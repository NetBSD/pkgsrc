$NetBSD: patch-simmain.cc,v 1.1 2019/10/26 11:27:10 nia Exp $

Search for data files in pkgsrc path.

--- simmain.cc.orig	2018-09-10 08:16:26.000000000 +0000
+++ simmain.cc
@@ -493,8 +493,8 @@ int simu_main(int argc, char** argv)
 		strcat( env_t::program_dir, PATH_SEPARATOR );
 	}
 	else {
-		strcpy( env_t::program_dir, argv[0] );
-		*(strrchr( env_t::program_dir, PATH_SEPARATOR[0] )+1) = 0;
+		const char data_dir[] = "@PREFIX@/share/simutrans/";
+		memcpy(env_t::program_dir, data_dir, sizeof(data_dir));
 
 #ifdef __APPLE__
 		// change working directory from binary dir to bundle dir
