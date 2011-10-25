$NetBSD: patch-lib9_dirread.c,v 1.1 2011/10/25 16:28:17 ryoon Exp $

* DragonFly support

--- lib9/dirread.c.orig	2010-06-04 10:46:05.000000000 +0000
+++ lib9/dirread.c
@@ -25,7 +25,7 @@ mygetdents(int fd, struct dirent *buf, i
 	long off;
 	return getdirentries(fd, (void*)buf, n, &off);
 }
-#elif defined(__sun__) || defined(__NetBSD__)
+#elif defined(__sun__) || defined(__NetBSD__) || defined(__DragonFly__)
 static int
 mygetdents(int fd, struct dirent *buf, int n)
 {
@@ -50,14 +50,22 @@ countde(char *p, int n)
 	m = 0;
 	while(p < e){
 		de = (struct dirent*)p;
+#if defined(__DragonFly__)
+		if (p + _DIRENT_DIRSIZ(de) > e)
+#else
 		if(de->d_reclen <= 4+2+2+1 || p+de->d_reclen > e)
+#endif
 			break;
 		if(de->d_name[0]=='.' && de->d_name[1]==0)
 			de->d_name[0] = 0;
 		else if(de->d_name[0]=='.' && de->d_name[1]=='.' && de->d_name[2]==0)
 			de->d_name[0] = 0;
 		m++;
+#if defined(__DragonFly__)
+		p += _DIRENT_DIRSIZ(de);
+#else
 		p += de->d_reclen;
+#endif
 	}
 	return m;
 }
@@ -97,7 +105,11 @@ dirpackage(int fd, char *buf, int n, Dir
 				stat(de->d_name, &st);
 			nstr += _p9dir(&lst, &st, de->d_name, nil, nil, nil);
 		}
+#if defined(__DragonFly__)
+		p += _DIRENT_DIRSIZ(de);
+#else
 		p += de->d_reclen;
+#endif
 	}
 
 	d = malloc(sizeof(Dir)*n+nstr);
@@ -119,7 +131,11 @@ dirpackage(int fd, char *buf, int n, Dir
 				stat(de->d_name, &st);
 			_p9dir(&lst, &st, de->d_name, &d[m++], &str, estr);
 		}
+#if defined(__DragonFly__)
+		p += _DIRENT_DIRSIZ(de);
+#else
 		p += de->d_reclen;
+#endif
 	}
 
 	fchdir(oldwd);
