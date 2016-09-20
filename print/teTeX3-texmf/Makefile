# $NetBSD: Makefile,v 1.81 2016/09/20 13:21:23 markd Exp $

DISTNAME=	tetex-texmf-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
PKGREVISION=	57
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=obsolete/systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

CONFLICTS+=	teTeX-share-[0-9]*
DEPENDS+=	tex-SIunits-[0-9]*:../../print/tex-SIunits
DEPENDS+=	tex-a4wide-[0-9]*:../../print/tex-a4wide
DEPENDS+=	tex-a5comb-[0-9]*:../../print/tex-a5comb
DEPENDS+=	tex-abstract-[0-9]*:../../print/tex-abstract
DEPENDS+=	tex-acromake-[0-9]*:../../print/tex-acromake
DEPENDS+=	tex-acronym-[0-9]*:../../print/tex-acronym
DEPENDS+=	tex-adrconv-[0-9]*:../../print/tex-adrconv
DEPENDS+=	tex-advdate-[0-9]*:../../print/tex-advdate
DEPENDS+=	tex-aeguill-[0-9]*:../../print/tex-aeguill
DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-amstex-[0-9]*:../../print/tex-amstex
DEPENDS+=	tex-anonchap-[0-9]*:../../print/tex-anonchap
DEPENDS+=	tex-antt-[0-9]*:../../fonts/tex-antt
DEPENDS+=	tex-anysize-[0-9]*:../../print/tex-anysize
DEPENDS+=	tex-appendix-[0-9]*:../../print/tex-appendix
DEPENDS+=	tex-bbm-[0-9]*:../../fonts/tex-bbm
DEPENDS+=	tex-bbm-macros-[0-9]*:../../print/tex-bbm-macros
DEPENDS+=	tex-bbold-[0-9]*:../../fonts/tex-bbold
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer
DEPENDS+=	tex-belleek-[0-9]*:../../fonts/tex-belleek
DEPENDS+=	tex-bezos-[0-9]*:../../print/tex-bezos
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-bibtopic-[0-9]*:../../print/tex-bibtopic
DEPENDS+=	tex-bibunits-[0-9]*:../../print/tex-bibunits
DEPENDS+=	tex-block-[0-9]*:../../print/tex-block
DEPENDS+=	tex-bold-extra-[0-9]*:../../print/tex-bold-extra
DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
DEPENDS+=	tex-boxedminipage-[0-9]*:../../print/tex-boxedminipage
DEPENDS+=	tex-braket-[0-9]*:../../print/tex-braket
DEPENDS+=	tex-breakcites-[0-9]*:../../print/tex-breakcites
DEPENDS+=	tex-breqn-[0-9]*:../../print/tex-breqn
DEPENDS+=	tex-calrsfs-[0-9]*:../../print/tex-calrsfs
DEPENDS+=	tex-cancel-[0-9]*:../../print/tex-cancel
DEPENDS+=	tex-capt-of-[0-9]*:../../print/tex-capt-of
DEPENDS+=	tex-captdef-[0-9]*:../../print/tex-captdef
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-cases-[0-9]*:../../print/tex-cases
DEPENDS+=	tex-cbfonts-[0-9]*:../../fonts/tex-cbfonts
DEPENDS+=	tex-cbfonts-fd-[0-9]*:../../fonts/tex-cbfonts-fd
DEPENDS+=	tex-cc-pl-[0-9]*:../../fonts/tex-cc-pl
DEPENDS+=	tex-ccaption-[0-9]*:../../print/tex-ccaption
DEPENDS+=	tex-ccfonts-[0-9]*:../../fonts/tex-ccfonts
DEPENDS+=	tex-changebar-[0-9]*:../../print/tex-changebar
DEPENDS+=	tex-changepage-[0-9]*:../../print/tex-changepage
DEPENDS+=	tex-chappg-[0-9]*:../../print/tex-chappg
DEPENDS+=	tex-chbibref-[0-9]*:../../print/tex-chbibref
DEPENDS+=	tex-chngcntr-[0-9]*:../../print/tex-chngcntr
DEPENDS+=	tex-circle-[0-9]*:../../print/tex-circle
DEPENDS+=	tex-cite-[0-9]*:../../print/tex-cite
DEPENDS+=	tex-cmap-[0-9]*:../../print/tex-cmap
DEPENDS+=	tex-cmbright-[0-9]*:../../fonts/tex-cmbright
DEPENDS+=	tex-cmcyr>=2009:../../fonts/tex-cmcyr
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-comment-[0-9]*:../../print/tex-comment
DEPENDS+=	tex-concmath-[0-9]*:../../fonts/tex-concmath
DEPENDS+=	tex-concmath-fonts-[0-9]*:../../fonts/tex-concmath-fonts
DEPENDS+=	tex-concrete-[0-9]*:../../fonts/tex-concrete
DEPENDS+=	tex-context>=2009:../../print/tex-context
DEPENDS+=	tex-crop-[0-9]*:../../print/tex-crop
DEPENDS+=	tex-cs-[0-9]*:../../fonts/tex-cs
DEPENDS+=	tex-cslatex-[0-9]*:../../print/tex-cslatex
DEPENDS+=	tex-csplain-[0-9]*:../../print/tex-csplain
DEPENDS+=	tex-currvita-[0-9]*:../../print/tex-currvita
DEPENDS+=	tex-curves-[0-9]*:../../print/tex-curves
DEPENDS+=	tex-custom-bib-[0-9]*:../../print/tex-custom-bib
DEPENDS+=	tex-cweb-[0-9]*:../../print/tex-cweb
DEPENDS+=	tex-cyrillic>=2009:../../print/tex-cyrillic
DEPENDS+=	tex-cyrplain-[0-9]*:../../print/tex-cyrplain
DEPENDS+=	tex-dblfloatfix-[0-9]*:../../print/tex-dblfloatfix
DEPENDS+=	tex-dinbrief-[0-9]*:../../print/tex-dinbrief
DEPENDS+=	tex-dk-bib-[0-9]*:../../print/tex-dk-bib
DEPENDS+=	tex-doublestroke>=1.0:../../fonts/tex-doublestroke
DEPENDS+=	tex-draftcopy-[0-9]*:../../print/tex-draftcopy
DEPENDS+=	tex-ec>=1.0:../../fonts/tex-ec
DEPENDS+=	tex-ecc>=1.0:../../fonts/tex-ecc
DEPENDS+=	tex-eepic>=1.1e:../../graphics/tex-eepic
DEPENDS+=	tex-endfloat-[0-9]*:../../print/tex-endfloat
DEPENDS+=	tex-eijkhout-[0-9]*:../../print/tex-eijkhout
DEPENDS+=	tex-endnotes-[0-9]*:../../print/tex-endnotes
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-eplain-[0-9]*:../../print/tex-eplain
DEPENDS+=	tex-esint-[0-9]*:../../fonts/tex-esint
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-ethiop-[0-9]*:../../print/tex-ethiop
DEPENDS+=	tex-eulervm-[0-9]*:../../fonts/tex-eulervm
DEPENDS+=	tex-euxm-[0-9]*:../../fonts/tex-euxm
DEPENDS+=	tex-exam-[0-9]*:../../print/tex-exam
DEPENDS+=	tex-excludeonly-[0-9]*:../../print/tex-excludeonly
DEPENDS+=	tex-extsizes-[0-9]*:../../print/tex-extsizes
DEPENDS+=	tex-fancybox-[0-9]*:../../print/tex-fancybox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-filecontents-[0-9]*:../../print/tex-filecontents
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-floatflt-[0-9]*:../../print/tex-floatflt
DEPENDS+=	tex-fncylab-[0-9]*:../../print/tex-fncylab
DEPENDS+=	tex-fnpara-[0-9]*:../../print/tex-fnpara
DEPENDS+=	tex-fontinst-[0-9]*:../../fonts/tex-fontinst
DEPENDS+=	tex-footbib-[0-9]*:../../print/tex-footbib
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-footnpag-[0-9]*:../../print/tex-footnpag
DEPENDS+=	tex-fp-[0-9]*:../../math/tex-fp
DEPENDS+=	tex-framed-[0-9]*:../../print/tex-framed
DEPENDS+=	tex-ftcap-[0-9]*:../../print/tex-ftcap
DEPENDS+=	tex-fwlw-[0-9]*:../../print/tex-fwlw
DEPENDS+=	tex-g-brief-[0-9]*:../../print/tex-g-brief
DEPENDS+=	tex-genmisc-[0-9]*:../../print/tex-genmisc
DEPENDS+=	tex-germbib-[0-9]*:../../print/tex-germbib
DEPENDS+=	tex-gothic-[0-9]*:../../fonts/tex-gothic
DEPENDS+=	tex-graphics-pln-[0-9]*:../../graphics/tex-graphics-pln
DEPENDS+=	tex-greek-inputenc-[0-9]*:../../print/tex-greek-inputenc
DEPENDS+=	tex-gustlib-[0-9]*:../../print/tex-gustlib
DEPENDS+=	tex-hypernat-[0-9]*:../../print/tex-hypernat
DEPENDS+=	tex-hyphen-basque-[0-9]*:../../print/tex-hyphen-basque
DEPENDS+=	tex-hyphen-bulgarian-[0-9]*:../../print/tex-hyphen-bulgarian
DEPENDS+=	tex-hyphen-catalan-[0-9]*:../../print/tex-hyphen-catalan
DEPENDS+=	tex-hyphen-croatian-[0-9]*:../../print/tex-hyphen-croatian
DEPENDS+=	tex-hyphen-czech-[0-9]*:../../print/tex-hyphen-czech
DEPENDS+=	tex-hyphen-danish-[0-9]*:../../print/tex-hyphen-danish
DEPENDS+=	tex-hyphen-dutch-[0-9]*:../../print/tex-hyphen-dutch
DEPENDS+=	tex-hyphen-esperanto-[0-9]*:../../print/tex-hyphen-esperanto
DEPENDS+=	tex-hyphen-estonian-[0-9]*:../../print/tex-hyphen-estonian
DEPENDS+=	tex-hyphen-finnish-[0-9]*:../../print/tex-hyphen-finnish
DEPENDS+=	tex-hyphen-french-[0-9]*:../../print/tex-hyphen-french
DEPENDS+=	tex-hyphen-german-[0-9]*:../../print/tex-hyphen-german
DEPENDS+=	tex-hyphen-greek-[0-9]*:../../print/tex-hyphen-greek
DEPENDS+=	tex-hyphen-hungarian-[0-9]*:../../print/tex-hyphen-hungarian
DEPENDS+=	tex-hyphen-icelandic-[0-9]*:../../print/tex-hyphen-icelandic
DEPENDS+=	tex-hyphen-indonesian-[0-9]*:../../print/tex-hyphen-indonesian
DEPENDS+=	tex-hyphen-irish-[0-9]*:../../print/tex-hyphen-irish
DEPENDS+=	tex-hyphen-italian-[0-9]*:../../print/tex-hyphen-italian
DEPENDS+=	tex-hyphen-latin-[0-9]*:../../print/tex-hyphen-latin
DEPENDS+=	tex-hyphen-norwegian-[0-9]*:../../print/tex-hyphen-norwegian
DEPENDS+=	tex-hyphen-polish-[0-9]*:../../print/tex-hyphen-polish
DEPENDS+=	tex-hyphen-portuguese-[0-9]*:../../print/tex-hyphen-portuguese
DEPENDS+=	tex-hyphen-romanian-[0-9]*:../../print/tex-hyphen-romanian
DEPENDS+=	tex-hyphen-russian-[0-9]*:../../print/tex-hyphen-russian
DEPENDS+=	tex-hyphen-serbian-[0-9]*:../../print/tex-hyphen-serbian
DEPENDS+=	tex-hyphen-slovak-[0-9]*:../../print/tex-hyphen-slovak
DEPENDS+=	tex-hyphen-slovenian-[0-9]*:../../print/tex-hyphen-slovenian
DEPENDS+=	tex-hyphen-spanish-[0-9]*:../../print/tex-hyphen-spanish
DEPENDS+=	tex-hyphen-swedish-[0-9]*:../../print/tex-hyphen-swedish
DEPENDS+=	tex-hyphen-turkish-[0-9]*:../../print/tex-hyphen-turkish
DEPENDS+=	tex-hyphen-ukrainian-[0-9]*:../../print/tex-hyphen-ukrainian
DEPENDS+=	tex-hyphenat-[0-9]*:../../print/tex-hyphenat
DEPENDS+=	tex-ifmtarg-[0-9]*:../../print/tex-ifmtarg
DEPENDS+=	tex-import-[0-9]*:../../print/tex-import
DEPENDS+=	tex-index-[0-9]*:../../print/tex-index
DEPENDS+=	tex-jknapltx-[0-9]*:../../print/tex-jknapltx
DEPENDS+=	tex-jurabib-[0-9]*:../../print/tex-jurabib
DEPENDS+=	tex-kix-[0-9]*:../../print/tex-kix
DEPENDS+=	tex-knuth-doc-[0-9]*:../../print/tex-knuth-doc
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-labels-[0-9]*:../../print/tex-labels
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
DEPENDS+=	tex-lastpage-[0-9]*:../../print/tex-lastpage
DEPENDS+=	tex-layouts-[0-9]*:../../print/tex-layouts
DEPENDS+=	tex-leftidx-[0-9]*:../../print/tex-leftidx
DEPENDS+=	tex-lettrine-[0-9]*:../../print/tex-lettrine
DEPENDS+=	tex-lh>=3.5g:../../fonts/tex-lh
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-listing-[0-9]*:../../print/tex-listing
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-localloc-[0-9]*:../../print/tex-localloc
DEPENDS+=	tex-ltabptch-[0-9]*:../../print/tex-ltabptch
DEPENDS+=	tex-ly1-[0-9]*:../../fonts/tex-ly1
DEPENDS+=	tex-magaz-[0-9]*:../../print/tex-magaz
DEPENDS+=	tex-manfnt-[0-9]*:../../fonts/tex-manfnt
DEPENDS+=	tex-mathcomp-[0-9]*:../../print/tex-mathcomp
DEPENDS+=	tex-mathpazo-[0-9]*:../../fonts/tex-mathpazo
DEPENDS+=	tex-mathtools-[0-9]*:../../print/tex-mathtools
DEPENDS+=	tex-mdwtools-[0-9]*:../../print/tex-mdwtools
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-metapost-[0-9]*:../../graphics/tex-metapost
DEPENDS+=	tex-mex-[0-9]*:../../print/tex-mex
DEPENDS+=	tex-mfpic-[0-9]*:../../graphics/tex-mfpic
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-midpage-[0-9]*:../../print/tex-midpage
DEPENDS+=	tex-misc209-[0-9]*:../../print/tex-misc209
DEPENDS+=	tex-mltex-[0-9]*:../../print/tex-mltex
DEPENDS+=	tex-moreverb-[0-9]*:../../print/tex-moreverb
DEPENDS+=	tex-mparhack-[0-9]*:../../print/tex-mparhack
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-multibib-[0-9]*:../../print/tex-multibib
DEPENDS+=	tex-multirow-[0-9]*:../../print/tex-multirow
DEPENDS+=	tex-mwcls-[0-9]*:../../print/tex-mwcls
DEPENDS+=	tex-needspace-[0-9]*:../../print/tex-needspace
DEPENDS+=	tex-nextpage-[0-9]*:../../print/tex-nextpage
DEPENDS+=	tex-nomencl-[0-9]*:../../print/tex-nomencl
DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass
DEPENDS+=	tex-ntheorem-[0-9]*:../../print/tex-ntheorem
DEPENDS+=	tex-ocherokee-[0-9]*:../../fonts/tex-ocherokee
DEPENDS+=	tex-oinuit-[0-9]*:../../print/tex-oinuit
DEPENDS+=	tex-omega-[0-9]*:../../print/tex-omega
DEPENDS+=	tex-onlyamsmath-[0-9]*:../../print/tex-onlyamsmath
DEPENDS+=	tex-otibet-[0-9]*:../../print/tex-otibet
DEPENDS+=	tex-oubraces-[0-9]*:../../print/tex-oubraces
DEPENDS+=	tex-overpic-[0-9]*:../../print/tex-overpic
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-pb-diagram-[0-9]*:../../print/tex-pb-diagram
DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages
DEPENDS+=	tex-picinpar-[0-9]*:../../print/tex-picinpar
DEPENDS+=	tex-pict2e-[0-9]*:../../print/tex-pict2e
DEPENDS+=	tex-pictex-[0-9]*:../../graphics/tex-pictex
DEPENDS+=	tex-pl-[0-9]*:../../fonts/tex-pl
DEPENDS+=	tex-placeins-[0-9]*:../../print/tex-placeins
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
DEPENDS+=	tex-polski-[0-9]*:../../print/tex-polski
DEPENDS+=	tex-poltawski-[0-9]*:../../print/tex-poltawski
DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
DEPENDS+=	tex-preview-[0-9]*:../../print/tex-preview
DEPENDS+=	tex-printlen-[0-9]*:../../print/tex-printlen
DEPENDS+=	tex-program-[0-9]*:../../print/tex-program
DEPENDS+=	tex-psfrag-[0-9]*:../../print/tex-psfrag
DEPENDS+=	tex-psgo-[0-9]*:../../graphics/tex-psgo
DEPENDS+=	tex-pst-3d-[0-9]*:../../graphics/tex-pst-3d
DEPENDS+=	tex-pst-3dplot-[0-9]*:../../graphics/tex-pst-3dplot
DEPENDS+=	tex-pst-blur-[0-9]*:../../graphics/tex-pst-blur
DEPENDS+=	tex-pst-circ-[0-9]*:../../graphics/tex-pst-circ
DEPENDS+=	tex-pst-coil-[0-9]*:../../graphics/tex-pst-coil
DEPENDS+=	tex-pst-eps-[0-9]*:../../graphics/tex-pst-eps
DEPENDS+=	tex-pst-fill-[0-9]*:../../graphics/tex-pst-fill
DEPENDS+=	tex-pst-geo-[0-9]*:../../geography/tex-pst-geo
DEPENDS+=	tex-pst-ghsb-[0-9]*:../../graphics/tex-pst-ghsb
DEPENDS+=	tex-pst-gr3d-[0-9]*:../../graphics/tex-pst-gr3d
DEPENDS+=	tex-pst-grad-[0-9]*:../../graphics/tex-pst-grad
DEPENDS+=	tex-pst-lens-[0-9]*:../../graphics/tex-pst-lens
DEPENDS+=	tex-pst-math-[0-9]*:../../graphics/tex-pst-math
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pst-osci-[0-9]*:../../graphics/tex-pst-osci
DEPENDS+=	tex-pst-plot-[0-9]*:../../graphics/tex-pst-plot
DEPENDS+=	tex-pst-poly-[0-9]*:../../graphics/tex-pst-poly
DEPENDS+=	tex-pst-slpe-[0-9]*:../../graphics/tex-pst-slpe
DEPENDS+=	tex-pst-text-[0-9]*:../../graphics/tex-pst-text
DEPENDS+=	tex-pst-tree-[0-9]*:../../graphics/tex-pst-tree
DEPENDS+=	tex-pst-uml-[0-9]*:../../devel/tex-pst-uml
DEPENDS+=	tex-pst-vue3d-[0-9]*:../../graphics/tex-pst-vue3d
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-pstricks-add-[0-9]*:../../graphics/tex-pstricks-add
DEPENDS+=	tex-qpxqtx-[0-9]*:../../fonts/tex-qpxqtx
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize
DEPENDS+=	tex-revtex4-[0-9]*:../../print/tex-revtex4
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-rotfloat-[0-9]*:../../print/tex-rotfloat
DEPENDS+=	tex-sansmath-[0-9]*:../../print/tex-sansmath
DEPENDS+=	tex-sauter-[0-9]*:../../fonts/tex-sauter
DEPENDS+=	tex-scale-[0-9]*:../../print/tex-scale
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-selectp-[0-9]*:../../print/tex-selectp
DEPENDS+=	tex-seminar-[0-9]*:../../print/tex-seminar
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-shapepar-[0-9]*:../../print/tex-shapepar
DEPENDS+=	tex-showdim-[0-9]*:../../print/tex-showdim
DEPENDS+=	tex-showlabels-[0-9]*:../../print/tex-showlabels
DEPENDS+=	tex-sidecap-[0-9]*:../../print/tex-sidecap
DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul
DEPENDS+=	tex-stdclsdv-[0-9]*:../../print/tex-stdclsdv
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
DEPENDS+=	tex-subfig-[0-9]*:../../print/tex-subfig
DEPENDS+=	tex-subfigure-[0-9]*:../../print/tex-subfigure
DEPENDS+=	tex-supertabular-[0-9]*:../../print/tex-supertabular
DEPENDS+=	tex-t2-[0-9]*:../../print/tex-t2
DEPENDS+=	tex-tabls-[0-9]*:../../print/tex-tabls
DEPENDS+=	tex-tap-[0-9]*:../../print/tex-tap
DEPENDS+=	tex-tex-gyre-[0-9]*:../../fonts/tex-tex-gyre
DEPENDS+=	tex-tex-gyre-math-[0-9]*:../../fonts/tex-tex-gyre-math
DEPENDS+=	tex-texdraw-[0-9]*:../../graphics/tex-texdraw
DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
DEPENDS+=	tex-textfit-[0-9]*:../../print/tex-textfit
DEPENDS+=	tex-textmerg-[0-9]*:../../print/tex-textmerg
DEPENDS+=	tex-textpos-[0-9]*:../../print/tex-textpos
DEPENDS+=	tex-threeparttable-[0-9]*:../../print/tex-threeparttable
DEPENDS+=	tex-thumbpdf-[0-9]*:../../print/tex-thumbpdf
DEPENDS+=	tex-titlesec-[0-9]*:../../print/tex-titlesec
DEPENDS+=	tex-tocbibind-[0-9]*:../../print/tex-tocbibind
DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft
DEPENDS+=	tex-totpages-[0-9]*:../../print/tex-totpages
DEPENDS+=	tex-twoinone-[0-9]*:../../print/tex-twoinone
DEPENDS+=	tex-type1cm-[0-9]*:../../print/tex-type1cm
DEPENDS+=	tex-umlaute-[0-9]*:../../print/tex-umlaute
DEPENDS+=	tex-units-[0-9]*:../../print/tex-units
DEPENDS+=	tex-upquote-[0-9]*:../../print/tex-upquote
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-utf8mex-[0-9]*:../../print/tex-utf8mex
DEPENDS+=	tex-verbdef-[0-9]*:../../print/tex-verbdef
DEPENDS+=	tex-version-[0-9]*:../../print/tex-version
DEPENDS+=	tex-vertbars-[0-9]*:../../print/tex-vertbars
DEPENDS+=	tex-vmargin-[0-9]*:../../print/tex-vmargin
DEPENDS+=	tex-vntex-[0-9]*:../../print/tex-vntex
DEPENDS+=	tex-vruler-[0-9]*:../../print/tex-vruler
DEPENDS+=	tex-was-[0-9]*:../../print/tex-was
DEPENDS+=	tex-wrapfig-[0-9]*:../../print/tex-wrapfig
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xtab-[0-9]*:../../print/tex-xtab
DEPENDS+=	tex-xypic-[0-9]*:../../graphics/tex-xypic
DEPENDS+=	tex-yfonts-[0-9]*:../../print/tex-yfonts
DEPENDS+=	texlive-collection-fontsrecommended>=2010:../../meta-pkgs/texlive-collection-fontsrecommended
DEPENDS+=	texlive-collection-genericrecommended>=2010:../../meta-pkgs/texlive-collection-genericrecommended
DEPENDS+=	texlive-collection-latex>=2010:../../meta-pkgs/texlive-collection-latex

