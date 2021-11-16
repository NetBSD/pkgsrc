# $NetBSD: dist.mk,v 1.10 2021/11/16 14:23:50 adam Exp $

PY_DISTVERSION=	3.9.9
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
