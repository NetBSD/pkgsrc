# $NetBSD: dist.mk,v 1.1 2014/05/09 02:27:14 wen Exp $

PY_DISTVERSION=	3.4.0
DISTNAME=	Python-${PY_DISTVERSION}
EXTRACT_SUFX=	.tar.xz
DISTINFO_FILE=	${.CURDIR}/../../lang/python34/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python34/patches
MASTER_SITES=	http://www.python.org/ftp/python/${PY_DISTVERSION}/
