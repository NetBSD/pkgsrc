#!/bin/sh
#
#       $NetBSD: netsaint-setup.sh,v 1.2 2002/03/25 12:54:18 rh Exp $
#
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/log/netsaint
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/log/netsaint/archives
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/run/netsaint
install -m 0775 -o @@USER@@ -g @@GROUP@@ -d /var/run/netsaint/rw
