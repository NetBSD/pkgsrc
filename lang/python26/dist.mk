# $NetBSD: dist.mk,v 1.3 2012/04/14 10:47:17 obache Exp $

PY_DISTVERSION=	2.6.8
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python26/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python26/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
