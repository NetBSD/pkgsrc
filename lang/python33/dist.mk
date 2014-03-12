# $NetBSD: dist.mk,v 1.5 2014/03/12 10:39:43 wiz Exp $

PY_DISTVERSION=	3.3.5
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python33/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python33/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
