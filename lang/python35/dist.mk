# $NetBSD: dist.mk,v 1.8 2019/03/20 19:27:47 adam Exp $

PY_DISTVERSION=	3.5.7
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python35/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python35/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
