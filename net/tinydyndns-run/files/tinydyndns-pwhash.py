#!/usr/bin/env python
#
# $NetBSD: tinydyndns-pwhash.py,v 1.2 2020/10/19 07:15:55 schmonz Exp $
#
# @PKGNAME@ program to crypt() a password.

import crypt, sys

print(crypt.crypt(sys.stdin.read().rstrip()))
