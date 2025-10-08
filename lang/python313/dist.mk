# $NetBSD: dist.mk,v 1.9 2025/10/08 05:55:24 adam Exp $

PY_DISTVERSION=	3.13.8
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python313/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python313/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
