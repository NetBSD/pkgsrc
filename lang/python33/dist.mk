# $NetBSD: dist.mk,v 1.1 2012/12/10 03:15:48 tsarna Exp $

PY_DISTVERSION=	3.3.0
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python33/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python33/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
