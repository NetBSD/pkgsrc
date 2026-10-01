# $NetBSD: dist.mk,v 1.17 2026/10/01 07:28:53 adam Exp $

PY_DISTVERSION=	3.13.16
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python313/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python313/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
