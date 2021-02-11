# $NetBSD: Makefile,v 1.8 2021/02/11 22:08:46 markd Exp $

DISTNAME=	collection-humanities
PKGNAME=	texlive-${DISTNAME}-2020pre2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54074

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Graphics, pictures, diagrams TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex


# depend adtrees
# depend bibleref
# depend bibleref-lds
# depend bibleref-mouth
# depend bibleref-parse
# depend covington
# depend diadia
# depend dramatist
# depend dvgloss
# depend ecltree
# depend edfnotes
# depend ednotes
# depend eledform
# depend eledmac
# depend expex
# depend gb4e
# depend gmverse
# depend jura
# depend juraabbrev
# depend juramisc
# depend jurarsp
# depend ledmac
# depend lexikon
# depend lexref
# depend ling-macros
# depend linguex
# depend liturg
# depend metrix
# depend parallel
# depend parrun
# depend phonrule
# depend plari
# depend play
# depend poemscol
# depend poetry
# depend poetrytex
# depend qobitree
DEPENDS+=	tex-qtree-[0-9]*:../../print/tex-qtree
# depend reledmac
# depend rrgtrees
# depend rtklage
# depend screenplay
# depend screenplay-pkg
# depend sides
# depend stage
# depend textglos
# depend theatre
# depend thalie
# depend tree-dvips
DEPENDS+=	tex-verse-[0-9]*:../../print/tex-verse
# depend xyling

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
