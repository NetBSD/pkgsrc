# $NetBSD: dist.mk,v 1.4 2021/04/03 06:23:13 adam Exp $

PY_DISTVERSION=	3.9.3
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
