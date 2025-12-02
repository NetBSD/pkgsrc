# $NetBSD: dist.mk,v 1.2 2025/12/02 21:34:37 adam Exp $

PY_DISTVERSION=	3.14.1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python314/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python314/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
