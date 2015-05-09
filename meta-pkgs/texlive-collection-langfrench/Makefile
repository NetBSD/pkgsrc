# $NetBSD: Makefile,v 1.2 2015/05/09 23:31:53 markd Exp $

DISTNAME=	collection-langfrench
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	French TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-aeguill-[0-9]*:../../print/tex-aeguill
# depend apprends-latex
DEPENDS+=	tex-babel-basque-[0-9]*:../../print/tex-babel-basque
DEPENDS+=	tex-babel-french-[0-9]*:../../print/tex-babel-french
# depend basque-book
# depend basque-date
# depend bib-fr
# depend bibleref-french
# depend booktabs-fr
# depend droit-fr
# depend epslatex-fr
# depend facture
# depend frenchle
# depend frletter
DEPENDS+=	tex-hyphen-basque-[0-9]*:../../print/tex-hyphen-basque
DEPENDS+=	tex-hyphen-french-[0-9]*:../../print/tex-hyphen-french
# depend impatient-fr
# depend impnattypo
# depend l2tabu-french
# lshort-french is documentation only
# depend mafr
# depend tabvar
# depend tdsfrmath
# depend texlive-fr
# depend translation-array-fr
# depend translation-dcolumn-fr
# depend translation-natbib-fr
# depend translation-tabbing-fr
# depend variations

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