EXTRACT_ELEMENTS+=	bibtex
EXTRACT_ELEMENTS+=	fonts
#EXTRACT_ELEMENTS+=	scripts
EXTRACT_ELEMENTS+=	tex

WRKSRC=		${WRKDIR}/tetex
EXTRACT_DIR=	${WRKSRC}
NO_BUILD=	yes

USE_TOOLS+=	sh:run pax

INSTALLATION_DIRS+=	share/texmf-dist

TEX_MAP_FILES+=		mathpple.map

.include "../../print/kpathsea/texmf.mk"
.include "../../print/tex-tetex/map.mk"

post-extract:
	rm -f ${WRKSRC}/ls-R
	rm -rf ${WRKSRC}/bibtex/bib
	rm -rf ${WRKSRC}/bibtex/bst/[a-m]*
	rm -rf ${WRKSRC}/bibtex/bst/natbib
	rm -rf ${WRKSRC}/bibtex/bst/[p-z]*
	rm -rf ${WRKSRC}/fonts/afm/[a-x]*
	rm -rf ${WRKSRC}/fonts/[clop]*
	rm -rf ${WRKSRC}/fonts/enc/dvipdfm
	rm -rf ${WRKSRC}/fonts/enc/dvips/[abcd-oq-z]*
	rm -rf ${WRKSRC}/fonts/enc/dvips/pl
	rm -rf ${WRKSRC}/fonts/map/dvipdfm
	rm -rf ${WRKSRC}/fonts/map/dvips/[abcd-knoq-sv-z]*
	rm -rf ${WRKSRC}/fonts/map/dvips/lm
	rm -rf ${WRKSRC}/fonts/map/dvips/misc/cmcyr.map
	rm -rf ${WRKSRC}/fonts/map/dvips/misc/[d-o]*
	rm -rf ${WRKSRC}/fonts/map/dvips/pl
	rm -rf ${WRKSRC}/fonts/map/dvips/psnfss
	rm -rf ${WRKSRC}/fonts/map/dvips/tetex/[abd-km-z]*.map
	-rmdir ${WRKSRC}/fonts/map/dvips/updmap
	rm -rf ${WRKSRC}/fonts/map/dvips/urwvn
	rm -rf ${WRKSRC}/fonts/map/fontname
	-rmdir ${WRKSRC}/fonts/map/pdftex/updmap
	-rmdir ${WRKSRC}/fonts/misc
	-rmdir ${WRKSRC}/fonts/sfd
	rm -rf ${WRKSRC}/fonts/source/ams
	rm -rf ${WRKSRC}/fonts/source/jknappen/[a-s]*
	rm -rf ${WRKSRC}/fonts/source/lh
	rm -rf ${WRKSRC}/fonts/source/public/[abd-ln-uw-z]*
	rm -rf ${WRKSRC}/fonts/source/public/cbgreek
	rm -rf ${WRKSRC}/fonts/source/public/cc-pl
	rm -rf ${WRKSRC}/fonts/source/public/cm
	rm -rf ${WRKSRC}/fonts/source/public/cmbright
	rm -rf ${WRKSRC}/fonts/source/public/cmextra
	rm -rf ${WRKSRC}/fonts/source/public/concmath
	rm -rf ${WRKSRC}/fonts/source/public/concrete
	rm -rf ${WRKSRC}/fonts/source/public/cs
	rm -rf ${WRKSRC}/fonts/source/public/mflogo
	rm -f ${WRKSRC}/fonts/source/public/misc/[0-9a-wyz]*.mf
	rm -rf ${WRKSRC}/fonts/source/public/vnr
	rm -rf ${WRKSRC}/fonts/tfm/adobe/[a-ln-z]*
	rm -rf ${WRKSRC}/fonts/tfm/ams
	rm -rf ${WRKSRC}/fonts/tfm/bitstrea
	rm -rf ${WRKSRC}/fonts/tfm/bitstrea
	rm -rf ${WRKSRC}/fonts/tfm/cg/cou*
	rm -rf ${WRKSRC}/fonts/tfm/cg/[h-kp-s]*
	rm -rf ${WRKSRC}/fonts/tfm/cg/times
	rm -rf ${WRKSRC}/fonts/tfm/[d-o]*
	rm -rf ${WRKSRC}/fonts/tfm/public/[abd-ln-pr-tw-z]*
	rm -rf ${WRKSRC}/fonts/tfm/public/cc-pl
	rm -rf ${WRKSRC}/fonts/tfm/public/cm
	rm -rf ${WRKSRC}/fonts/tfm/public/cmbright
	rm -rf ${WRKSRC}/fonts/tfm/public/cm[c-z]*
	rm -rf ${WRKSRC}/fonts/tfm/public/concmath
	rm -rf ${WRKSRC}/fonts/tfm/public/concrete
	rm -rf ${WRKSRC}/fonts/tfm/public/cs
	rm -rf ${WRKSRC}/fonts/tfm/public/marvosym
	rm -rf ${WRKSRC}/fonts/tfm/public/mflogo
	rm -f ${WRKSRC}/fonts/tfm/public/misc/[b-q]*.tfm
	rm -rf ${WRKSRC}/fonts/tfm/public/q*
	rm -rf ${WRKSRC}/fonts/tfm/public/urwvn
	rm -rf ${WRKSRC}/fonts/tfm/public/vnr
	rm -rf ${WRKSRC}/fonts/tfm/yandy/times
	-rmdir ${WRKSRC}/fonts/truetype
	rm -rf ${WRKSRC}/fonts/type1/[a-oq-z]*
	rm -rf ${WRKSRC}/fonts/type1/public/[abd-tw-z]*
	rm -rf ${WRKSRC}/fonts/type1/public/cc-pl
	rm -rf ${WRKSRC}/fonts/type1/public/cmcyr
	rm -rf ${WRKSRC}/fonts/type1/public/cs
	rm -rf ${WRKSRC}/fonts/type1/public/urwvn
	rm -rf ${WRKSRC}/fonts/type1/public/vnr
	-rmdir ${WRKSRC}/fonts/type3
	-rmdir ${WRKSRC}/fonts/type42
	rm -rf ${WRKSRC}/fonts/vf/adobe/[a-ln-z]*
	rm -rf ${WRKSRC}/fonts/vf/bitstrea
	rm -rf ${WRKSRC}/fonts/vf/public
	rm -rf ${WRKSRC}/fonts/vf/cg/cou*
	rm -rf ${WRKSRC}/fonts/vf/cg/[h-k]*
	rm -rf ${WRKSRC}/fonts/vf/cg/times
	rm -rf ${WRKSRC}/fonts/vf/yandy/times
	rm -rf ${WRKSRC}/tex/amstex
	rm -rf ${WRKSRC}/tex/context
	rm -rf ${WRKSRC}/tex/cslatex
	rm -rf ${WRKSRC}/tex/csplain
	rm -rf ${WRKSRC}/tex/cyrplain
	rm -rf ${WRKSRC}/tex/eplain
	rm -rf ${WRKSRC}/tex/fontinst
	rm -rf ${WRKSRC}/tex/generic/[abdf-km-pu-z]*
	rm -rf ${WRKSRC}/tex/generic/con*
	rm -rf ${WRKSRC}/tex/generic/csplain
	rm -rf ${WRKSRC}/tex/generic/eijkhout
	rm -rf ${WRKSRC}/tex/generic/enctex
	rm -rf ${WRKSRC}/tex/generic/encodings
	rm -rf ${WRKSRC}/tex/generic/epsf
	rm -rf ${WRKSRC}/tex/generic/localloc
	rm -rf ${WRKSRC}/tex/generic/q*
	rm -rf ${WRKSRC}/tex/generic/random
	rm -rf ${WRKSRC}/tex/generic/ruhyphen
	rm -rf ${WRKSRC}/tex/generic/tap
	rm -rf ${WRKSRC}/tex/generic/tex-ps
	rm -rf ${WRKSRC}/tex/generic/texdraw
	rm -rf ${WRKSRC}/tex/generic/texnames
	rm -rf ${WRKSRC}/tex/generic/thumbpdf
	rm -rf ${WRKSRC}/tex/lambda
	rm -rf ${WRKSRC}/tex/latex/SIunits
	rm -rf ${WRKSRC}/tex/latex/a*
	rm -rf ${WRKSRC}/tex/latex/base
	rm -rf ${WRKSRC}/tex/latex/b[b-z]*
	rm -rf ${WRKSRC}/tex/latex/c[a-h]*
	rm -rf ${WRKSRC}/tex/latex/cite
	rm -rf ${WRKSRC}/tex/latex/c[m-r]*
	rm -rf ${WRKSRC}/tex/latex/cslatex
	rm -rf ${WRKSRC}/tex/latex/currvita
	rm -rf ${WRKSRC}/tex/latex/curves
	rm -rf ${WRKSRC}/tex/latex/custom-bib
	rm -rf ${WRKSRC}/tex/latex/c[v-z]*
	rm -rf ${WRKSRC}/tex/latex/d[a-u]*
	rm -rf ${WRKSRC}/tex/latex/dvipdfm
	rm -rf ${WRKSRC}/tex/latex/e[d-n]*
	rm -rf ${WRKSRC}/tex/latex/e[s-x]*
	rm -rf ${WRKSRC}/tex/latex/f[a-f]*
	rm -rf ${WRKSRC}/tex/latex/f[h-z]*
	rm -rf ${WRKSRC}/tex/latex/g-brief
	rm -rf ${WRKSRC}/tex/latex/germbib
	rm -rf ${WRKSRC}/tex/latex/geo*
	rm -rf ${WRKSRC}/tex/latex/graphics
	rm -rf ${WRKSRC}/tex/latex/greek
	rm -rf ${WRKSRC}/tex/latex/h*
	rm -rf ${WRKSRC}/tex/latex/i*
	rm -rf ${WRKSRC}/tex/latex/j*
	rm -rf ${WRKSRC}/tex/latex/k*
	rm -rf ${WRKSRC}/tex/latex/l[a-t]*
	rm -rf ${WRKSRC}/tex/latex/marvosym
	rm -rf ${WRKSRC}/tex/latex/mathcomp
	rm -rf ${WRKSRC}/tex/latex/m[b-p]*
	rm -rf ${WRKSRC}/tex/latex/ms
	rm -rf ${WRKSRC}/tex/latex/multibib
	rm -rf ${WRKSRC}/tex/latex/multind
	rm -rf ${WRKSRC}/tex/latex/multirow
	rm -rf ${WRKSRC}/tex/latex/mwcls
	rm -rf ${WRKSRC}/tex/latex/n[a-s]*
	rm -rf ${WRKSRC}/tex/latex/ntgclass
	rm -rf ${WRKSRC}/tex/latex/ntheorem
	rm -rf ${WRKSRC}/tex/latex/o*
	rm -rf ${WRKSRC}/tex/latex/par*
	rm -rf ${WRKSRC}/tex/latex/p[b-g]*
	rm -rf ${WRKSRC}/tex/latex/picinpar
	rm -rf ${WRKSRC}/tex/latex/pict2e
	rm -rf ${WRKSRC}/tex/latex/placeins
	rm -rf ${WRKSRC}/tex/latex/platex
	rm -rf ${WRKSRC}/tex/latex/portland
	rm -rf ${WRKSRC}/tex/latex/pr*
	rm -rf ${WRKSRC}/tex/latex/ps[b-z]*
	rm -rf ${WRKSRC}/tex/latex/pxfonts
	rm -rf ${WRKSRC}/tex/latex/qfonts
	rm -rf ${WRKSRC}/tex/latex/r*
	rm -rf ${WRKSRC}/tex/latex/s[a-k]*
	rm -rf ${WRKSRC}/tex/latex/s[m-z]*
	rm -rf ${WRKSRC}/tex/latex/t2
	rm -rf ${WRKSRC}/tex/latex/tabls
	rm -rf ${WRKSRC}/tex/latex/text*
	rm -rf ${WRKSRC}/tex/latex/t[f-q]*
	rm -rf ${WRKSRC}/tex/latex/t[s-z]*
	rm -rf ${WRKSRC}/tex/latex/u[l-p]*
	rm -rf ${WRKSRC}/tex/latex/url
	rm -rf ${WRKSRC}/tex/latex/urwvn
	rm -rf ${WRKSRC}/tex/latex/version
	rm -rf ${WRKSRC}/tex/latex/vietnam
	rm -rf ${WRKSRC}/tex/latex/vmargin
	rm -rf ${WRKSRC}/tex/latex/w*
	rm -rf ${WRKSRC}/tex/latex/x*
	rm -rf ${WRKSRC}/tex/latex/y*
	rm -rf ${WRKSRC}/tex/mex
	rm -rf ${WRKSRC}/tex/plain/amsfonts
	rm -rf ${WRKSRC}/tex/plain/antt
	rm -f ${WRKSRC}/tex/plain/base/[c-gmp-z]*
	rm -f ${WRKSRC}/tex/plain/base/letter*
	rm -rf ${WRKSRC}/tex/plain/[c-ln-or-uw-z]*
	rm -rf ${WRKSRC}/tex/plain/mproof
	rm -rf ${WRKSRC}/tex/plain/pdfcolor
	rm -rf ${WRKSRC}/tex/plain/verbatim
	rm -rf ${WRKSRC}/tex/plain/vietnam
	rm -rf ${WRKSRC}/tex/platex
	rm -rf ${WRKSRC}/tex/texinfo

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../mk/bsd.pkg.mk"
