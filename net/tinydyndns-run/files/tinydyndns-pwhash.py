#!/usr/bin/env python

import crypt, sys

print(crypt.crypt(sys.stdin.read().rstrip()))
