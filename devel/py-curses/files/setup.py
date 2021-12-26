# $NetBSD: setup.py,v 1.2 2021/12/26 19:57:05 nros Exp $

import distutils
import os
from distutils.core import setup, Extension
from distutils.sysconfig import get_python_inc

ncursesprefix = '@NCURSESPREFIX@'
ncincl = ncursesprefix + '/include'
nclib = ncursesprefix + '/lib'
py_inc_int = os.path.join(get_python_inc(), 'internal')

setup(
	ext_modules = [
		Extension(
			'_curses',
			['Modules/_cursesmodule.c'],
			define_macros=[('HAVE_NCURSES_H', None), ('Py_BUILD_CORE_MODULE', None)],
			include_dirs=[ncincl, py_inc_int],
			library_dirs=[nclib],
			runtime_library_dirs=[nclib],
			libraries=['ncurses']
		)
	]
)
