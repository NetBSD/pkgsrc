# $NetBSD: Makefile,v 1.4 2004/03/18 15:33:21 cube Exp $

DISTNAME=	gkrellweather-0.2.7
PKGNAME=	gkrellm-weather-0.2.7
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://www.cse.unsw.edu.au/~flam/repository/c/gkrellm/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://www.cse.unsw.edu.au/~flam/programs/gkrellweather.html
COMMENT=	gkrellm weather plugin

DEPENDS+=       wmweather>=1.3:../../x11/wmweather

USE_BUILDLINK3=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
