# $NetBSD: dist.mk,v 1.10 2024/04/08 12:49:33 adam Exp $

PY_DISTVERSION=	3.11.9
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
