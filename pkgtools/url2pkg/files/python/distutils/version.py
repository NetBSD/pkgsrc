# $NetBSD: version.py,v 1.3 2022/08/26 20:14:58 rillig Exp $
#
# Fake implementation of distutils.version.
#
# https://docs.python.org/3/distutils/apiref.html#module-distutils.version

# indirectly used by pkgsrc package wip/py-torch 1.12.0
class Version:
    def __init__(self, vstring=None):
        pass


# just for completeness
class StrictVersion(Version):
    pass


# used by pkgsrc package wip/py-torch 1.12.0
class LooseVersion(Version):
    def __init__(self, vstring=None):
        super().__init__(vstring)
