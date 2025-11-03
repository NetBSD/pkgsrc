$NetBSD: patch-src_cmd_ksh93_SHOPT.sh,v 1.1 2025/11/03 21:47:14 vins Exp $

Enable sourcing of system-wide configuration.

--- src/cmd/ksh93/SHOPT.sh.orig	2024-08-01 22:54:10.000000000 +0000
+++ src/cmd/ksh93/SHOPT.sh
@@ -37,7 +37,7 @@ SHOPT REMOTE=				# enable --rc if runnin
 SHOPT SCRIPTONLY=0			# build ksh for running scripts only; compile out the interactive shell
 SHOPT SPAWN=				# use spawnveg for fork/exec
 SHOPT STATS=1				# add .sh.stats variable
-SHOPT SYSRC=				# attempt . /etc/ksh.kshrc if interactive
+SHOPT SYSRC=1				# attempt . /etc/ksh.kshrc if interactive
 SHOPT TEST_L=				# add 'test -l' as an alias for 'test -L'
 SHOPT TIMEOUT=				# number of seconds for shell timeout
 SHOPT VSH=1				# vi edit mode
