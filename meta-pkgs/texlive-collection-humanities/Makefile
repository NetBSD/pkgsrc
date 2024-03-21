# $NetBSD: Makefile,v 1.13 2024/03/21 20:00:52 markd Exp $

DISTNAME=	collection-humanities
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	68465

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
# depend eledform
# depend eledmac
# depend expex
# depend expex-glossonly
# depend gb4e
# depend gmverse
# depend jura
# depend juraabbrev
# depend juramisc
# depend jurarsp
# depend langnames
# depend ledmac
# depend lexikon
# depend lexref
# depend ling-macros
# depend linguex
# depend liturg
# depend metrix
# depend nnext
# depend opbible
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
# depend thalie
# depend theatre
# depend tree-dvips
DEPENDS+=	tex-verse-[0-9]*:../../print/tex-verse
# depend xyling

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
