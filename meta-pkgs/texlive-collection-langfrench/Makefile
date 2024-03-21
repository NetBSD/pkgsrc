# $NetBSD: Makefile,v 1.18 2024/03/21 20:00:53 markd Exp $

DISTNAME=	collection-langfrench
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	67951

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	French TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-aeguill-[0-9]*:../../print/tex-aeguill
# depend annee-scolaire
# apprendre-a-programmer-en-tex is documentation only
# apprends-latex is documentation only
DEPENDS+=	tex-babel-basque-[0-9]*:../../print/tex-babel-basque
DEPENDS+=	tex-babel-french-[0-9]*:../../print/tex-babel-french
# depend basque-book
# depend basque-date
# depend bib-fr
# depend bibleref-french
# booktabs-fr is documentation only
# depend cahierprof
# depend couleurs-fr
# depend droit-fr
# depend e-french
# epslatex-fr is documentation only
# expose-expl3-dunkerque-2019 is documentation only
# depend facture
# formation-latex-ul is documentation only
# depend frenchmath
# depend frletter
# depend frpseudocode
DEPENDS+=	tex-hyphen-basque-[0-9]*:../../print/tex-hyphen-basque
DEPENDS+=	tex-hyphen-french-[0-9]*:../../print/tex-hyphen-french
# impatient-fr is documentation only
# depend impnattypo
# l2tabu-french is documentation only
# latex2e-help-texinfo-fr is documentation only
# depend letgut
# lshort-french is documentation only
# depend mafr
# depend matapli
# depend panneauxroute
# depend profcollege
# depend proflabo
# depend proflycee
# depend profsio
# depend tabvar
# depend tdsfrmath
# texlive-fr is documentation only
# translation-array-fr is documentation only
# translation-dcolumn-fr is documentation only
# translation-natbib-fr is documentation only
# translation-tabbing-fr is documentation only
# depend variations
# visualfaq-fr is documentation only
# visualtikz is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
