# $NetBSD: Makefile,v 1.10 2019/05/15 10:03:12 markd Exp $

DISTNAME=	collection-music
PKGNAME=	texlive-${DISTNAME}-2019pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	51000

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Music TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-abc-[0-9]*:../../print/tex-abc
# depend autosp
DEPENDS+=	tex-bagpipe-[0-9]*:../../print/tex-bagpipe
# depend chordbars
# depend chordbox
# depend figbas
# depend gchords
# depend gregoriotex
# depend gtrcrd
# depend guitar
# depend guitarchordschemes
# depend guitartabs
# depend harmony
# depend leadsheets
# depend latex4musicians
# depend lilyglyphs
# depend lyluatex
# depend m-tx
# depend musicography
# depend musixguit
DEPENDS+=	tex-musixtex-[0-9]*:../../print/tex-musixtex
DEPENDS+=	tex-musixtex-fonts-[0-9]*:../../fonts/tex-musixtex-fonts
# depend musixtnt
# depend octave
# depend piano
# depend pmx
# depend pmxchords
# depend songbook
# depend songs
# depend xpiano

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
