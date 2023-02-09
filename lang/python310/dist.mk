# $NetBSD: dist.mk,v 1.11 2023/02/09 10:47:08 adam Exp $

PY_DISTVERSION=	3.10.10
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
