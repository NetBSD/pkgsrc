# $NetBSD: dist.mk,v 1.2 2024/12/05 07:54:03 adam Exp $

PY_DISTVERSION=	3.13.1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python313/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python313/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
