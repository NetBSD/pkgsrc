# $NetBSD: dist.mk,v 1.22 2024/12/05 07:49:52 adam Exp $

PY_DISTVERSION=	3.9.21
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	https://www.python.org/ftp/python/${PY_DISTVERSION}/
