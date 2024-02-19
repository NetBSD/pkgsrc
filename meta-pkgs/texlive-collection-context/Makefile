# $NetBSD: Makefile,v 1.14 2024/02/19 10:45:36 markd Exp $

DISTNAME=	collection-context
PKGNAME=	texlive-${DISTNAME}-2023.69108
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	69108

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	ConTeXt and packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-context-calendar-examples-[0-9]*:../../print/tex-context-calendar-examples
DEPENDS+=	tex-context-collating-marks-[0-9]*:../../print/tex-context-collating-marks
DEPENDS+=	tex-context-cyrillicnumbers-[0-9]*:../../print/tex-context-cyrillicnumbers
DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter
DEPENDS+=	tex-context-gnuplot-[0-9]*:../../print/tex-context-gnuplot
DEPENDS+=	tex-context-handlecsv-[0-9]*:../../print/tex-context-handlecsv
DEPENDS+=	tex-context-legacy-[0-9]*:../../print/tex-context-legacy
DEPENDS+=	tex-context-letter-[0-9]*:../../print/tex-context-letter
DEPENDS+=	tex-context-mathsets-[0-9]*:../../print/tex-context-mathsets
# context-notes-zh-cn is documentation only
DEPENDS+=	tex-context-pocketdiary-[0-9]*:../../print/tex-context-pocketdiary
DEPENDS+=	tex-context-simpleslides-[0-9]*:../../print/tex-context-simpleslides
DEPENDS+=	tex-context-squares-[0-9]*:../../print/tex-context-squares
DEPENDS+=	tex-context-sudoku-[0-9]*:../../print/tex-context-sudoku
DEPENDS+=	tex-context-texlive-[0-9]*:../../print/tex-context-texlive
DEPENDS+=	tex-context-transliterator-[0-9]*:../../print/tex-context-transliterator
DEPENDS+=	tex-context-typescripts-[0-9]*:../../print/tex-context-typescripts
DEPENDS+=	tex-context-vim-[0-9]*:../../print/tex-context-vim
DEPENDS+=	tex-context-visualcounter-[0-9]*:../../print/tex-context-visualcounter
DEPENDS+=	tex-jmn-[0-9]*:../../fonts/tex-jmn
DEPENDS+=	tex-luajittex-[0-9]*:../../print/tex-luajittex

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
