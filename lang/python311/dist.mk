# $NetBSD: dist.mk,v 1.2 2022/12/07 11:55:37 adam Exp $

PY_DISTVERSION=	3.11.1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
