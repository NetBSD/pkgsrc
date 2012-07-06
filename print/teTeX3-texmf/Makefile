# $NetBSD: Makefile,v 1.57 2012/07/06 16:22:55 joerg Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
PKGREVISION=	36
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=obsolete/systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

CONFLICTS+=	teTeX-share-[0-9]*
DEPENDS+=	tex-a4wide-[0-9]*:../../print/tex-a4wide
DEPENDS+=	tex-a5comb-[0-9]*:../../print/tex-a5comb
DEPENDS+=	tex-acromake-[0-9]*:../../print/tex-acromake
DEPENDS+=	tex-advdate-[0-9]*:../../print/tex-advdate
DEPENDS+=	tex-anonchap-[0-9]*:../../print/tex-anonchap
DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-bbold-[0-9]*:../../fonts/tex-bbold
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer
DEPENDS+=	tex-bezos-[0-9]*:../../print/tex-bezos
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-bibtopic-[0-9]*:../../print/tex-bibtopic
DEPENDS+=	tex-block-[0-9]*:../../print/tex-block
DEPENDS+=	tex-bold-extra-[0-9]*:../../print/tex-bold-extra
DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
DEPENDS+=	tex-boxedminipage-[0-9]*:../../print/tex-boxedminipage
DEPENDS+=	tex-braket-[0-9]*:../../print/tex-braket
DEPENDS+=	tex-breakcites-[0-9]*:../../print/tex-breakcites
DEPENDS+=	tex-cancel-[0-9]*:../../print/tex-cancel
DEPENDS+=	tex-capt-of-[0-9]*:../../print/tex-capt-of
DEPENDS+=	tex-captdef-[0-9]*:../../print/tex-captdef
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-cases-[0-9]*:../../print/tex-cases
DEPENDS+=	tex-changebar-[0-9]*:../../print/tex-changebar
DEPENDS+=	tex-chbibref-[0-9]*:../../print/tex-chbibref
DEPENDS+=	tex-chngcntr-[0-9]*:../../print/tex-chngcntr
DEPENDS+=	tex-changepage-[0-9]*:../../print/tex-changepage
DEPENDS+=	tex-circle-[0-9]*:../../print/tex-circle
DEPENDS+=	tex-cite-[0-9]*:../../print/tex-cite
DEPENDS+=	tex-cmcyr>=2009:../../fonts/tex-cmcyr
DEPENDS+=	tex-collection-fontsrecommended>=2010:../../fonts/tex-collection-fontsrecommended
DEPENDS+=	tex-collection-genericrecommended>=2010:../../print/tex-collection-genericrecommended
DEPENDS+=	tex-collection-latex>=2010:../../print/tex-collection-latex
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-context>=2009:../../print/tex-context
DEPENDS+=	tex-cweb-[0-9]*:../../print/tex-cweb
DEPENDS+=	tex-cyrillic>=2009:../../print/tex-cyrillic
DEPENDS+=	tex-dblfloatfix-[0-9]*:../../print/tex-dblfloatfix
DEPENDS+=	tex-ec>=1.0:../../fonts/tex-ec
DEPENDS+=	tex-eepic>=1.1e:../../graphics/tex-eepic
DEPENDS+=	tex-endfloat-[0-9]*:../../print/tex-endfloat
DEPENDS+=	tex-endnotes-[0-9]*:../../print/tex-endnotes
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-esint-[0-9]*:../../fonts/tex-esint
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-exam-[0-9]*:../../print/tex-exam
DEPENDS+=	tex-excludeonly-[0-9]*:../../print/tex-excludeonly
DEPENDS+=	tex-extsizes-[0-9]*:../../print/tex-extsizes
DEPENDS+=	tex-fancybox-[0-9]*:../../print/tex-fancybox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-fncylab-[0-9]*:../../print/tex-fncylab
DEPENDS+=	tex-fnpara-[0-9]*:../../print/tex-fnpara
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-fp-[0-9]*:../../math/tex-fp
DEPENDS+=	tex-framed-[0-9]*:../../print/tex-framed
DEPENDS+=	tex-ftcap-[0-9]*:../../print/tex-ftcap
DEPENDS+=	tex-fwlw-[0-9]*:../../print/tex-fwlw
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
DEPENDS+=	tex-jurabib-[0-9]*:../../print/tex-jurabib
DEPENDS+=	tex-kix-[0-9]*:../../print/tex-kix
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
DEPENDS+=	tex-lastpage-[0-9]*:../../print/tex-lastpage
DEPENDS+=	tex-listing-[0-9]*:../../print/tex-listing
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-lh>=3.5g:../../fonts/tex-lh
DEPENDS+=	tex-ly1-[0-9]*:../../fonts/tex-ly1
DEPENDS+=	tex-magaz-[0-9]*:../../print/tex-magaz
DEPENDS+=	tex-manfnt-[0-9]*:../../fonts/tex-manfnt
DEPENDS+=	tex-mdwtools-[0-9]*:../../print/tex-mdwtools
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-metapost-[0-9]*:../../graphics/tex-metapost
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-midpage-[0-9]*:../../print/tex-midpage
DEPENDS+=	tex-moreverb-[0-9]*:../../print/tex-moreverb
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-multirow-[0-9]*:../../print/tex-multirow
DEPENDS+=	tex-needspace-[0-9]*:../../print/tex-needspace
DEPENDS+=	tex-nextpage-[0-9]*:../../print/tex-nextpage
DEPENDS+=	tex-nomencl-[0-9]*:../../print/tex-nomencl
DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass
DEPENDS+=	tex-oubraces-[0-9]*:../../print/tex-oubraces
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages
DEPENDS+=	tex-picinpar-[0-9]*:../../print/tex-picinpar
DEPENDS+=	tex-placeins-[0-9]*:../../print/tex-placeins
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
DEPENDS+=	tex-preview-[0-9]*:../../print/tex-preview
DEPENDS+=	tex-printlen-[0-9]*:../../print/tex-printlen
DEPENDS+=	tex-psgo-[0-9]*:../../graphics/tex-psgo
DEPENDS+=	tex-pst-3d-[0-9]*:../../graphics/tex-pst-3d
DEPENDS+=	tex-pst-3dplot-[0-9]*:../../graphics/tex-pst-3dplot
DEPENDS+=	tex-pst-blur-[0-9]*:../../graphics/tex-pst-blur
DEPENDS+=	tex-pst-circ-[0-9]*:../../graphics/tex-pst-circ
DEPENDS+=	tex-pst-coil-[0-9]*:../../graphics/tex-pst-coil
DEPENDS+=	tex-pst-eps-[0-9]*:../../graphics/tex-pst-eps
DEPENDS+=	tex-pst-fill-[0-9]*:../../graphics/tex-pst-fill
DEPENDS+=	tex-pst-ghsb-[0-9]*:../../graphics/tex-pst-ghsb
DEPENDS+=	tex-pst-gr3d-[0-9]*:../../graphics/tex-pst-gr3d
DEPENDS+=	tex-pst-grad-[0-9]*:../../graphics/tex-pst-grad
DEPENDS+=	tex-pst-geo-[0-9]*:../../geography/tex-pst-geo
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
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-sansmath-[0-9]*:../../print/tex-sansmath
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-selectp-[0-9]*:../../print/tex-selectp
DEPENDS+=	tex-seminar-[0-9]*:../../print/tex-seminar
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
DEPENDS+=	tex-subfigure-[0-9]*:../../print/tex-subfigure
DEPENDS+=	tex-subfig-[0-9]*:../../print/tex-subfig
DEPENDS+=	tex-supertabular-[0-9]*:../../print/tex-supertabular
DEPENDS+=	tex-tabls-[0-9]*:../../print/tex-tabls
DEPENDS+=	tex-t2-[0-9]*:../../print/tex-t2
DEPENDS+=	tex-threeparttable-[0-9]*:../../print/tex-threeparttable
DEPENDS+=	tex-titlesec-[0-9]*:../../print/tex-titlesec
DEPENDS+=	tex-tocbibind-[0-9]*:../../print/tex-tocbibind
DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft
DEPENDS+=	tex-twoinone-[0-9]*:../../print/tex-twoinone
DEPENDS+=	tex-type1cm-[0-9]*:../../print/tex-type1cm
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-verbdef-[0-9]*:../../print/tex-verbdef
DEPENDS+=	tex-version-[0-9]*:../../print/tex-version
DEPENDS+=	tex-vertbars-[0-9]*:../../print/tex-vertbars
DEPENDS+=	tex-vruler-[0-9]*:../../print/tex-vruler
DEPENDS+=	tex-wrapfig-[0-9]*:../../print/tex-wrapfig
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xypic-[0-9]*:../../graphics/tex-xypic

