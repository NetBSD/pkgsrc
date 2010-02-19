# $NetBSD: setup.py,v 1.2 2010/02/19 17:15:11 joerg Exp $

from distutils.core import setup, Extension

sqlite_prefix = '@SQLITE_PREFIX@'
sqlite_incdir = sqlite_prefix + '/include'
sqlite_libdir = sqlite_prefix + '/lib'

sqlite_defines = [('MODULE_NAME', '"sqlite3"')]

sqlite_srcs = ['_sqlite/cache.c',
               '_sqlite/connection.c',
               '_sqlite/cursor.c',
               '_sqlite/microprotocols.c',
               '_sqlite/module.c',
               '_sqlite/prepare_protocol.c',
               '_sqlite/row.c',
               '_sqlite/statement.c',
               '_sqlite/util.c', ]
sqlite_srcs = ['Modules/' + x for x in sqlite_srcs]

setup(
    ext_modules = [
        Extension('_sqlite3',
                  sqlite_srcs,
                  define_macros=sqlite_defines,
                  include_dirs=["Modules/_sqlite",
                                sqlite_incdir],
                  library_dirs=[sqlite_libdir],
                  runtime_library_dirs=[sqlite_libdir],
                  libraries=["sqlite3"]),
        ]
)
