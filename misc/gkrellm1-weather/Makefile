# $NetBSD: Makefile,v 1.2 2004/02/24 23:24:06 cube Exp $

DISTNAME=	gkrellweather-0.2.7
PKGNAME=	gkrellm-weather-0.2.7
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.cse.unsw.edu.au/~flam/repository/c/gkrellm/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://www.cse.unsw.edu.au/~flam/programs/gkrellweather.html
COMMENT=	gkrellm weather plugin

DEPENDS+=       wmweather>=1.3:../../x11/wmweather

USE_BUILDLINK2=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
