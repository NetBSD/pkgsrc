# $NetBSD: extension.py,v 1.2 2022/08/25 19:56:07 rillig Exp $
#
# Fake implementation of distutils.extension
#
# https://docs.python.org/3/distutils/apiref.html#module-distutils.extension

# used by pkgsrc package devel/py-pysha3 1.0.2
class Extension:
    def __init__(self, *args, **kwargs):
        pass
