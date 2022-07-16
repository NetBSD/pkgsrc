# $NetBSD: __init__.py,v 1.1 2022/07/16 08:59:39 rillig Exp $
#
# This is a drop-in replacement for the distutils Python module. Instead
# of actually searching for the dependencies, it extracts the dependency
# information and includes it in the generated pkgsrc package Makefile.
#
# https://docs.python.org/3/distutils/
# As of Python 3.10, distutils is deprecated.
# The successor is setuptools.
