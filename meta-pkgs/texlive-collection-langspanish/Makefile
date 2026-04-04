# $NetBSD: Makefile,v 1.18 2026/04/04 05:43:15 markd Exp $

DISTNAME=	collection-langspanish
PKGNAME=	texlive-${DISTNAME}-2026
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	72203

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Spanish TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# antique-spanish-units is documentation only
DEPENDS+=	tex-babel-catalan-[0-9]*:../../print/tex-babel-catalan
DEPENDS+=	tex-babel-galician-[0-9]*:../../print/tex-babel-galician
DEPENDS+=	tex-babel-spanish-[0-9]*:../../print/tex-babel-spanish
# es-tex-faq is documentation only
DEPENDS+=	tex-hyphen-catalan-[0-9]*:../../print/tex-hyphen-catalan
DEPENDS+=	tex-hyphen-galician-[0-9]*:../../print/tex-hyphen-galician
DEPENDS+=	tex-hyphen-spanish-[0-9]*:../../print/tex-hyphen-spanish
# l2tabu-spanish is documentation only
# latex2e-help-texinfo-spanish is documentation only
# latexcheat-esmx is documentation only
# lshort-spanish is documentation only
DEPENDS+=	tex-quran-es-[0-9]*:../../print/tex-quran-es
# texlive-es is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
