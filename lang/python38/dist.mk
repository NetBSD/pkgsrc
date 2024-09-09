# $NetBSD: dist.mk,v 1.21 2024/09/09 15:47:30 adam Exp $

PY_DISTVERSION=	3.8.20
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python38/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python38/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
