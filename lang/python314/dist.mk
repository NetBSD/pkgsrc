# $NetBSD: dist.mk,v 1.8 2026/08/05 15:56:03 adam Exp $

PY_DISTVERSION=	3.14.7
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python314/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python314/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
