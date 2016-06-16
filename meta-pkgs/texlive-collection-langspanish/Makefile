# $NetBSD: Makefile,v 1.7 2016/06/16 04:03:15 markd Exp $

DISTNAME=	collection-langspanish
PKGNAME=	texlive-${DISTNAME}-2016
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	40587

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Spanish TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-catalan-[0-9]*:../../print/tex-babel-catalan
DEPENDS+=	tex-babel-galician-[0-9]*:../../print/tex-babel-galician
DEPENDS+=	tex-babel-spanish-[0-9]*:../../print/tex-babel-spanish
# es-tex-faq is documentation only
DEPENDS+=	tex-hyphen-catalan-[0-9]*:../../print/tex-hyphen-catalan
DEPENDS+=	tex-hyphen-galician-[0-9]*:../../print/tex-hyphen-galician
DEPENDS+=	tex-babel-spanglish-[0-9]*:../../print/tex-babel-spanglish
DEPENDS+=	tex-hyphen-spanish-[0-9]*:../../print/tex-hyphen-spanish
# l2tabu-spanish is documentation only
# latex2e-help-texinfo-spanish is documentation only
# latexcheat-esmx is documentation only
# lshort-spanish is documentation only
DEPENDS+=	tex-spanish-mx-[0-9]*:../../print/tex-spanish-mx
# texlive-es is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
