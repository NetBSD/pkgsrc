# $NetBSD: dist.mk,v 1.3 2023/02/09 10:48:15 adam Exp $

PY_DISTVERSION=	3.11.2
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python311/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python311/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
