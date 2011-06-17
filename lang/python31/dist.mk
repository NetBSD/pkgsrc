# $NetBSD: dist.mk,v 1.1.1.1 2011/06/17 00:10:19 reed Exp $

PY_DISTVERSION=	3.1.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python31/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python31/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
