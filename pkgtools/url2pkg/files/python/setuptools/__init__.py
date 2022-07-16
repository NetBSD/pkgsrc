# $NetBSD: __init__.py,v 1.1 2022/07/16 08:59:39 rillig Exp $
#
# This is a drop-in replacement for the setuptools Python module. Instead
# of actually searching for the dependencies, it extracts the dependency
# information and includes it in the generated pkgsrc package Makefile.
#
# https://setuptools.pypa.io/en/latest/index.html
# https://setuptools.pypa.io/en/latest/setuptools.html
# https://setuptools.pypa.io/en/latest/userguide/index.html
# https://github.com/pypa/setuptools/tree/main/setuptools

import url2pkg
# used by pkgsrc package wip/py-torch 1.12.0
import distutils  # only re-export
from setuptools.dist import Distribution


# used by pkgsrc package devel/py-pysha3 1.0.2
# used by pkgsrc package wip/py-torch 1.12.0
def setup(**kwargs):
    url2pkg.setup(**kwargs)


# used by pkgsrc package wip/py-torch 1.12.0
def find_packages(where='.', exclude=(), include=('*',)):
    return []


# used by pkgsrc package devel/py-pysha3 1.0.2
# used by pkgsrc package wip/py-torch 1.12.0
class Extension:
    def __init__(self, name, sources, *args, **kw) -> None:
        pass
