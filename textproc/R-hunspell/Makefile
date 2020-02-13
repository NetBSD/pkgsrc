# $NetBSD: Makefile,v 1.1 2020/02/13 15:26:16 mef Exp $

R_PKGNAME=	hunspell
R_PKGVER=	3.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High-Performance Stemmer, Tokenizer, and Spell Checker
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1

DEPENDS+=	R-digest>=0.6.20:../../security/R-digest

#Packages suggested but not available:
#  'spelling', 'pdftools', 'janeaustenr', 'wordcloud2', 'stopwords'
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling


USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
