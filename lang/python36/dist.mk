# $NetBSD: dist.mk,v 1.4 2017/10/05 08:17:25 adam Exp $

PY_DISTVERSION=	3.6.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python36/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python36/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