EXTRACT_ELEMENTS+=	aliases
EXTRACT_ELEMENTS+=	bibtex
EXTRACT_ELEMENTS+=	doc
EXTRACT_ELEMENTS+=	dvips
EXTRACT_ELEMENTS+=	fonts
EXTRACT_ELEMENTS+=	metafont
EXTRACT_ELEMENTS+=	metapost
EXTRACT_ELEMENTS+=	mft
EXTRACT_ELEMENTS+=	omega
EXTRACT_ELEMENTS+=	release-tetex-texmf.txt
EXTRACT_ELEMENTS+=	scripts
EXTRACT_ELEMENTS+=	tex

WRKSRC=		${WRKDIR}/tetex
EXTRACT_DIR=	${WRKSRC}
NO_BUILD=	yes

REPLACE_PERL+=	doc/generic/ruhyphen/reduce-patt doc/generic/ruhyphen/sorthyph
# No dependency on Perl.
CHECK_INTERPRETER_SKIP+=share/texmf-dist/doc/generic/ruhyphen/reduce-patt \
			share/texmf-dist/doc/generic/ruhyphen/sorthyph
REPLACE_SH+=	doc/latex/bibunits/bibtexall doc/latex/multibib/bibtexall
USE_TOOLS+=	sh:run pax

