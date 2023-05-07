## $NetBSD: Makefile.am,v 1.2 2023/05/07 19:13:27 wiz Exp $

ACLOCAL_AMFLAGS = -I buildaux

SUBDIRS = libnetbsd

if WITH_LOCAL_LIBEDIT
SUBDIRS += libedit
endif

SUBDIRS += src

EXTRA_DIST = \
	todo \
	tnftp.h
