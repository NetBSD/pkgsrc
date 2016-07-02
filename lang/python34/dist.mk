# $NetBSD: dist.mk,v 1.6 2016/07/02 15:23:33 adam Exp $

PY_DISTVERSION=	3.4.5
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python34/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python34/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
