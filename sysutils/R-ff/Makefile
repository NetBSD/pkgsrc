# $NetBSD: Makefile,v 1.3 2024/12/07 04:15:39 mef Exp $

R_PKGNAME=	ff
R_PKGVER=	4.5.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast Access Functions for Large Data on Disk
LICENSE=	gnu-gpl-v3 OR gnu-gpl-v2	# See also LICENSE file

DEPENDS+=	R-bit>=4.0.0:../../devel/R-bit

TEST_DEPENDS+=	R-biglm-[0-9]*:../../sysutils/R-biglm
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
