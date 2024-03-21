# $NetBSD: Makefile,v 1.19 2024/03/21 20:00:56 markd Exp $

DISTNAME=	collection-xetex
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	69452

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	XeTeX and packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-arabxetex-[0-9]*:../../print/tex-arabxetex
# depend bidi-atbegshi
# depend bidicontour
# depend bidipagegrid
# depend bidipresentation
# depend bidishadowtext
# depend businesscard-qrcode
# depend cqubeamer
# depend fixlatvian
# depend font-change-xetex
# depend fontbook
# depend fontwrap
# depend interchar
# depend na-position
# depend philokalia
DEPENDS+=	tex-polyglossia-[0-9]*:../../print/tex-polyglossia
# depend ptext
DEPENDS+=	tex-realscripts-[0-9]*:../../print/tex-realscripts
# depend simple-resume-cv
# depend simple-thesis-dissertation
# depend tetragonos
# depend ucharclasses
# depend unicode-bidi
# depend unimath-plain-xetex
# depend unisugar
# depend xebaposter
# depend xechangebar
# depend xecolor
# depend xecyr
# depend xeindex
# depend xelatex-dev
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
# depend zbmath-review-template

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
