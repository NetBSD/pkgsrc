# $NetBSD: Makefile,v 1.8 2023/03/12 09:52:10 mef Exp $

R_PKGNAME=	markdown
R_PKGVER=	1.5
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Render Markdown with the C Library 'Sundown'
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-commonmark-[0-9]*:../../textproc/R-commonmark
DEPENDS+=	R-mime>=0.3:../../mail/R-mime
DEPENDS+=	R-xfun-[0-9]*:../../devel/R-xfun

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-RCurl-[0-9]*:../../www/R-RCurl

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
