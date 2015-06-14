# $NetBSD: Makefile,v 1.3 2015/06/14 13:28:53 markd Exp $

DISTNAME=	collection-music
PKGNAME=	texlive-${DISTNAME}-2015pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	37024

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Music TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-abc-[0-9]*:../../print/tex-abc
DEPENDS+=	tex-bagpipe-[0-9]*:../../print/tex-bagpipe
# depend figbas
# depend gchords
# depend gtrcrd
# depend guitar
# depend guitarchordschemes
# depend harmony
# depend leadsheets
# depend lilyglyphs
# depend m-tx
# depend musixguit
DEPENDS+=	tex-musixtex-[0-9]*:../../print/tex-musixtex
DEPENDS+=	tex-musixtex-fonts-[0-9]*:../../fonts/tex-musixtex-fonts
# depend musixtnt
# depend pmx
# depend pmxchords
# depend songbook
# depend songs

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
