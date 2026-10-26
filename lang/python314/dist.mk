# $NetBSD: dist.mk,v 1.11 2026/10/26 12:53:06 adam Exp $

PY_DISTVERSION=	3.14.10
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python314/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python314/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
