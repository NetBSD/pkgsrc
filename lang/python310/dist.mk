# $NetBSD: dist.mk,v 1.21 2026/03/04 07:03:17 adam Exp $

PY_DISTVERSION=	3.10.20
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
