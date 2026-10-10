# $NetBSD: dist.mk,v 1.1 2026/10/10 10:34:19 adam Exp $

PY_DISTVERSION=	3.15.0
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python315/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python315/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
