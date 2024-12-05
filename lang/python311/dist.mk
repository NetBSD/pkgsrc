# $NetBSD: dist.mk,v 1.12 2024/12/05 07:51:12 adam Exp $

PY_DISTVERSION=	3.11.11
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
