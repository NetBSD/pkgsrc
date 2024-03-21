# $NetBSD: Makefile,v 1.25 2024/03/21 20:00:56 markd Exp $

DISTNAME=	collection-plaingeneric
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	68675

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Plain (La)TeX packages

DEPENDS+=	texlive-collection-basic>=2014:../../meta-pkgs/texlive-collection-basic

# depend abbr
# depend abstyles
# depend advice
DEPENDS+=	tex-apnum>=1.1:../../math/tex-apnum
# depend autoaligne
# depend barr
# depend bitelist
# depend borceux
# depend c-pascal
# depend calcfrac
# depend catcodes
# depend chronosys
# depend collargs
# depend colorsep
DEPENDS+=	tex-compare-[0-9]*:../../print/tex-compare
# depend crossrefenum
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
# depend etoolbox-generic
# depend expex-acro
# depend expkv-bundle
# depend fenixpar
DEPENDS+=	tex-figflow-[0-9]*:../../print/tex-figflow
DEPENDS+=	tex-fixpdfmag-[0-9]*:../../print/tex-fixpdfmag
# depend fltpoint
# depend fntproof
DEPENDS+=	tex-font-change-[0-9]*:../../print/tex-font-change
DEPENDS+=	tex-fontch-[0-9]*:../../print/tex-fontch
DEPENDS+=	tex-fontname>=2013:../../fonts/tex-fontname
# depend gates
DEPENDS+=	tex-getoptk-[0-9]*:../../print/tex-getoptk
DEPENDS+=	tex-gfnotation-[0-9]*:../../print/tex-gfnotation
# depend gobble
DEPENDS+=	tex-graphics-pln-[0-9]*:../../graphics/tex-graphics-pln
# depend gtl
# depend hlist
DEPENDS+=	tex-hyplain-[0-9]*:../../print/tex-hyplain
# depend inputnormalization
# depend insbox
DEPENDS+=	tex-js-misc-[0-9]*:../../print/tex-js-misc
DEPENDS+=	tex-kastrup>=2010:../../math/tex-kastrup
DEPENDS+=	tex-lambda-lists-[0-9]*:../../print/tex-lambda-lists
# depend langcode
# depend lecturer
DEPENDS+=	tex-letterspacing-[0-9]*:../../print/tex-letterspacing
# depend librarian
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-localloc-[0-9]*:../../print/tex-localloc
DEPENDS+=	tex-mathdots-[0-9]*:../../print/tex-mathdots
# depend metatex
# depend midnight
DEPENDS+=	tex-mkpattern-[0-9]*:../../print/tex-mkpattern
# depend mlawriter
# depend modulus
DEPENDS+=	tex-multido>=1.42:../../devel/tex-multido
# depend namedef
# depend navigator
DEPENDS+=	tex-newsletr-[0-9]*:../../print/tex-newsletr
DEPENDS+=	tex-nth-[0-9]*:../../print/tex-nth
# depend ofs
# depend olsak-misc
DEPENDS+=	tex-outerhbox-[0-9]*:../../print/tex-outerhbox
DEPENDS+=	tex-path>=3.05:../../print/tex-path
# depend pdf-trans
# depend pdfmsym
DEPENDS+=	tex-pitex-[0-9]*:../../print/tex-pitex
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
# depend plainpkg
DEPENDS+=	tex-plipsum-[0-9]*:../../print/tex-plipsum
DEPENDS+=	tex-plnfss-[0-9]*:../../print/tex-plnfss
DEPENDS+=	tex-plstmary-[0-9]*:../../print/tex-plstmary
# depend poormanlog
DEPENDS+=	tex-present-[0-9]*:../../print/tex-present
# depend pwebmac
DEPENDS+=	tex-random-[0-9]*:../../print/tex-random
# depend randomlist
DEPENDS+=	tex-resumemac-[0-9]*:../../print/tex-resumemac
DEPENDS+=	tex-ruler-[0-9]*:../../print/tex-ruler
# depend schemata
# depend shade
DEPENDS+=	tex-simplekv-[0-9]*:../../print/tex-simplekv
DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul
DEPENDS+=	tex-swrule-[0-9]*:../../print/tex-swrule
# depend systeme
# depend tabto-generic
# depend termmenu
DEPENDS+=	tex-tex-ps>=2010:../../graphics/tex-tex-ps
DEPENDS+=	tex-tex4ht-[0-9]*:../../print/tex-tex4ht
# depend texapi
# depend texdate
# depend texdimens
DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
DEPENDS+=	tex-timetable-[0-9]*:../../print/tex-timetable
DEPENDS+=	tex-tracklang-[0-9]*:../../print/tex-tracklang
# depend transparent-io
DEPENDS+=	tex-treetex-[0-9]*:../../print/tex-treetex
# depend trigonometry
DEPENDS+=	tex-ulem>=2013:../../print/tex-ulem
# depend upca
DEPENDS+=	tex-varisize-[0-9]*:../../print/tex-varisize
# xii is a "fun" package and the only files are in tex-xii-doc
# depend xii-lat
# depend xintsession
#DEPENDS+=	tex-xii-[0-9]*:../../print/tex-xii
# depend xlop
# depend yax
# depend zztex

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
