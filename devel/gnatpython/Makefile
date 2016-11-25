# $NetBSD: Makefile,v 1.12 2016/11/25 01:05:47 marino Exp $

DISTNAME=	gnatpython-${SNAPSHOT}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER= 	draco@marino.st
HOMEPAGE=	http://forge.open-do.org/projects/gnatpython
COMMENT=	Python package used in Ada testsuites
LICENSE= 	gnu-gpl-v3
SNAPSHOT=	20110912

EGG_NAME=	gnatpython-1.2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 20110912

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
