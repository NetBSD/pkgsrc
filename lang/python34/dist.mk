# $NetBSD: dist.mk,v 1.7 2017/01/19 01:25:09 wen Exp $

PY_DISTVERSION=	3.4.6
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python34/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python34/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