INSTALLATION_DIRS+=	share/texmf-dist

TEX_MAP_FILES+=		antp.map
TEX_MAP_FILES+=		cork-antt.map
TEX_MAP_FILES+=		cs-antt.map
TEX_MAP_FILES+=		exp-antt.map
TEX_MAP_FILES+=		greek-antt.map
TEX_MAP_FILES+=		qx-antt.map
TEX_MAP_FILES+=		t2a-antt.map
TEX_MAP_FILES+=		t2b-antt.map
TEX_MAP_FILES+=		t2c-antt.map
TEX_MAP_FILES+=		t5-antt.map
TEX_MAP_FILES+=		texnansi-antt.map
TEX_MAP_FILES+=		wncy-antt.map
TEX_MAP_FILES+=		qbk.map
TEX_MAP_FILES+=		qcr.map
TEX_MAP_FILES+=		qhv.map
TEX_MAP_FILES+=		qpl.map
TEX_MAP_FILES+=		qtm.map
TEX_MAP_FILES+=		qzc.map
TEX_MAP_FILES+=		contnav.map
TEX_MAP_FILES+=		mathpple.map
TEX_MAP_FILES+=		omega.map
TEX_MAP_FILES+=		xypic.map
TEX_MAP_FILES+=		urwvn.map
TEX_MAP_FILES+=		dstroke.map
TEX_MIXEDMAP_FILES+=	cs.map
TEX_MIXEDMAP_FILES+=	pl.map
TEX_MIXEDMAP_FILES+=	ccpl.map
TEX_MIXEDMAP_FILES+=	vnr.map

.include "../../print/kpathsea/texmf.mk"
.include "../../print/tex-tetex/map.mk"

