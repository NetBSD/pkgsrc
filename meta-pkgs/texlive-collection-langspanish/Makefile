# $NetBSD: Makefile,v 1.16 2024/03/21 20:00:54 markd Exp $

DISTNAME=	collection-langspanish
PKGNAME=	texlive-${DISTNAME}-2024
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	67307

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
# texlive-es is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
