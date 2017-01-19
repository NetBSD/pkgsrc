# $NetBSD: dist.mk,v 1.4 2017/01/19 13:55:53 wen Exp $

PY_DISTVERSION=	3.5.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python35/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python35/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
