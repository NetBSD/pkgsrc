# $NetBSD: dist.mk,v 1.2 2011/06/04 05:08:19 obache Exp $

PY_DISTVERSION=	2.5.6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python25/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python25/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
