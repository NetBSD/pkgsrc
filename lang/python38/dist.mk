# $NetBSD: dist.mk,v 1.18 2023/06/07 13:25:08 adam Exp $

PY_DISTVERSION=	3.8.17
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python38/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python38/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
