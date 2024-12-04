# $NetBSD: Makefile,v 1.14 2024/12/04 14:07:23 mef Exp $

R_PKGNAME=	Cairo
R_PKGVER=	1.6-2
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
