# $NetBSD: dist.mk,v 1.1 2015/12/05 17:12:13 adam Exp $

PY_DISTVERSION=	3.5.0
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python35/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python35/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
