# $NetBSD: Makefile,v 1.4 2019/07/31 16:00:30 brook Exp $

CATEGORIES=	graphics R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rforge.net/Cairo/
COMMENT=	R graphics device using cairo graphics library
LICENSE=	gnu-gpl-v2

R_PKGNAME=	Cairo
R_PKGVER=	1.5-10

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
