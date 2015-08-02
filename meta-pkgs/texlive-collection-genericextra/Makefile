# $NetBSD: Makefile,v 1.3 2015/08/02 02:59:03 markd Exp $

DISTNAME=	collection-genericextra
PKGNAME=	texlive-${DISTNAME}-2015pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	37591

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Generic additional packages for TeX

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend abbr
# depend abstyles
# depend barr
# depend bitelist
# depend borceux
# depend c-pascal
# depend catcodes
# depend chronosys
# depend colorsep
# depend dinat
# depend dirtree
# depend docbytex
# depend dowith
# depend eijkhout
# depend encxvlna
# depend epigram
# depend fenixpar
# depend fltpoint
# depend fntproof
# depend gates
# depend ifetex
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
# depend insbox
# depend lambda-lists
# depend langcode
# depend lecturer
# depend librarian
# depend mathdots
# depend metatex
# depend midnight
# depend navigator
# depend ofs
# depend pdf-trans
# depend plainpkg
# depend schemata
# depend shade
# depend systeme
# depend tabto-generic
# depend termmenu
# depend tracklang
# depend texapi
# depend upca
# depend xlop
# depend yax

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
