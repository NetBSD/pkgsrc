# $NetBSD: Makefile,v 1.11 2024/05/29 16:33:26 adam Exp $

R_PKGNAME=	ncdf4
R_PKGVER=	1.22

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to Unidata netCDF (Version 4 or Earlier) Format Data Files
PKGREVISION=	2
LICENSE=	gnu-gpl-v3

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

# ./configure: 1833: Syntax error: Bad substitution
USE_TOOLS+=	bash
REPLACE_BASH+=	configure

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
