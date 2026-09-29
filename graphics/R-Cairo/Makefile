# $NetBSD: Makefile,v 1.20 2026/09/29 06:05:31 wiz Exp $

R_PKGNAME=	Cairo
R_PKGVER=	1.7-0
PKGREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R graphics device using cairo graphics library
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-png-[0-9]*:../../graphics/R-png

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
