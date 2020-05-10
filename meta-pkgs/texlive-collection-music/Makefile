# $NetBSD: Makefile,v 1.12 2020/05/10 04:13:27 markd Exp $

DISTNAME=	collection-music
PKGNAME=	texlive-${DISTNAME}-2020pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54666

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
# depend leadsheets
# depend latex4musicians
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
# depend songbook
# depend songs
# depend xpiano

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
