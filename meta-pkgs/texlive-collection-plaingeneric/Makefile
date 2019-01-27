# $NetBSD: Makefile,v 1.7 2019/01/27 09:59:14 markd Exp $

DISTNAME=	collection-plaingeneric
PKGNAME=	texlive-${DISTNAME}-2018pre3
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	49271

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Plain (La)TeX packages

DEPENDS+=	texlive-collection-basic>=2014:../../meta-pkgs/texlive-collection-basic

# depend abbr
# depend abstyles
DEPENDS+=	tex-apnum>=1.1:../../math/tex-apnum
# depend autoaligne
# depend barr
# depend bitelist
# depend borceux
# depend c-pascal
# depend catcodes
# depend chronosys
# depend colorsep
# depend cweb-old
# depend dinat
# depend dirtree
# depend docbytex
# depend dowith
DEPENDS+=	tex-eijkhout-[0-9]*:../../print/tex-eijkhout
# depend encxvlna
# depend epigram
DEPENDS+=	tex-epsf>=2.7.4:../../print/tex-epsf
DEPENDS+=	tex-epsf-dvipdfmx-[0-9]*:../../print/tex-epsf-dvipdfmx
# depend fenixpar
DEPENDS+=	tex-figflow-[0-9]*:../../print/tex-figflow
DEPENDS+=	tex-fixpdfmag-[0-9]*:../../print/tex-fixpdfmag
# depend fltpoint
# depend fntproof
DEPENDS+=	tex-font-change-[0-9]*:../../print/tex-font-change
DEPENDS+=	tex-fontch-[0-9]*:../../print/tex-fontch
DEPENDS+=	tex-fontname>=2013:../../fonts/tex-fontname
# depend gates
DEPENDS+=	tex-genmisc>=2013:../../print/tex-genmisc
DEPENDS+=	tex-getoptk-[0-9]*:../../print/tex-getoptk
DEPENDS+=	tex-gfnotation-[0-9]*:../../print/tex-gfnotation
# depend gfnotation
# depend gobble
DEPENDS+=	tex-graphics-pln-[0-9]*:../../graphics/tex-graphics-pln
# depend gtl
# depend hlist
DEPENDS+=	tex-hyplain-[0-9]*:../../print/tex-hyplain
# depend ifetex
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
# depend insbox
DEPENDS+=	tex-js-misc-[0-9]*:../../print/tex-js-misc
DEPENDS+=	tex-kastrup>=2010:../../math/tex-kastrup
DEPENDS+=	tex-lambda-lists-[0-9]*:../../print/tex-lambda-lists
# depend langcode
# depend lecturer
# depend librarian
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-mathdots-[0-9]*:../../print/tex-mathdots
# depend metatex
# depend midnight
DEPENDS+=	tex-mkpattern-[0-9]*:../../print/tex-mkpattern
# depend modulus
DEPENDS+=	tex-multido>=1.42:../../devel/tex-multido
# depend navigator
DEPENDS+=	tex-newsletr-[0-9]*:../../print/tex-newsletr
# depend ofs
# depend olsak-misc
DEPENDS+=	tex-path>=3.05:../../print/tex-path
# depend pdf-trans
DEPENDS+=	tex-pitex-[0-9]*:../../print/tex-pitex
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
# depend plainpkg
DEPENDS+=	tex-plipsum-[0-9]*:../../print/tex-plipsum
DEPENDS+=	tex-plnfss-[0-9]*:../../print/tex-plnfss
DEPENDS+=	tex-plstmary-[0-9]*:../../print/tex-plstmary
DEPENDS+=	tex-present-[0-9]*:../../print/tex-present
# depend randomlist
DEPENDS+=	tex-resumemac-[0-9]*:../../print/tex-resumemac
# depend schemata
# depend shade
# depend simplekv
# depend systeme
# depend tabto-generic
# depend termmenu
DEPENDS+=	tex-tex-ps>=2010:../../graphics/tex-tex-ps
DEPENDS+=	tex-tex4ht-[0-9]*:../../print/tex-tex4ht
# depend texapi
# depend texdate
DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
DEPENDS+=	tex-timetable-[0-9]*:../../print/tex-timetable
DEPENDS+=	tex-tracklang-[0-9]*:../../print/tex-tracklang
DEPENDS+=	tex-treetex-[0-9]*:../../print/tex-treetex
# depend trigonometry
DEPENDS+=	tex-ulem>=2013:../../print/tex-ulem
# depend upca
DEPENDS+=	tex-varisize-[0-9]*:../../print/tex-varisize
# xii is a "fun" package and the only files are in tex-xii-doc
# depend xii-lat
#DEPENDS+=	tex-xii-[0-9]*:../../print/tex-xii
# depend xlop
# depend yax

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
