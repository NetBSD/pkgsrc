# $NetBSD: setup.py,v 1.1 2002/03/14 17:58:50 wiz Exp $

import distutils
from distutils.core import setup, Extension

rlprefix = '@RLPREFIX@'
rlincl = rlprefix + '/include'
rllib = rlprefix + '/lib'
rlrtprefix = '@RLRTPREFIX@'
rlrtlib = rlrtprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'readline',
			['Modules/readline.c'],
			include_dirs=[rlincl],
			library_dirs=[rllib],
			runtime_library_dirs=[rlrtlib],
			libraries=['readline', 'termcap']
		)
	]
)
