#! /bin/sh
#
#ident "@(#)$NetBSD: netsaint-setup.sh,v 1.3 2002/04/14 10:57:11 rh Exp $"
#
# Run this script as root to create these necessary runtime directories.
#
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/log/netsaint
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/log/netsaint/archives
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/run/netsaint
install -m 0775 -o @@USER@@ -g @@GROUP@@ -d /var/run/netsaint/rw
