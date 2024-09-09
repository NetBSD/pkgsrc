# $NetBSD: dist.mk,v 1.11 2024/09/09 15:50:30 adam Exp $

PY_DISTVERSION=	3.11.10
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
