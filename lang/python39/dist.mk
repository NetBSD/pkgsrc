# $NetBSD: dist.mk,v 1.5 2021/04/05 07:40:10 adam Exp $

PY_DISTVERSION=	3.9.4
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python39/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python39/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
