# $NetBSD: dist.mk,v 1.9 2022/10/12 08:02:25 adam Exp $

PY_DISTVERSION=	3.10.8
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
