# $NetBSD: Makefile,v 1.5 2019/08/08 19:53:42 brook Exp $

R_PKGNAME=	Cairo
R_PKGVER=	1.5-10
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R graphics device using cairo graphics library
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
