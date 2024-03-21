# $NetBSD: Makefile,v 1.16 2024/03/21 20:00:55 markd Exp $

DISTNAME=	collection-music
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	69613

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Music TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-abc-[0-9]*:../../print/tex-abc
# depend autosp
DEPENDS+=	tex-bagpipe-[0-9]*:../../print/tex-bagpipe
# depend chordbars
# depend chordbox
# depend ddphonism
# depend figbas
# depend gchords
# depend gregoriotex
# depend gtrcrd
# depend guitar
# depend guitarchordschemes
# depend guitartabs
# depend harmony
# depend latex4musicians
# depend leadsheets
# depend lilyglyphs
# depend lyluatex
# depend m-tx
# depend musical
# depend musicography
# depend musixguit
DEPENDS+=	tex-musixtex-[0-9]*:../../print/tex-musixtex
DEPENDS+=	tex-musixtex-fonts-[0-9]*:../../fonts/tex-musixtex-fonts
# depend musixtnt
# depend octave
# depend piano
# depend pmx
# depend pmxchords
# depend recorder-fingering
# depend songbook
# depend songproj
# depend songs
# depend undar-digitacion
# depend xml2pmx
# depend xpiano

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
