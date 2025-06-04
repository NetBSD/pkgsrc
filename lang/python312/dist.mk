# $NetBSD: dist.mk,v 1.12 2025/06/04 14:14:53 adam Exp $

PY_DISTVERSION=	3.12.11
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python312/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python312/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
