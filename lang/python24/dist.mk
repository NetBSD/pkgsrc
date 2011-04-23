# $NetBSD: dist.mk,v 1.2 2011/04/23 08:53:53 obache Exp $

PY_DISTVERSION=	2.4.6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python24/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python24/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