post-extract:
	rm -f ${WRKSRC}/ls-R
	rm -rf ${WRKSRC}/bibtex/bib
	rm -rf ${WRKSRC}/bibtex/bst/ams
	rm -rf ${WRKSRC}/bibtex/bst/[b-c]*
	rm -rf ${WRKSRC}/bibtex/bst/[h-m]*
	rm -rf ${WRKSRC}/bibtex/bst/natbib
	rm -rf ${WRKSRC}/bibtex/bst/plbib
	rm -rf ${WRKSRC}/doc/bibtex/base
	rm -rf ${WRKSRC}/doc/context
	rmdir ${WRKSRC}/doc/generic/pdfcrop
	rm -rf ${WRKSRC}/doc/etex
	rm -rf ${WRKSRC}/doc/fonts/ae*
	rm -rf ${WRKSRC}/doc/fonts/am*
	rm -rf ${WRKSRC}/doc/fonts/cm
	rm -rf ${WRKSRC}/doc/fonts/ec
	rm -rf ${WRKSRC}/doc/fonts/eu*
	rm -rf ${WRKSRC}/doc/fonts/f*
	rm -rf ${WRKSRC}/doc/fonts/l[a-t]*
	rm -rf ${WRKSRC}/doc/fonts/mar*
	rm -rf ${WRKSRC}/doc/fonts/mathp*
	rm -rf ${WRKSRC}/doc/fonts/pxfonts
	rm -rf ${WRKSRC}/doc/fonts/t*
	rm -rf ${WRKSRC}/doc/generic/[a-f]*
	rm -rf ${WRKSRC}/doc/generic/[a-g]*
	rm -rf ${WRKSRC}/doc/generic/multido
	rm -rf ${WRKSRC}/doc/generic/pstricks
	rm -rf ${WRKSRC}/doc/generic/tex-ps
	rm -rf ${WRKSRC}/doc/generic/u*
	rm -rf ${WRKSRC}/doc/generic/x*
	rm -rf ${WRKSRC}/doc/latex/a[f-m]*
	rm -rf ${WRKSRC}/doc/latex/base
	rm -rf ${WRKSRC}/doc/latex/bbold
	rm -rf ${WRKSRC}/doc/latex/be*
	rm -rf ${WRKSRC}/doc/latex/bibtopic
	rm -rf ${WRKSRC}/doc/latex/booktabs
	rm -rf ${WRKSRC}/doc/latex/ca*
	rm -rf ${WRKSRC}/doc/latex/changebar
	rm -rf ${WRKSRC}/doc/latex/c[v-z]*
	rm -rf ${WRKSRC}/doc/latex/e[d-n]*
	rm -rf ${WRKSRC}/doc/latex/eso-pic
	rm -rf ${WRKSRC}/doc/latex/euler
	rm -rf ${WRKSRC}/doc/latex/ex*
	rm -rf ${WRKSRC}/doc/latex/fa*
	rm -rf ${WRKSRC}/doc/latex/float
	rm -rf ${WRKSRC}/doc/latex/footmisc
	rm -rf ${WRKSRC}/doc/latex/fp
	rm -rf ${WRKSRC}/doc/latex/geo*
	rm -rf ${WRKSRC}/doc/latex/h*
	rm -rf ${WRKSRC}/doc/latex/jurabib
	rm -rf ${WRKSRC}/doc/latex/k*
	rm -rf ${WRKSRC}/doc/latex/lastpage
	rm -rf ${WRKSRC}/doc/latex/lis*
	rm -rf ${WRKSRC}/doc/latex/m[b-g]*
	rm -rf ${WRKSRC}/doc/latex/mi*
	rm -rf ${WRKSRC}/doc/latex/moreverb
	rm -rf ${WRKSRC}/doc/latex/ms
	rm -rf ${WRKSRC}/doc/latex/n[a-s]*
	rm -rf ${WRKSRC}/doc/latex/ntgclass
	rm -rf ${WRKSRC}/doc/latex/oberdiek
	rm -rf ${WRKSRC}/doc/latex/paralist
	rm -rf ${WRKSRC}/doc/latex/p[c-g]*
	rm -rf ${WRKSRC}/doc/latex/picinpar
	rm -rf ${WRKSRC}/doc/latex/placeins
	rm -rf ${WRKSRC}/doc/latex/pre*
	rm -rf ${WRKSRC}/doc/latex/ps[g-n]*
	rm -rf ${WRKSRC}/doc/latex/rotating
	rm -rf ${WRKSRC}/doc/latex/se*
	rm -rf ${WRKSRC}/doc/latex/soul
	rm -rf ${WRKSRC}/doc/latex/stmaryrd
	rm -rf ${WRKSRC}/doc/latex/su*
	rm -rf ${WRKSRC}/doc/latex/ti*
	rm -rf ${WRKSRC}/doc/latex/toc*
	rm -rf ${WRKSRC}/doc/latex/tools
	rm -rf ${WRKSRC}/doc/latex/ty*
	rm -rf ${WRKSRC}/doc/latex/wasysym
	rm -rf ${WRKSRC}/doc/latex/wrapfig
	rm -rf ${WRKSRC}/doc/latex/xcolor
	rm -rf ${WRKSRC}/doc/programs
	rm -rf ${WRKSRC}/doc/m[a-j]*
	rm -rf ${WRKSRC}/doc/pdftex
	rm -rf ${WRKSRC}/dvips/[b-n]*
	rm -rf ${WRKSRC}/dvips/pstricks
	rm -rf ${WRKSRC}/dvips/[r-z]*
	rm -rf ${WRKSRC}/fonts/afm/[a-o]*
	rm -rf ${WRKSRC}/fonts/afm/public/[b-n]*
	rm -rf ${WRKSRC}/fonts/afm/public/pxfonts
	rm -rf ${WRKSRC}/fonts/afm/public/[r-z]*
	rm -rf ${WRKSRC}/fonts/afm/urw
	rmdir ${WRKSRC}/fonts/cmap
	rm -rf ${WRKSRC}/fonts/enc/dvipdfm/tetex
	rm -rf ${WRKSRC}/fonts/enc/dvips/base
	rm -rf ${WRKSRC}/fonts/enc/dvips/context
	rm -rf ${WRKSRC}/fonts/enc/dvips/lm
	rm -rf ${WRKSRC}/fonts/enc/dvips/tetex
	rmdir ${WRKSRC}/fonts/lig
	rm -f ${WRKSRC}/fonts/map/dvipdfm/tetex/cm-dvipdfm-fix.map
	rmdir ${WRKSRC}/fonts/map/dvipdfm/updmap
	rm -rf ${WRKSRC}/fonts/map/dvips/ams
	rm -rf ${WRKSRC}/fonts/map/dvips/context
	rm -rf ${WRKSRC}/fonts/map/dvips/lm
	rm -rf ${WRKSRC}/fonts/map/dvips/misc/cmcyr.map
	rm -f ${WRKSRC}/fonts/map/dvips/misc/eurosym.map
	rm -f ${WRKSRC}/fonts/map/dvips/misc/marvosym.map
	rm -rf ${WRKSRC}/fonts/map/dvips/psnfss
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/pxfonts.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/b*
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/[d-k]*.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/m*
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/pdftex35.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/ps2pk35.map
	rm -rf ${WRKSRC}/fonts/map/dvips/tetex/t*
	rmdir ${WRKSRC}/fonts/map/dvips/updmap
	rm -rf ${WRKSRC}/fonts/map/dvips/xypic
	rm -rf ${WRKSRC}/fonts/map/fontname
	rmdir ${WRKSRC}/fonts/map/pdftex/updmap
	rmdir ${WRKSRC}/fonts/misc
	rmdir ${WRKSRC}/fonts/opentype
	rmdir ${WRKSRC}/fonts/pk
	rmdir ${WRKSRC}/fonts/sfd
	rm -rf ${WRKSRC}/fonts/source/ams
	rm -rf ${WRKSRC}/fonts/source/jknappen/[a-r]*
	rm -rf ${WRKSRC}/fonts/source/lh
	rm -rf ${WRKSRC}/fonts/source/public/bbold
	rm -rf ${WRKSRC}/fonts/source/public/cm
	rm -rf ${WRKSRC}/fonts/source/public/cmextra
	rm -rf ${WRKSRC}/fonts/source/public/esint
	rm -rf ${WRKSRC}/fonts/source/public/eurosym
	rm -rf ${WRKSRC}/fonts/source/public/latex
	rm -rf ${WRKSRC}/fonts/source/public/mflogo
	rm -f ${WRKSRC}/fonts/source/public/misc/[0-9b-w]*.mf
	rm -f ${WRKSRC}/fonts/source/public/misc/z*.mf
	rm -rf ${WRKSRC}/fonts/source/public/[r-s]*
	rm -rf ${WRKSRC}/fonts/source/public/w*
	rm -rf ${WRKSRC}/fonts/source/public/xypic
	rm -rf ${WRKSRC}/fonts/tfm/adobe/[a-ln-z]*
	rm -rf ${WRKSRC}/fonts/tfm/ams
	rm -rf ${WRKSRC}/fonts/tfm/bitstrea
	rm -rf ${WRKSRC}/fonts/tfm/bitstrea
	rm -rf ${WRKSRC}/fonts/tfm/cg/cou*
	rm -rf ${WRKSRC}/fonts/tfm/cg/[h-kp-s]*
	rm -rf ${WRKSRC}/fonts/tfm/cg/times
	rm -rf ${WRKSRC}/fonts/tfm/[d-o]*
	rm -rf ${WRKSRC}/fonts/tfm/public/ae*
	rm -rf ${WRKSRC}/fonts/tfm/public/bbold
	rm -rf ${WRKSRC}/fonts/tfm/public/cm
	rm -rf ${WRKSRC}/fonts/tfm/public/cm[c-z]*
	rm -rf ${WRKSRC}/fonts/tfm/public/eurosym
	rm -rf ${WRKSRC}/fonts/tfm/public/latex
	rm -rf ${WRKSRC}/fonts/tfm/public/lm
	rm -rf ${WRKSRC}/fonts/tfm/public/marvosym
	rm -rf ${WRKSRC}/fonts/tfm/public/mflogo
	rm -f ${WRKSRC}/fonts/tfm/public/misc/[b-q]*.tfm
	rm -rf ${WRKSRC}/fonts/tfm/public/pazo
	rm -rf ${WRKSRC}/fonts/tfm/public/pxfonts
	rm -rf ${WRKSRC}/fonts/tfm/public/[r-t]*
	rm -rf ${WRKSRC}/fonts/tfm/public/w*
	rm -rf ${WRKSRC}/fonts/tfm/public/xypic
	rm -rf ${WRKSRC}/fonts/tfm/yandy/times
	rmdir ${WRKSRC}/fonts/truetype
	rm -rf ${WRKSRC}/fonts/type1/[a-o]*
	rm -rf ${WRKSRC}/fonts/type1/public/cmcyr
	rm -rf ${WRKSRC}/fonts/type1/public/[e-n]*
	rm -rf ${WRKSRC}/fonts/type1/public/pxfonts
	rm -rf ${WRKSRC}/fonts/type1/public/t*
	rm -rf ${WRKSRC}/fonts/type1/public/xypic
	rm -rf ${WRKSRC}/fonts/type1/urw
	rm -rf ${WRKSRC}/fonts/type1/xypic
	rmdir ${WRKSRC}/fonts/type3
	rmdir ${WRKSRC}/fonts/type42
	rm -rf ${WRKSRC}/fonts/vf/adobe/[a-ln-z]*
	rm -rf ${WRKSRC}/fonts/vf/bitstrea
	rm -rf ${WRKSRC}/fonts/vf/public/ae*
	rm -rf ${WRKSRC}/fonts/vf/public/cmcyr
	rm -rf ${WRKSRC}/fonts/vf/public/pxfonts
	rm -rf ${WRKSRC}/fonts/vf/public/t*
	rm -rf ${WRKSRC}/fonts/vf/cg/cou*
	rm -rf ${WRKSRC}/fonts/vf/cg/[h-k]*
	rm -rf ${WRKSRC}/fonts/vf/cg/times
	rm -rf ${WRKSRC}/fonts/vf/yandy/times
	rm -rf ${WRKSRC}/metafont/[a-l]*
	rm -f ${WRKSRC}/metafont/misc/[a-w]*
	rm -rf ${WRKSRC}/metapost/[a-c]*
	rm -rf ${WRKSRC}/metapost/misc
	rm -rf ${WRKSRC}/metapost/support
	rm -rf ${WRKSRC}/mft
	rm -rf ${WRKSRC}/omega/ocp/misc
	rm -rf ${WRKSRC}/omega/otp/misc
	rm -rf ${WRKSRC}/scripts/context
	rm -rf ${WRKSRC}/tex/context
	rm -rf ${WRKSRC}/tex/generic/[a-b]*
	rm -rf ${WRKSRC}/tex/generic/con*
	rm -rf ${WRKSRC}/tex/generic/enctex
	rm -rf ${WRKSRC}/tex/generic/epsf
	rm -rf ${WRKSRC}/tex/generic/german
	rm -rf ${WRKSRC}/tex/generic/hyphen
	rm -rf ${WRKSRC}/tex/generic/multido
	rm -rf ${WRKSRC}/tex/generic/null
	rm -rf ${WRKSRC}/tex/generic/path
	rm -rf ${WRKSRC}/tex/generic/pstricks
	rm -rf ${WRKSRC}/tex/generic/ruhyphen
	rm -rf ${WRKSRC}/tex/generic/tex-ps
	rm -rf ${WRKSRC}/tex/generic/texnames
	rm -rf ${WRKSRC}/tex/generic/ukrhyph
	rm -rf ${WRKSRC}/tex/generic/x*
	rm -rf ${WRKSRC}/tex/lambda
	rm -rf ${WRKSRC}/tex/latex/a4wide
	rm -rf ${WRKSRC}/tex/latex/ae
	rm -rf ${WRKSRC}/tex/latex/a[f-m]*
	rm -rf ${WRKSRC}/tex/latex/base
	rm -rf ${WRKSRC}/tex/latex/bbold
	rm -rf ${WRKSRC}/tex/latex/be*
	rm -rf ${WRKSRC}/tex/latex/bibtopic
	rm -rf ${WRKSRC}/tex/latex/bo*
	rm -rf ${WRKSRC}/tex/latex/ca[m-z]*
	rm -rf ${WRKSRC}/tex/latex/carlisle
	rm -rf ${WRKSRC}/tex/latex/changebar
	rm -rf ${WRKSRC}/tex/latex/chngpage
	rm -rf ${WRKSRC}/tex/latex/cite
	rm -rf ${WRKSRC}/tex/latex/concrete
	rm -rf ${WRKSRC}/tex/latex/con[f-z]*
	rm -rf ${WRKSRC}/tex/latex/c[v-z]*
	rm -f ${WRKSRC}/tex/latex/dvipdfm/dvipdfm.def
	rm -rf ${WRKSRC}/tex/latex/e[d-n]*
	rm -rf ${WRKSRC}/tex/latex/e[st]*
	rm -rf ${WRKSRC}/tex/latex/euler
	rm -rf ${WRKSRC}/tex/latex/eurosym
	rm -rf ${WRKSRC}/tex/latex/exam
	rm -rf ${WRKSRC}/tex/latex/extsizes
	rm -rf ${WRKSRC}/tex/latex/fa*
	rm -rf ${WRKSRC}/tex/latex/float
	rm -rf ${WRKSRC}/tex/latex/fnpara
	rm -rf ${WRKSRC}/tex/latex/footmisc
	rm -rf ${WRKSRC}/tex/latex/fp
	rm -rf ${WRKSRC}/tex/latex/framed
	rm -rf ${WRKSRC}/tex/latex/geo*
	rm -f ${WRKSRC}/tex/latex/graphics/[a-l]*
	rm -f ${WRKSRC}/tex/latex/graphics/p*
	rm -f ${WRKSRC}/tex/latex/graphics/t[cr]*
	rm -rf ${WRKSRC}/tex/latex/here
	rm -rf ${WRKSRC}/tex/latex/hyp*
	rm -rf ${WRKSRC}/tex/latex/jurabib
	rm -rf ${WRKSRC}/tex/latex/k*
	rm -rf ${WRKSRC}/tex/latex/lastpage
	rm -rf ${WRKSRC}/tex/latex/lis*
	rm -rf ${WRKSRC}/tex/latex/lm
	rm -rf ${WRKSRC}/tex/latex/marvosym
	rm -rf ${WRKSRC}/tex/latex/m[b-g]*
	rm -rf ${WRKSRC}/tex/latex/mi*
	rm -rf ${WRKSRC}/tex/latex/moreverb
	rm -rf ${WRKSRC}/tex/latex/ms
	rm -rf ${WRKSRC}/tex/latex/multirow
	rm -rf ${WRKSRC}/tex/latex/n[a-s]*
	rm -rf ${WRKSRC}/tex/latex/ntgclass
	rm -f ${WRKSRC}/tex/latex/oberdiek/[a-u]*
	rm -rf ${WRKSRC}/tex/latex/optional
	rm -rf ${WRKSRC}/tex/latex/par*
	rm -rf ${WRKSRC}/tex/latex/p[c-g]*
	rm -rf ${WRKSRC}/tex/latex/picinpar
	rm -rf ${WRKSRC}/tex/latex/placeins
	rm -rf ${WRKSRC}/tex/latex/pre*
	rm -rf ${WRKSRC}/tex/latex/psl*
	rm -rf ${WRKSRC}/tex/latex/pstricks
	rm -rf ${WRKSRC}/tex/latex/psn*
	rm -rf ${WRKSRC}/tex/latex/pxfonts
	rm -rf ${WRKSRC}/tex/latex/relsize
	rm -rf ${WRKSRC}/tex/latex/rotating
	rm -rf ${WRKSRC}/tex/latex/selectp
	rm -rf ${WRKSRC}/tex/latex/sec*
	rm -rf ${WRKSRC}/tex/latex/seminar
	rm -rf ${WRKSRC}/tex/latex/set*
	rm -rf ${WRKSRC}/tex/latex/shadow
	rm -rf ${WRKSRC}/tex/latex/showtags
	rm -rf ${WRKSRC}/tex/latex/soul
	rm -rf ${WRKSRC}/tex/latex/stmaryrd
	rm -rf ${WRKSRC}/tex/latex/su*
	rm -rf ${WRKSRC}/tex/latex/t2
	rm -rf ${WRKSRC}/tex/latex/tabls
	rm -rf ${WRKSRC}/tex/latex/threeparttable
	rm -rf ${WRKSRC}/tex/latex/ti*
	rm -rf ${WRKSRC}/tex/latex/toc*
	rm -rf ${WRKSRC}/tex/latex/tools
	rm -rf ${WRKSRC}/tex/latex/t[s-z]*
	rm -rf ${WRKSRC}/tex/latex/ulem
	rm -rf ${WRKSRC}/tex/latex/url
	rm -rf ${WRKSRC}/tex/latex/version
	rm -rf ${WRKSRC}/tex/latex/wasysym
	rm -rf ${WRKSRC}/tex/latex/wrapfig
	rm -rf ${WRKSRC}/tex/latex/xcolor
	rm -rf ${WRKSRC}/tex/latex/xk*
	rm -rf ${WRKSRC}/tex/plain/amsfonts
	rm -f ${WRKSRC}/tex/plain/base/[c-gmp-z]*
	rm -f ${WRKSRC}/tex/plain/base/letter*
	rm -rf ${WRKSRC}/tex/plain/[c-f]*
	rm -rf ${WRKSRC}/tex/plain/[i-l]*
	rm -rf ${WRKSRC}/tex/plain/mproof
	rm -rf ${WRKSRC}/tex/plain/pdfcolor
	rm -rf ${WRKSRC}/tex/plain/[r-u]*
	rm -rf ${WRKSRC}/tex/plain/[w-z]*
	rm -rf ${WRKSRC}/tex/platex

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../mk/bsd.pkg.mk"
