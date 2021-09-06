# $NetBSD: dist.mk,v 1.13 2021/09/06 07:25:13 adam Exp $

PY_DISTVERSION=	3.7.12
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python37/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python37/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
