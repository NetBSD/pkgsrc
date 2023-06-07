# $NetBSD: dist.mk,v 1.5 2023/06/07 13:28:49 adam Exp $

PY_DISTVERSION=	3.11.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
