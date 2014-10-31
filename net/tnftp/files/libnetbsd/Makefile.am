## $NetBSD: Makefile.am,v 1.1.1.1 2014/10/31 18:47:20 spz Exp $

noinst_LTLIBRARIES = libnetbsd.la

libnetbsd_la_SOURCES =


CPPFLAGS = \
	-I$(srcdir) \
	-I$(top_srcdir) \
	-I$(top_builddir)

libnetbsd_la_LIBADD = $(LTLIBOBJS)

EXTRA_DIST = \
	fseeko.c \
	ftpglob.h \
	ftpvis.h
