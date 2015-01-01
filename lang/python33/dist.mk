# $NetBSD: dist.mk,v 1.6 2015/01/01 21:39:45 he Exp $

PY_DISTVERSION=	3.3.6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python33/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python33/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
