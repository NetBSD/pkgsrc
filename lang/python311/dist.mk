# $NetBSD: dist.mk,v 1.4 2023/04/06 11:30:37 adam Exp $

PY_DISTVERSION=	3.11.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
