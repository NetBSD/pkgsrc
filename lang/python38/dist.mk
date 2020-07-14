# $NetBSD: dist.mk,v 1.5 2020/07/14 19:12:31 adam Exp $

PY_DISTVERSION=	3.8.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python38/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python38/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
