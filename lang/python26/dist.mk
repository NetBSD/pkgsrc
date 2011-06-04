# $NetBSD: dist.mk,v 1.2 2011/06/04 03:58:58 obache Exp $

PY_DISTVERSION=	2.6.7
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python26/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python26/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
