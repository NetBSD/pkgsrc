$NetBSD: patch-tools_ci-run-docker-image.sh,v 1.1 2026/09/06 11:02:45 markd Exp $

fix "test =="

--- tools/ci-run-docker-image.sh.orig	2026-08-14 03:31:40.000000000 +0000
+++ tools/ci-run-docker-image.sh
@@ -44,7 +44,7 @@ EOF
 
 options=
 shopts="export ci_parallel=$ci_parallel; export ci_distro=$ci_distro; export ci_variant=$ci_variant;"
-if [ "$1" == "--use-host-display" ]; then
+if [ "$1" = "--use-host-display" ]; then
     options="-v $HOME/.Xauthority:/root/.Xauthority:rw --env=DISPLAY --net=host"
     shopts+=" export DISPLAY=$DISPLAY;"
 fi
