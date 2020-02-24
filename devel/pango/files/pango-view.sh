#!/bin/sh
# $NetBSD: pango-view.sh,v 1.1 2020/02/24 17:08:31 brook Exp $
#
# Run pango-view with LD_LIBRARY_PATH
#
# During the build process, help2man is used to create a man page for
# pango-view, which it does by running pango-view.  On some platforms
# (notably Darwin) this fails because pango-view requires access to a
# shared library just built and rpath is not set appropriately.
# Therefore, LD_LIBRARY_PATH must be set, which cannot be done in
# meson.build, because help2man does not propagate the environment to
# programs it runs.  The solution is to wrap pango-view in this script
# and provide LD_LIBRARY_PATH here.
#

env LD_LIBRARY_PATH=@WRKSRC@/output/pango @WRKSRC@/output/utils/pango-view ${*}
