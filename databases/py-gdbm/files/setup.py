# $NetBSD: setup.py,v 1.2 2011/11/03 12:21:41 obache Exp $

import distutils
from distutils.core import setup, Extension

gdbmprefix = '@GDBMPREFIX@'
gdbmincl = gdbmprefix + '/include'
gdbmlib = gdbmprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'@GDBM_MODNAME@',
			['Modules/@GDBM_MODNAME@module.c'],
			include_dirs=[gdbmincl],
			library_dirs=[gdbmlib],
			runtime_library_dirs=[gdbmlib],
			libraries=['gdbm']
		)
	]
)
