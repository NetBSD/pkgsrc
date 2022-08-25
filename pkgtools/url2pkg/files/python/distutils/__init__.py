# $NetBSD: __init__.py,v 1.2 2022/08/25 19:56:07 rillig Exp $
#
# This is a drop-in replacement for the distutils Python module. Instead
# of actually searching for the dependencies, it extracts the dependency
# information and includes it in the generated pkgsrc package Makefile.
#
# https://docs.python.org/3/distutils/
# As of Python 3.10, distutils is deprecated.
# The successor is setuptools.
