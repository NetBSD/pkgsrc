# $NetBSD: dist.mk,v 1.3 2024/02/07 08:06:57 adam Exp $

PY_DISTVERSION=	3.12.2
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python312/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python312/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
