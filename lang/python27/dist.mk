# $NetBSD: dist.mk,v 1.13 2016/12/30 10:53:21 adam Exp $

PY_DISTVERSION=	2.7.13
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python27/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
