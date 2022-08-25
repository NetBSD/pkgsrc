# $NetBSD: test.py,v 1.1 2022/08/25 19:51:59 rillig Exp $
#
# Fake implementation of setuptools.command.test.
#
# https://github.com/pypa/setuptools/blob/main/setuptools/command/test.py

# used by pkgsrc package www/py-pook 1.0.2

from setuptools import Command


class test(Command):
    pass
