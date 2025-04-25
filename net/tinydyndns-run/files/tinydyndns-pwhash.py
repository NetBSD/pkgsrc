#!/usr/bin/env python
#
# $NetBSD: tinydyndns-pwhash.py,v 1.3 2025/04/25 20:41:11 schmonz Exp $
#
# @PKGNAME@ program to bcrypt a password.

from passlib.context import CryptContext
import sys

print(CryptContext(schemes=["bcrypt"]).hash(sys.stdin.read().rstrip()))
