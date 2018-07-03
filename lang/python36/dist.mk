# $NetBSD: dist.mk,v 1.7 2018/07/03 03:52:41 adam Exp $

PY_DISTVERSION=	3.6.6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python36/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python36/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
