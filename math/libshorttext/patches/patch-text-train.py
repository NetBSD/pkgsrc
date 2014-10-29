$NetBSD: patch-text-train.py,v 1.1.1.1 2014/10/29 17:06:40 cheusov Exp $

# differnt executables are provided by libsvm and liblinear packages
--- text-train.py.orig	2013-09-09 08:53:54.000000000 +0000
+++ text-train.py
@@ -150,9 +150,9 @@ if __name__ == '__main__':
 			extra_svm_files += [value]
 		elif argv[i] == '-x':
 			if value.lower() == 'grid':
-				system(path.dirname(LIBLINEAR_HOME) + '/../grid.py')
+				system('svm-grid')
 			elif value.lower() == 'liblinear':
-				system(LIBLINEAR_HOME + '/train')
+				system('liblinear-train')
 			else:
 				stderr.write('Error: Invalid usage of option -x. No command ' + value + '\n')
 				exit_with_help()
