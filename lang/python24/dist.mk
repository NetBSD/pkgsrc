# $NetBSD: dist.mk,v 1.1 2010/09/17 07:11:41 obache Exp $

PY_DISTVERSION=	2.4.5
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python24/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python24/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
