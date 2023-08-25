# $NetBSD: dist.mk,v 1.19 2023/08/25 08:25:28 adam Exp $

PY_DISTVERSION=	3.8.18
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python38/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python38/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
