# $NetBSD: dist.mk,v 1.5 2016/05/13 16:35:03 adam Exp $

PY_DISTVERSION=	3.4.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python34/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python34/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
