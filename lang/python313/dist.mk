# $NetBSD: dist.mk,v 1.4 2025/04/09 14:51:00 adam Exp $

PY_DISTVERSION=	3.13.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python313/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python313/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
