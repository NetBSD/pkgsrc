# $NetBSD: dist.mk,v 1.2 2012/04/14 11:22:07 obache Exp $

PY_DISTVERSION=	3.1.5
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python31/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python31/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
