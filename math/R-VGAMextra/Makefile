# $NetBSD: Makefile,v 1.1 2024/10/26 13:16:24 mef Exp $

R_PKGNAME=	VGAMextra
R_PKGVER=	0.0-6

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Additions and Extensions of the 'VGAM' Package
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-VGAM>=1.0.0:../../math/R-VGAM

TEST_DEPENDS+=	R-VGAMdata-[0-9]*:../../math/R-VGAMdata

TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
