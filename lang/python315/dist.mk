# $NetBSD: dist.mk,v 1.2 2026/10/22 08:08:54 adam Exp $

PY_DISTVERSION=	3.15.1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python315/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python315/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
