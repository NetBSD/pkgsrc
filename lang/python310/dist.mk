# $NetBSD: dist.mk,v 1.20 2025/10/10 13:01:00 adam Exp $

PY_DISTVERSION=	3.10.19
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
