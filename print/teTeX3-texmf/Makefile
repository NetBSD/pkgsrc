# $NetBSD: Makefile,v 1.49 2011/01/22 23:54:25 minskim Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
PKGREVISION=	29
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
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-block-[0-9]*:../../print/tex-block
DEPENDS+=	tex-bold-extra-[0-9]*:../../print/tex-bold-extra
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
DEPENDS+=	tex-collection-latex>=2009:../../print/tex-collection-latex
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-context>=2009:../../print/tex-context
DEPENDS+=	tex-courier-[0-9]*:../../fonts/tex-courier
DEPENDS+=	tex-cyrillic>=2009:../../print/tex-cyrillic
DEPENDS+=	tex-dblfloatfix-[0-9]*:../../print/tex-dblfloatfix
DEPENDS+=	tex-ec>=1.0:../../fonts/tex-ec
DEPENDS+=	tex-eepic>=1.1e:../../graphics/tex-eepic
DEPENDS+=	tex-endfloat-[0-9]*:../../print/tex-endfloat
DEPENDS+=	tex-endnotes-[0-9]*:../../print/tex-endnotes
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-epsf>=2.7.3:../../print/tex-epsf
DEPENDS+=	tex-eurosym-[0-9]*:../../fonts/tex-eurosym
DEPENDS+=	tex-exam-[0-9]*:../../print/tex-exam
DEPENDS+=	tex-excludeonly-[0-9]*:../../print/tex-excludeonly
DEPENDS+=	tex-fancybox-[0-9]*:../../print/tex-fancybox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-fncylab-[0-9]*:../../print/tex-fncylab
DEPENDS+=	tex-fnpara-[0-9]*:../../print/tex-fnpara
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-framed-[0-9]*:../../print/tex-framed
DEPENDS+=	tex-ftcap-[0-9]*:../../print/tex-ftcap
DEPENDS+=	tex-fwlw-[0-9]*:../../print/tex-fwlw
DEPENDS+=	tex-gustlib-[0-9]*:../../print/tex-gustlib
DEPENDS+=	tex-helvetic-[0-9]*:../../fonts/tex-helvetic
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
DEPENDS+=	tex-ifmtarg-[0-9]*:../../print/tex-ifmtarg
DEPENDS+=	tex-kix-[0-9]*:../../print/tex-kix
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
DEPENDS+=	tex-listing-[0-9]*:../../print/tex-listing
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-lh>=3.5g:../../fonts/tex-lh
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-magaz-[0-9]*:../../print/tex-magaz
DEPENDS+=	tex-marvosym-[0-9]*:../../fonts/tex-marvosym
DEPENDS+=	tex-manfnt-[0-9]*:../../fonts/tex-manfnt
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
DEPENDS+=	tex-oubraces-[0-9]*:../../print/tex-oubraces
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-placeins-[0-9]*:../../print/tex-placeins
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
DEPENDS+=	tex-printlen-[0-9]*:../../print/tex-printlen
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-rsfs-[0-9]*:../../fonts/tex-rsfs
DEPENDS+=	tex-sansmath-[0-9]*:../../print/tex-sansmath
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-selectp-[0-9]*:../../print/tex-selectp
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
DEPENDS+=	tex-subfigure-[0-9]*:../../print/tex-subfigure
DEPENDS+=	tex-subfig-[0-9]*:../../print/tex-subfig
DEPENDS+=	tex-symbol-[0-9]*:../../fonts/tex-symbol
DEPENDS+=	tex-tabls-[0-9]*:../../print/tex-tabls
DEPENDS+=	tex-threeparttable-[0-9]*:../../print/tex-threeparttable
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-titlesec-[0-9]*:../../print/tex-titlesec
DEPENDS+=	tex-tocbibind-[0-9]*:../../print/tex-tocbibind
DEPENDS+=	tex-twoinone-[0-9]*:../../print/tex-twoinone
DEPENDS+=	tex-txfonts-[0-9]*:../../fonts/tex-txfonts
DEPENDS+=	tex-type1cm-[0-9]*:../../print/tex-type1cm
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-verbdef-[0-9]*:../../print/tex-verbdef
DEPENDS+=	tex-version-[0-9]*:../../print/tex-version
DEPENDS+=	tex-vertbars-[0-9]*:../../print/tex-vertbars
DEPENDS+=	tex-vruler-[0-9]*:../../print/tex-vruler
DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-zapfding-[0-9]*:../../fonts/tex-zapfding

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
EXTRACT_ELEMENTS+=	texdoctk

