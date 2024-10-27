# $NetBSD: Makefile,v 1.7 2024/10/27 05:28:57 mef Exp $

R_PKGNAME=	git2r
R_PKGVER=	0.35.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides access to Git repositories
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-getPass-[0-9]*:../../security/R-getPass
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

#USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

.include "../../devel/libgit2/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
