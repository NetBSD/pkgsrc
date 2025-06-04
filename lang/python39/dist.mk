# $NetBSD: dist.mk,v 1.24 2025/06/04 14:12:53 adam Exp $

PY_DISTVERSION=	3.9.23
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
