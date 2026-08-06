# $NetBSD: dist.mk,v 1.16 2026/08/06 08:14:27 adam Exp $

PY_DISTVERSION=	3.13.15
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python313/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python313/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
