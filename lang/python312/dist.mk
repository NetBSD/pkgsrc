# $NetBSD: dist.mk,v 1.13 2025/10/10 11:53:08 adam Exp $

PY_DISTVERSION=	3.12.12
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python312/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python312/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
