# $NetBSD: dist.mk,v 1.1.1.1 2011/02/22 08:51:58 obache Exp $

PY_DISTVERSION=	2.7.1
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python27/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python27/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
