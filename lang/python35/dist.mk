# $NetBSD: dist.mk,v 1.2 2015/12/07 14:36:26 adam Exp $

PY_DISTVERSION=	3.5.1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python35/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python35/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
