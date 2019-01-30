# $NetBSD: Makefile,v 1.9 2019/01/30 10:15:45 markd Exp $

DISTNAME=	collection-langfrench
PKGNAME=	texlive-${DISTNAME}-2018pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	49728

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	French TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-aeguill-[0-9]*:../../print/tex-aeguill
# apprends-latex is documentation only
DEPENDS+=	tex-babel-basque-[0-9]*:../../print/tex-babel-basque
DEPENDS+=	tex-babel-french-[0-9]*:../../print/tex-babel-french
# depend basque-book
# depend basque-date
# depend bib-fr
# depend bibleref-french
# booktabs-fr is documentation only
# depend droit-fr
# depend e-french
# epslatex-fr is documentation only
# depend facture
# formation-latex-ul is documentation only
# depend frenchmath
# depend frletter
# guide-latex-fr is documentation only
DEPENDS+=	tex-hyphen-basque-[0-9]*:../../print/tex-hyphen-basque
DEPENDS+=	tex-hyphen-french-[0-9]*:../../print/tex-hyphen-french
# impatient-fr is documentation only
# depend impnattypo
# l2tabu-french is documentation only
# latex2e-help-texinfo-fr is documentation only
# lshort-french is documentation only
# depend mafr
# depend tabvar
# depend tdsfrmath
# texlive-fr is documentation only
# translation-array-fr is documentation only
# translation-dcolumn-fr is documentation only
# translation-natbib-fr is documentation only
# translation-tabbing-fr is documentation only
# depend variations
# visualtikz is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
