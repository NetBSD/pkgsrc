# $NetBSD: dist.mk,v 1.3.12.1 2013/11/25 10:30:45 tron Exp $

PY_DISTVERSION=	2.6.9
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python26/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python26/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
