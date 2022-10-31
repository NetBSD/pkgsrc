# $NetBSD: dist.mk,v 1.1 2022/10/31 09:50:40 adam Exp $

PY_DISTVERSION=	3.11.0
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
