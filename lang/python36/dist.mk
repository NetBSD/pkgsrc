# $NetBSD: dist.mk,v 1.13 2020/08/19 07:07:46 adam Exp $

PY_DISTVERSION=	3.6.12
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python36/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python36/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
