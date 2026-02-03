# $NetBSD: dist.mk,v 1.4 2026/02/03 20:30:46 adam Exp $

PY_DISTVERSION=	3.14.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python314/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python314/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
