# $NetBSD: dist.mk,v 1.3 2013/11/21 14:06:43 adam Exp $

PY_DISTVERSION=	3.3.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python33/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python33/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
