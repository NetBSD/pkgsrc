# $NetBSD: dist.mk,v 1.20 2024/03/20 15:41:01 adam Exp $

PY_DISTVERSION=	3.9.19
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
