# $NetBSD: errors.py,v 1.1 2022/08/25 20:10:42 rillig Exp $
#
# Fake implementation of distutils.errors.
#
# https://docs.python.org/3/distutils/apiref.html#module-distutils.errors

# used by pkgsrc package geography/py-maxminddb 2.2.0
class CCompilerError(Exception):
    pass


# used by pkgsrc package geography/py-maxminddb 2.2.0
class DistutilsExecError(Exception):
    pass


# used by pkgsrc package geography/py-maxminddb 2.2.0
class DistutilsPlatformError(Exception):
    pass
