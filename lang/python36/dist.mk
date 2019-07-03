# $NetBSD: dist.mk,v 1.10 2019/07/03 20:10:41 adam Exp $

PY_DISTVERSION=	3.6.9
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python36/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python36/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
