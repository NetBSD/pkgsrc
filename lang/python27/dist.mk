# $NetBSD: dist.mk,v 1.10 2015/05/24 07:44:07 adam Exp $

PY_DISTVERSION=	2.7.10
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python27/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
