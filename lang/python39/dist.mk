# $NetBSD: dist.mk,v 1.12 2022/03/19 18:58:24 adam Exp $

PY_DISTVERSION=	3.9.11
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
