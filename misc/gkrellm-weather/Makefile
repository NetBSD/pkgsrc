# $NetBSD: Makefile,v 1.2 2001/11/01 15:32:28 damon Exp $

DISTNAME=	gkrellweather-0.2.7
PKGNAME=	gkrellm-weather-0.2.7
CATEGORIES=	misc
MASTER_SITES=	http://www.cse.unsw.edu.au/~flam/repository/c/gkrellm/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://www.cse.unsw.edu.au/~flam/programs/gkrellweather.html
COMMENT=	gkrellm weather plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm
DEPENDS+=       wmWeather-1.3*:../../x11/wmweather

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../mk/bsd.pkg.mk"
