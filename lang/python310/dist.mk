# $NetBSD: dist.mk,v 1.22 2026/08/13 12:25:38 adam Exp $

PY_DISTVERSION=	3.10.21
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
