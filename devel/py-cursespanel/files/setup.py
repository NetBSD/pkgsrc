# $NetBSD: setup.py,v 1.1.1.1 2003/06/04 19:32:13 drochner Exp $

import distutils
from distutils.core import setup, Extension

ncursesprefix = '@NCURSESPREFIX@'
ncincl = ncursesprefix + '/include'
nclib = ncursesprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'_curses_panel',
			['Modules/_curses_panel.c'],
			define_macros=[('HAVE_NCURSES_H', None)],
			include_dirs=[ncincl],
			library_dirs=[nclib],
			runtime_library_dirs=[nclib],
			libraries=['panel', 'ncurses']
		)
	]
)
