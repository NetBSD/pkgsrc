# $NetBSD: dist.mk,v 1.16 2022/10/12 08:38:36 adam Exp $

PY_DISTVERSION=	3.7.15
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python37/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python37/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
