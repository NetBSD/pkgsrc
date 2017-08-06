# $NetBSD: Makefile,v 1.7 2017/08/06 12:48:15 markd Exp $

DISTNAME=	collection-xetex
PKGNAME=	texlive-${DISTNAME}-2017pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	44954

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	XeTeX and packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend arabxetex
# depend awesomebox
# depend bidi-atbegshi
# depend bidicontour
# depend bidipagegrid
# depend bidishadowtext
# depend bidipresentation
# depend fixlatvian
# depend font-change-xetex
# depend fontbook
# depend fontwrap
# depend interchar
# depend philokalia
DEPENDS+=	tex-polyglossia-[0-9]*:../../print/tex-polyglossia
# depend ptext
# depend quran
DEPENDS+=	tex-realscripts-[0-9]*:../../print/tex-realscripts
# depend simple-resume-cv
# depend simple-thesis-dissertation
# depend ucharclasses
# depend unicode-bidi
# depend unisugar
# depend xebaposter
# depend xechangebar
# depend xecjk
# depend xecolor
# depend xecyr
# depend xeindex
# depend xesearch
# depend xespotcolor
DEPENDS+=	tex-xetex-[0-9]*:../../print/tex-xetex
DEPENDS+=	tex-xetexconfig-[0-9]*:../../print/tex-xetexconfig
# depend xetex-itrans
# depend xetex-pstricks
# depend xetex-tibetan
# depend xetexfontinfo
# depend xetexko
# depend xevlna

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
