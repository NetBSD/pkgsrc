# $NetBSD: Makefile,v 1.12 2022/04/10 03:54:49 markd Exp $

DISTNAME=	collection-games
PKGNAME=	texlive-${DISTNAME}-2021pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	62102

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Games typesetting TeX packages

DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-bartel-chess-fonts-[0-9]*:../../fonts/tex-bartel-chess-fonts
DEPENDS+=	tex-chess-[0-9]*:../../print/tex-chess
DEPENDS+=	tex-chess-problem-diagrams-[0-9]*:../../print/tex-chess-problem-diagrams
DEPENDS+=	tex-chessboard-[0-9]*:../../print/tex-chessboard
DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss
# depend crossword
# depend crosswrd
# depend egameps
# depend gamebook
# depend gamebooklib
DEPENDS+=	tex-go-[0-9]*:../../print/tex-go
# depend hanoi
# depend havannah
# depend hexboard
# depend hexgame
# depend hmtrump
# depend horoscop
# depend jigsaw
# depend labyrinth
# depend logicpuzzle
# depend mahjong
# depend musikui
# depend nimsticks
# depend onedown
# depend othello
# depend othelloboard
# depend pas-crosswords
DEPENDS+=	tex-psgo-[0-9]*:../../graphics/tex-psgo
# depend realtranspose
# depend reverxii
# depend rubik
DEPENDS+=	tex-schwalbe-chess-[0-9]*:../../print/tex-schwalbe-chess
# depend sgame
DEPENDS+=	tex-skak-[0-9]*:../../print/tex-skak
DEPENDS+=	tex-skaknew-[0-9]*:../../print/tex-skaknew
# depend soup
# depend sudoku
# depend sudokubundle
# depend xq
DEPENDS+=	tex-xskak-[0-9]*:../../print/tex-xskak

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
