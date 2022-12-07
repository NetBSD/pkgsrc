# $NetBSD: dist.mk,v 1.17 2022/12/07 11:52:00 adam Exp $

PY_DISTVERSION=	3.8.16
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python38/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python38/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
