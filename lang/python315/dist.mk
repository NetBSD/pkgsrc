# $NetBSD: dist.mk,v 1.3 2026/10/26 05:37:44 adam Exp $

PY_DISTVERSION=	3.15.2
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python315/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python315/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
