$NetBSD: patch-docs_unburden-home-dir.1.md,v 1.2 2017/02/09 10:37:12 hauke Exp $

Fix absolute paths, and normalize config file name

--- docs/unburden-home-dir.1.md.orig	2016-10-17 14:13:06.000000000 +0000
+++ docs/unburden-home-dir.1.md
@@ -67,20 +67,18 @@ EXAMPLES
 --------
 
 Example configuration files can be found at
-`/usr/share/doc/unburden-home-dir/examples/` on Debian-based systems
+`@PREFIX@/share/examples/unburden-home-dir/`
 and in the `etc/` directory of the source tar ball.
 
 FILES
 -----
 
-`/etc/unburden-home-dir`, `/etc/unburden-home-dir.list`,
-`~/.unburden-home-dir`, `~/.unburden-home-dir.list`,
+`@PKG_SYSCONFDIR@/unburden-home-dir.conf`, `@PKG_SYSCONFDIR@/unburden-home-dir.list`,
+`~/.unburden-home-dir.conf`, `~/.unburden-home-dir.list`,
 `~/.config/unburden-home-dir/config`,
-`~/.config/unburden-home-dir/list`, `/etc/default/unburden-home-dir`,
-`/etc/X11/Xsession.d/95unburden-home-dir`
+`~/.config/unburden-home-dir/list`
 
-Read the documentation at either
-`/usr/share/doc/unburden-home-dir/html/` on debianoid installations,
+Read the documentation at either `@PREFIX@/share/doc/unburden-home-dir/`,
 at https://unburden-home-dir.readthedocs.io/ online, or in the `docs/`
 directory in the source tar ball for an explanation of these files.
 
