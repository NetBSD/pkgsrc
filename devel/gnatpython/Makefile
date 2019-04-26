# $NetBSD: Makefile,v 1.18 2019/04/26 13:13:49 maya Exp $

DISTNAME=	gnatpython-${SNAPSHOT}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER= 	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forge.open-do.org/projects/gnatpython
COMMENT=	Python package used in Ada testsuites
LICENSE= 	gnu-gpl-v3
SNAPSHOT=	20110912

EGG_NAME=	gnatpython-1.2

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 20110912

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
