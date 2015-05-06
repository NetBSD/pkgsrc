# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:44 markd Exp $

DISTNAME=	collection-langspanish
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Spanish TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-catalan-[0-9]*:../../print/tex-babel-catalan
# depend babel-galician
DEPENDS+=	tex-babel-spanish-[0-9]*:../../print/tex-babel-spanish
# depend es-tex-faq
DEPENDS+=	tex-hyphen-catalan-[0-9]*:../../print/tex-hyphen-catalan
DEPENDS+=	tex-hyphen-galician-[0-9]*:../../print/tex-hyphen-galician
DEPENDS+=	tex-hyphen-spanish-[0-9]*:../../print/tex-hyphen-spanish
# depend l2tabu-spanish
# depend latex2e-help-texinfo-spanish
# depend latexcheat-esmx
# depend lshort-spanish
# depend spanish-mx

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
