# $NetBSD: dist.mk,v 1.11 2021/02/16 19:40:33 adam Exp $

PY_DISTVERSION=	3.7.10
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python37/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python37/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
