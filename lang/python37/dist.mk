# $NetBSD: dist.mk,v 1.1 2018/07/03 03:55:40 adam Exp $

PY_DISTVERSION=	3.7.0
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python37/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python37/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
