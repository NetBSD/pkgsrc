# $NetBSD: dist.mk,v 1.4 2019/03/26 20:54:55 adam Exp $

PY_DISTVERSION=	3.7.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python37/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python37/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
