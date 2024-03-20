# $NetBSD: dist.mk,v 1.15 2024/03/20 15:42:25 adam Exp $

PY_DISTVERSION=	3.10.14
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
