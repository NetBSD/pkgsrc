# $NetBSD: dist.mk,v 1.11 2022/01/15 16:21:26 adam Exp $

PY_DISTVERSION=	3.9.10
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
