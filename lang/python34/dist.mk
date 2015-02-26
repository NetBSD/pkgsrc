# $NetBSD: dist.mk,v 1.4 2015/02/26 06:23:06 adam Exp $

PY_DISTVERSION=	3.4.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python34/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python34/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
