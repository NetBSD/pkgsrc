## $NetBSD: Makefile.am,v 1.2 2023/05/07 19:13:28 wiz Exp $

noinst_LTLIBRARIES = libnetbsd.la

libnetbsd_la_SOURCES = libnetbsd.c

AM_CPPFLAGS = \
	-I$(srcdir) \
	-I$(top_srcdir) \
	-I$(top_builddir)

libnetbsd_la_LIBADD = $(LTLIBOBJS)

EXTRA_DIST = \
	fseeko.c \
	ftpglob.h \
	ftpvis.h
