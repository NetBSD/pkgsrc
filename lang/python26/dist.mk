# $NetBSD: dist.mk,v 1.4 2013/11/06 07:25:49 adam Exp $

PY_DISTVERSION=	2.6.9
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python26/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python26/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
