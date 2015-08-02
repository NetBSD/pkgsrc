# $NetBSD: Makefile,v 1.2 2015/08/02 02:14:49 markd Exp $

DISTNAME=	collection-xetex
PKGNAME=	texlive-${DISTNAME}-2015pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	36312

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	XeTeX and packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend arabxetex
# depend bidi-atbegshi
# depend bidicontour
# depend bidipagegrid
# depend bidishadowtext
# depend bidipresentation
# depend fixlatvian
# depend fontbook
# depend fontwrap
# depend interchar
# depend mathspec
# depend philokalia
DEPENDS+=	tex-polyglossia-[0-9]*:../../print/tex-polyglossia
# depend ptext
DEPENDS+=	tex-realscripts-[0-9]*:../../print/tex-realscripts
# depend ucharclasses
# depend unisugar
# depend xecjk
# depend xecolor
# depend xecyr
# depend xeindex
# depend xepersian
# depend xesearch
# depend xespotcolor
DEPENDS+=	tex-xetex-[0-9]*:../../print/tex-xetex
DEPENDS+=	tex-xetex-def-[0-9]*:../../print/tex-xetex-def
DEPENDS+=	tex-xetexconfig-[0-9]*:../../print/tex-xetexconfig
# depend xetex-itrans
# depend xetex-pstricks
# depend xetex-tibetan
# depend xetexfontinfo
# depend xetexko
# depend xevlna
DEPENDS+=	tex-xltxtra-[0-9]*:../../print/tex-xltxtra
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
