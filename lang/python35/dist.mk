# $NetBSD: dist.mk,v 1.3 2016/07/02 15:07:47 adam Exp $

PY_DISTVERSION=	3.5.2
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python35/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python35/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
