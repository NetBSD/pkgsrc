# $NetBSD: dist.mk,v 1.10 2025/02/04 22:11:15 adam Exp $

PY_DISTVERSION=	3.12.9
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python312/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python312/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
