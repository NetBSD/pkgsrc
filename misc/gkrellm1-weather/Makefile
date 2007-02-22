# $NetBSD: Makefile,v 1.12 2007/02/22 19:26:49 wiz Exp $

DISTNAME=	gkrellweather-0.2.7
PKGNAME=	gkrellm-weather-0.2.7
PKGREVISION=	10
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://www.cse.unsw.edu.au/~flam/
COMMENT=	gkrellm weather plugin

DEPENDS+=	wmweather>=1.3:../../x11/wmweather


pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