WRKSRC=		${WRKDIR}/tetex
EXTRACT_DIR=	${WRKSRC}
NO_BUILD=	yes

REPLACE_PERL+=	doc/generic/ruhyphen/reduce-patt doc/generic/ruhyphen/sorthyph
# No dependency on Perl.
CHECK_INTERPRETER_SKIP+=share/texmf-dist/doc/generic/ruhyphen/reduce-patt \
			share/texmf-dist/doc/generic/ruhyphen/sorthyph
REPLACE_SH+=	doc/latex/bibunits/bibtexall doc/latex/multibib/bibtexall
USE_TOOLS+=	sh:run pax

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
TEX_MAP_FILES+=		pxfonts.map
TEX_MAP_FILES+=		xypic.map
TEX_MAP_FILES+=		urwvn.map
TEX_MAP_FILES+=		dstroke.map
TEX_MIXEDMAP_FILES+=	cs.map
TEX_MIXEDMAP_FILES+=	pl.map
TEX_MIXEDMAP_FILES+=	ccpl.map
TEX_MIXEDMAP_FILES+=	vnr.map

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive-tetex/map.mk"

post-extract:
	rm -f ${WRKSRC}/ls-R
	rm -rf ${WRKSRC}/bibtex/bib
	rm -rf ${WRKSRC}/bibtex/bst/ams
	rm -rf ${WRKSRC}/bibtex/bst/[b-c]*
	rm -rf ${WRKSRC}/bibtex/bst/misc
	rm -rf ${WRKSRC}/bibtex/bst/natbib
	rm -rf ${WRKSRC}/bibtex/bst/plbib
	rm -rf ${WRKSRC}/doc/bibtex/base
	rmdir ${WRKSRC}/doc/generic/pdfcrop
	rm -rf ${WRKSRC}/doc/etex
	rm -rf ${WRKSRC}/doc/fonts/ae*
	rm -rf ${WRKSRC}/doc/fonts/am*
	rm -rf ${WRKSRC}/doc/fonts/cm
	rm -rf ${WRKSRC}/doc/fonts/ec
	rm -rf ${WRKSRC}/doc/fonts/eu*
	rm -rf ${WRKSRC}/doc/fonts/l[a-t]*
	rm -rf ${WRKSRC}/doc/fonts/mar*
	rm -rf ${WRKSRC}/doc/fonts/t*
	rm -rf ${WRKSRC}/doc/generic/[a-f]*
	rm -rf ${WRKSRC}/doc/generic/[a-g]*
	rm -rf ${WRKSRC}/doc/generic/xk*
	rm -rf ${WRKSRC}/doc/latex/a[f-m]*
	rm -rf ${WRKSRC}/doc/latex/base
	rm -rf ${WRKSRC}/doc/latex/be[a-y]*
	rm -rf ${WRKSRC}/doc/latex/ca*
	rm -rf ${WRKSRC}/doc/latex/changebar
	rm -rf ${WRKSRC}/doc/latex/c[v-z]*
	rm -rf ${WRKSRC}/doc/latex/e[d-n]*
	rm -rf ${WRKSRC}/doc/latex/euler
	rm -rf ${WRKSRC}/doc/latex/exam
	rm -rf ${WRKSRC}/doc/latex/fa*
	rm -rf ${WRKSRC}/doc/latex/float
	rm -rf ${WRKSRC}/doc/latex/footmisc
	rm -rf ${WRKSRC}/doc/latex/geo*
	rm -rf ${WRKSRC}/doc/latex/hyperref
	rm -rf ${WRKSRC}/doc/latex/k*
	rm -rf ${WRKSRC}/doc/latex/lis*
	rm -rf ${WRKSRC}/doc/latex/m[e-g]*
	rm -rf ${WRKSRC}/doc/latex/mi*
	rm -rf ${WRKSRC}/doc/latex/moreverb
	rm -rf ${WRKSRC}/doc/latex/ms
	rm -rf ${WRKSRC}/doc/latex/n[a-s]*
	rm -rf ${WRKSRC}/doc/latex/oberdiek
	rm -rf ${WRKSRC}/doc/latex/paralist
	rm -rf ${WRKSRC}/doc/latex/pgf
	rm -rf ${WRKSRC}/doc/latex/placeins
	rm -rf ${WRKSRC}/doc/latex/preprint
	rm -rf ${WRKSRC}/doc/latex/ps[g-n]*
	rm -rf ${WRKSRC}/doc/latex/rotating
	rm -rf ${WRKSRC}/doc/latex/sectsty
	rm -rf ${WRKSRC}/doc/latex/stmaryrd
	rm -rf ${WRKSRC}/doc/latex/sub*
	rm -rf ${WRKSRC}/doc/latex/ti*
	rm -rf ${WRKSRC}/doc/latex/tocbibind
	rm -rf ${WRKSRC}/doc/latex/tools
	rm -rf ${WRKSRC}/doc/latex/ty*
	rm -rf ${WRKSRC}/doc/latex/wasysym/wasydoc.dvi
	rm -rf ${WRKSRC}/doc/latex/xcolor
	rm -rf ${WRKSRC}/doc/m[a-j]*
	rm -rf ${WRKSRC}/doc/pdftex
	rm -rf ${WRKSRC}/dvips/[b-l]*
	rm -f ${WRKSRC}/dvips/misc/[o-r]*
	rm -rf ${WRKSRC}/dvips/tetex
	rm -rf ${WRKSRC}/fonts/afm/adobe/[c-mq-y]*
	rm -rf ${WRKSRC}/fonts/afm/adobe/zapfding
	rm -rf ${WRKSRC}/fonts/afm/public/lm
	rm -rf ${WRKSRC}/fonts/afm/public/marvosym
	rm -rf ${WRKSRC}/fonts/afm/public/t*
	rm -rf ${WRKSRC}/fonts/afm/urw/[c-mq-y]*
	rm -rf ${WRKSRC}/fonts/afm/urw/zapfding
	rmdir ${WRKSRC}/fonts/cmap
	rm -rf ${WRKSRC}/fonts/enc/dvipdfm/tetex
	rm -rf ${WRKSRC}/fonts/enc/dvips/base
	rm -rf ${WRKSRC}/fonts/enc/dvips/context
	rm -rf ${WRKSRC}/fonts/enc/dvips/lm
	rm -rf ${WRKSRC}/fonts/enc/dvips/tetex
	rmdir ${WRKSRC}/fonts/lig
	rm -f ${WRKSRC}/fonts/map/dvipdfm/tetex/cm-dvipdfm-fix.map
	rmdir ${WRKSRC}/fonts/map/dvipdfm/updmap
	rm -rf ${WRKSRC}/fonts/map/dvips/context
	rm -rf ${WRKSRC}/fonts/map/dvips/lm
	rm -f ${WRKSRC}/fonts/map/dvips/misc/eurosym.map
	rm -f ${WRKSRC}/fonts/map/dvips/misc/marvosym.map
	rmdir ${WRKSRC}/fonts/map/dvips/updmap
	rmdir ${WRKSRC}/fonts/map/pdftex/updmap
	rm -rf ${WRKSRC}/fonts/map/dvips/ams
	rm -rf ${WRKSRC}/fonts/map/dvips/misc/cmcyr.map
	rm -rf ${WRKSRC}/fonts/map/dvips/psnfss
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/b*
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/[d-k]*.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/m*
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/pdftex35.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/ps2pk35.map
	rm -rf ${WRKSRC}/fonts/map/dvips/tetex/t*
	rmdir ${WRKSRC}/fonts/misc
	rmdir ${WRKSRC}/fonts/opentype
	rmdir ${WRKSRC}/fonts/pk
	rmdir ${WRKSRC}/fonts/sfd
	rm -rf ${WRKSRC}/fonts/source/ams
	rm -rf ${WRKSRC}/fonts/source/jknappen/[a-r]*
	rm -rf ${WRKSRC}/fonts/source/lh
	rm -rf ${WRKSRC}/fonts/source/public/cm
	rm -rf ${WRKSRC}/fonts/source/public/eurosym
	rm -rf ${WRKSRC}/fonts/source/public/latex
	rm -rf ${WRKSRC}/fonts/source/public/mflogo
	rm -f ${WRKSRC}/fonts/source/public/misc/[0-9b-w]*.mf
	rm -f ${WRKSRC}/fonts/source/public/misc/z*.mf
	rm -rf ${WRKSRC}/fonts/source/public/[r-s]*
	rm -rf ${WRKSRC}/fonts/source/public/w*
	rm -rf ${WRKSRC}/fonts/tfm/adobe/[c-lq-y]*
	rm -rf ${WRKSRC}/fonts/tfm/adobe/ps*
	rm -rf ${WRKSRC}/fonts/tfm/adobe/zapfding
	rm -rf ${WRKSRC}/fonts/tfm/ams
	rm -rf ${WRKSRC}/fonts/tfm/cg/cou*
	rm -rf ${WRKSRC}/fonts/tfm/cg/[h-kp-s]*
	rm -rf ${WRKSRC}/fonts/tfm/cg/times
	rm -rf ${WRKSRC}/fonts/tfm/[d-o]*
	rm -rf ${WRKSRC}/fonts/tfm/public/t*
	rm -rf ${WRKSRC}/fonts/tfm/public/ae*
	rm -rf ${WRKSRC}/fonts/tfm/public/cm
	rm -rf ${WRKSRC}/fonts/tfm/public/cmcyr
	rm -rf ${WRKSRC}/fonts/tfm/public/eurosym
	rm -rf ${WRKSRC}/fonts/tfm/public/latex
	rm -rf ${WRKSRC}/fonts/tfm/public/lm
	rm -rf ${WRKSRC}/fonts/tfm/public/marvosym
	rm -rf ${WRKSRC}/fonts/tfm/public/mflogo
	rm -f ${WRKSRC}/fonts/tfm/public/misc/[b-q]*.tfm
	rm -rf ${WRKSRC}/fonts/tfm/public/[r-s]*
	rm -rf ${WRKSRC}/fonts/tfm/public/w*
	rm -rf ${WRKSRC}/fonts/tfm/yandy/times
	rmdir ${WRKSRC}/fonts/truetype
	rm -rf ${WRKSRC}/fonts/type1/bluesky
	rm -rf ${WRKSRC}/fonts/type1/hoekwater
	rm -rf ${WRKSRC}/fonts/type1/public/cmcyr
	rm -rf ${WRKSRC}/fonts/type1/public/eurosym
	rm -rf ${WRKSRC}/fonts/type1/public/lm
	rm -rf ${WRKSRC}/fonts/type1/public/marvosym
	rm -rf ${WRKSRC}/fonts/type1/public/t*
	rm -rf ${WRKSRC}/fonts/type1/urw/[c-mq-y]*
	rm -rf ${WRKSRC}/fonts/type1/urw/zapfding
	rmdir ${WRKSRC}/fonts/type3
	rmdir ${WRKSRC}/fonts/type42
	rm -rf ${WRKSRC}/fonts/vf/adobe/[c-lq-y]*
	rm -rf ${WRKSRC}/fonts/vf/adobe/ps*
	rm -rf ${WRKSRC}/fonts/vf/public/ae*
	rm -rf ${WRKSRC}/fonts/vf/public/cmcyr
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
	rm -rf ${WRKSRC}/tex/generic/null
	rm -rf ${WRKSRC}/tex/generic/path
	rm -rf ${WRKSRC}/tex/generic/ruhyphen
	rm -rf ${WRKSRC}/tex/generic/texnames
	rm -rf ${WRKSRC}/tex/generic/ukrhyph
	rm -rf ${WRKSRC}/tex/generic/xk*
	rm -rf ${WRKSRC}/tex/lambda
	rm -rf ${WRKSRC}/tex/latex/a4wide
	rm -rf ${WRKSRC}/tex/latex/ae
	rm -rf ${WRKSRC}/tex/latex/a[f-m]*
	rm -rf ${WRKSRC}/tex/latex/base
	rm -rf ${WRKSRC}/tex/latex/beamer
	rm -rf ${WRKSRC}/tex/latex/beton
	rm -rf ${WRKSRC}/tex/latex/bo[a-np-z]*
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
	rm -rf ${WRKSRC}/tex/latex/etex
	rm -rf ${WRKSRC}/tex/latex/euler
	rm -rf ${WRKSRC}/tex/latex/eurosym
	rm -rf ${WRKSRC}/tex/latex/exam
	rm -rf ${WRKSRC}/tex/latex/fa*
	rm -rf ${WRKSRC}/tex/latex/float
	rm -rf ${WRKSRC}/tex/latex/fnpara
	rm -rf ${WRKSRC}/tex/latex/footmisc
	rm -rf ${WRKSRC}/tex/latex/framed
	rm -rf ${WRKSRC}/tex/latex/geo*
	rm -f ${WRKSRC}/tex/latex/graphics/[a-l]*
	rm -f ${WRKSRC}/tex/latex/graphics/p[a-r]*
	rm -f ${WRKSRC}/tex/latex/graphics/t[cr]*
	rm -rf ${WRKSRC}/tex/latex/here
	rm -rf ${WRKSRC}/tex/latex/hyperref
	rm -rf ${WRKSRC}/tex/latex/k*
	rm -rf ${WRKSRC}/tex/latex/lis*
	rm -rf ${WRKSRC}/tex/latex/lm
	rm -rf ${WRKSRC}/tex/latex/marvosym
	rm -rf ${WRKSRC}/tex/latex/m[e-g]*
	rm -rf ${WRKSRC}/tex/latex/mi*
	rm -rf ${WRKSRC}/tex/latex/moreverb
	rm -rf ${WRKSRC}/tex/latex/ms
	rm -rf ${WRKSRC}/tex/latex/multirow
	rm -rf ${WRKSRC}/tex/latex/n[a-s]*
	rm -f ${WRKSRC}/tex/latex/oberdiek/[a-u]*
	rm -rf ${WRKSRC}/tex/latex/optional
	rm -rf ${WRKSRC}/tex/latex/par*
	rm -rf ${WRKSRC}/tex/latex/pgf
	rm -rf ${WRKSRC}/tex/latex/placeins
	rm -rf ${WRKSRC}/tex/latex/preprint
	rm -rf ${WRKSRC}/tex/latex/psl*
	rm -rf ${WRKSRC}/tex/latex/psnfss
	rm -rf ${WRKSRC}/tex/latex/relsize
	rm -rf ${WRKSRC}/tex/latex/rotating
	rm -rf ${WRKSRC}/tex/latex/selectp
	rm -rf ${WRKSRC}/tex/latex/sec*
	rm -rf ${WRKSRC}/tex/latex/set*
	rm -rf ${WRKSRC}/tex/latex/shadow
	rm -rf ${WRKSRC}/tex/latex/showtags
	rm -rf ${WRKSRC}/tex/latex/stmaryrd
	rm -rf ${WRKSRC}/tex/latex/sub*
	rm -rf ${WRKSRC}/tex/latex/tabls
	rm -rf ${WRKSRC}/tex/latex/threeparttable
	rm -rf ${WRKSRC}/tex/latex/ti*
	rm -rf ${WRKSRC}/tex/latex/tocbibind
	rm -rf ${WRKSRC}/tex/latex/tools
	rm -rf ${WRKSRC}/tex/latex/t[s-z]*
	rm -rf ${WRKSRC}/tex/latex/ulem
	rm -rf ${WRKSRC}/tex/latex/url
	rm -rf ${WRKSRC}/tex/latex/version
	rm -rf ${WRKSRC}/tex/latex/xcolor
	rm -rf ${WRKSRC}/tex/latex/xk*
	rm -rf ${WRKSRC}/tex/plain/amsfonts
	rm -f ${WRKSRC}/tex/plain/base/[gmp-z]*
	rm -f ${WRKSRC}/tex/plain/base/letter*
	rm -rf ${WRKSRC}/tex/plain/[c-f]*
	rm -rf ${WRKSRC}/tex/plain/[i-l]*
	rm -rf ${WRKSRC}/tex/plain/mproof
	rm -rf ${WRKSRC}/tex/plain/pdfcolor
	rm -rf ${WRKSRC}/tex/plain/[r-u]*
	rm -rf ${WRKSRC}/tex/plain/[w-z]*

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../mk/bsd.pkg.mk"
