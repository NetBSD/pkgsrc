# $NetBSD: dist.mk,v 1.14 2023/08/25 08:26:49 adam Exp $

PY_DISTVERSION=	3.10.13
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
