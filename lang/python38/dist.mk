# $NetBSD: dist.mk,v 1.15 2022/09/07 15:32:34 adam Exp $

PY_DISTVERSION=	3.8.14
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python38/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python38/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
