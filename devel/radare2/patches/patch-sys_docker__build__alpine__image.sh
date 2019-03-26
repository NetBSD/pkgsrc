$NetBSD: patch-sys_docker__build__alpine__image.sh,v 1.1 2019/03/26 19:30:35 ryoon Exp $

* POSIX shell portability

--- sys/docker_build_alpine_image.sh.orig	2019-02-19 12:35:24.000000000 +0000
+++ sys/docker_build_alpine_image.sh
@@ -184,7 +184,7 @@ RUN set -o pipefail && \
 			echo "alias q=\"exit\"" >>/root/.bashrc \
 		) \
 	) && ( \
-		[ "$gname" == "root" ] || \
+		[ "$gname" = "root" ] || \
 		( \
 			groupadd -f $gname && \
 			(groupmod -g $gid $gname 2>/dev/null || true) && \
