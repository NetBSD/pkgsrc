# $NetBSD: core.py,v 1.1 2022/07/16 08:59:39 rillig Exp $
#
# Fake implementation of distutils.core.
#
# https://docs.python.org/3/distutils/apiref.html#module-distutils.core

import url2pkg


# used by pkgsrc package devel/py-pysha3 1.0.2
def setup(**kwargs):
    url2pkg.setup(**kwargs)


# Originally from distutils.cmd.
# used by pkgsrc package devel/py-pysha3 1.0.2
class Command:
    pass
