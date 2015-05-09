# $NetBSD: Makefile,v 1.2 2015/05/09 23:31:53 markd Exp $

DISTNAME=	collection-langenglish
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	34607

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	US and UK English TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-hyphen-english-[0-9]*:../../print/tex-hyphen-english
# depend FAQ-en
# depend MemoirChapStyles
# depend Type1fonts
# depend amslatex-primer
# depend around-the-bend
# depend ascii-chart
# depend components-of-TeX
# depend comprehensive
# depend dickimaw
# depend dtxtut
# depend first-latex-doc
# depend gentle
DEPENDS+=	tex-guide-to-latex-[0-9]*:../../print/tex-guide-to-latex
# depend happy4th
# depend impatient
# depend intro-scientific
# depend knuth
# depend l2tabu-english
# depend latex-brochure
# depend latex-course
# depend latex-doc-ptr
# depend latex-graphics-companion
# depend latex-veryshortguide
# depend latex-web-companion
# depend latex2e-help-texinfo
# depend latex4wp
# depend latexcheat
# depend latexcourse-rug
# depend latexfileinfo-pkgs
# lshort-english is documentation only
# depend macros2e
# depend math-e
# depend memdesign
# depend metafont-beginners
# depend metapost-examples
# depend mil3
# depend patgen2-tutorial
# depend pictexsum
# depend plain-doc
# depend presentations-en
# depend pstricks-examples-en
# depend simplified-latex
# depend svg-inkscape
# depend tabulars-e
# depend tamethebeast
# depend tds
# depend tex-font-errors-cheatsheet
# depend tex-overview
# depend tex-refs
# depend texbytopic
# depend titlepages
# depend tlc2
# depend visualfaq
# depend voss-mathmode
# depend webguide
# depend xetexref

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
