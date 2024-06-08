# $NetBSD: dist.mk,v 1.5 2024/06/08 07:39:40 adam Exp $

PY_DISTVERSION=	3.12.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python312/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python312/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
