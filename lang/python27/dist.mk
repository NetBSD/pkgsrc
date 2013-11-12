# $NetBSD: dist.mk,v 1.6 2013/11/12 18:57:25 adam Exp $

PY_DISTVERSION=	2.7.6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python27/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
