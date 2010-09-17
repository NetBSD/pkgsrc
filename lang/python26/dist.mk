# $NetBSD: dist.mk,v 1.1 2010/09/17 07:11:42 obache Exp $

PY_DISTVERSION=	2.6.6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python26/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python26/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
