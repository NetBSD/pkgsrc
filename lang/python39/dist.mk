# $NetBSD: dist.mk,v 1.23 2025/04/09 14:46:06 adam Exp $

PY_DISTVERSION=	3.9.22
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
