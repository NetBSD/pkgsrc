# $NetBSD: dist.mk,v 1.4 2014/02/11 17:56:16 adam Exp $

PY_DISTVERSION=	3.3.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python33/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python33/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
