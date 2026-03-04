# $NetBSD: dist.mk,v 1.16 2026/03/04 06:51:45 adam Exp $

PY_DISTVERSION=	3.11.15
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
