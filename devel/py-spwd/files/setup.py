# $NetBSD: setup.py,v 1.1 2014/02/13 16:10:50 jperkin Exp $

import distutils
from distutils.core import setup, Extension

setup(
	ext_modules = [
		Extension(
			'spwd',
			['Modules/spwdmodule.c']
		)
	]
)
