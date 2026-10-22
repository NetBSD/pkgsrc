# $NetBSD: dist.mk,v 1.10 2026/10/22 08:01:58 adam Exp $

PY_DISTVERSION=	3.14.9
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python314/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python314/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
