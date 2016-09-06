# $NetBSD: dist.mk,v 1.11.6.1 2016/09/06 19:04:27 bsiegert Exp $

PY_DISTVERSION=	2.7.12
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python27/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
