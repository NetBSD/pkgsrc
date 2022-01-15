# $NetBSD: dist.mk,v 1.3 2022/01/15 16:23:47 adam Exp $

PY_DISTVERSION=	3.10.2
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
