# $NetBSD: Makefile,v 1.3 2015/07/02 21:12:04 markd Exp $

DISTNAME=	collection-science
PKGNAME=	texlive-${DISTNAME}-2015pre2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	36989

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Natural and computer sciences TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-SIstyle-[0-9]*:../../print/tex-SIstyle
DEPENDS+=	tex-SIunits-[0-9]*:../../print/tex-SIunits
# depend alg
DEPENDS+=	tex-algorithm2e-[0-9]*:../../print/tex-algorithm2e
DEPENDS+=	tex-algorithmicx-[0-9]*:../../print/tex-algorithmicx
DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
# depend biocon
# depend bohr
# depend bpchem
# depend bytefield
DEPENDS+=	tex-chemarrow-[0-9]*:../../print/tex-chemarrow
# depend chemcompounds
# depend chemcono
# depend chemexec
# depend chemformula
# depend chemgreek
# depend chemmacros
# depend chemnum
# depend chemschemex
# depend chemstyle
DEPENDS+=	tex-clrscode-[0-9]*:../../print/tex-clrscode
# depend clrscode3e
# depend complexity
# depend computational-complexity
# depend cryptocode
# depend digiconfigs
# depend drawstack
# depend dyntree
# depend eltex
# depend endiagram
# depend engtlc
# depend fouridx
# depend functan
# depend galois
# depend gastex
# depend gene-logic
# depend ghsystem
# depend gu
# depend hep
# depend hepnames
# depend hepparticles
# depend hepthesis
# depend hepunits
# depend karnaugh
# depend karnaughmap
# depend matlab-prettifier
DEPENDS+=	tex-mhchem-[0-9]*:../../print/tex-mhchem
# depend miller
# depend mychemistry
# depend nuc
# depend objectz
# depend physics
# depend pseudocode
# depend pygmentex
# depend sasnrdisplay
# depend sciposter
# depend sclang-prettifier
# depend sfg
DEPENDS+=	tex-siunitx-[0-9]*:../../print/tex-siunitx
# depend steinmetz
# depend struktex
# depend substances
# depend t-angles
# depend textopo
# depend ulqda
# depend unitsdef
# depend xymtex
# depend youngtab

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
