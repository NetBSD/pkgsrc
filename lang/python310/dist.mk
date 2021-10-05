# $NetBSD: dist.mk,v 1.1 2021/10/05 19:07:13 adam Exp $

PY_DISTVERSION=	3.10.0
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python310/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python310/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
