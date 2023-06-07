# $NetBSD: dist.mk,v 1.18 2023/06/07 13:23:58 adam Exp $

PY_DISTVERSION=	3.7.17
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python37/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python37/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
