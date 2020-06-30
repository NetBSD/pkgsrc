# $NetBSD: dist.mk,v 1.12 2020/06/30 05:59:40 adam Exp $

PY_DISTVERSION=	3.6.11
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python36/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python36/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
