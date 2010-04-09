# $NetBSD: Makefile,v 1.41 2010/04/09 22:04:37 markd Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
PKGREVISION=	23
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

CONFLICTS+=	teTeX-share-[0-9]*
DEPENDS+=	tex-ae-[0-9]*:../../fonts/tex-ae
DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-amscls-[0-9]*:../../print/tex-amscls
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-carlisle-[0-9]*:../../print/tex-carlisle
DEPENDS+=	tex-cite-[0-9]*:../../print/tex-cite
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-courier-[0-9]*:../../fonts/tex-courier
DEPENDS+=	tex-dvips-[0-9]*:../../print/tex-dvips
DEPENDS+=	tex-enctex-[0-9]*:../../print/tex-enctex
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-exam-[0-9]*:../../print/tex-exam
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-helvetic-[0-9]*:../../fonts/tex-helvetic
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
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
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-lambda-[0-9]*:../../print/tex-lambda
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc
DEPENDS+=	tex-marvosym-[0-9]*:../../fonts/tex-marvosym
DEPENDS+=	tex-makeindex-[0-9]*:../../textproc/tex-makeindex
DEPENDS+=	tex-manfnt-[0-9]*:../../fonts/tex-manfnt
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-mflogo-[0-9]*:../../fonts/tex-mflogo
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-moreverb-[0-9]*:../../print/tex-moreverb
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-multirow-[0-9]*:../../print/tex-multirow
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-nomencl-[0-9]*:../../print/tex-nomencl
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-placeins-[0-9]*:../../print/tex-placeins
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-rsfs-[0-9]*:../../fonts/tex-rsfs
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
DEPENDS+=	tex-subfigure-[0-9]*:../../print/tex-subfigure
DEPENDS+=	tex-subfig-[0-9]*:../../print/tex-subfig
DEPENDS+=	tex-symbol-[0-9]*:../../fonts/tex-symbol
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-titlesec-[0-9]*:../../print/tex-titlesec
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-txfonts-[0-9]*:../../fonts/tex-txfonts
DEPENDS+=	tex-type1cm-[0-9]*:../../print/tex-type1cm
DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-zapfding-[0-9]*:../../fonts/tex-zapfding

EXTRACT_ELEMENTS+=	aliases
EXTRACT_ELEMENTS+=	bibtex
EXTRACT_ELEMENTS+=	context
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
TEX_MAP_FILES+=		cmcyr.map
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
TEX_MIXEDMAP_FILES+=	eurosym.map
TEX_MIXEDMAP_FILES+=	vnr.map

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive-tetex/map.mk"

post-extract:
	rm -f ${WRKSRC}/ls-R
	rm -rf ${WRKSRC}/bibtex/bib/[A-Za-o]*
	rm -rf ${WRKSRC}/bibtex/bst/ams
	rm -rf ${WRKSRC}/bibtex/bst/base
	rm -rf ${WRKSRC}/bibtex/bst/misc
	rm -rf ${WRKSRC}/bibtex/bst/natbib
	rm -rf ${WRKSRC}/doc/bibtex/base
	rmdir ${WRKSRC}/doc/generic/pdfcrop
	rm -rf ${WRKSRC}/doc/etex
	rm -rf ${WRKSRC}/doc/fonts/ae*
	rm -rf ${WRKSRC}/doc/fonts/am*
	rm -rf ${WRKSRC}/doc/fonts/lm
	rm -rf ${WRKSRC}/doc/fonts/mar*
	rm -rf ${WRKSRC}/doc/fonts/t*
	rm -rf ${WRKSRC}/doc/generic/[a-f]*
	rm -rf ${WRKSRC}/doc/generic/xk*
	rm -rf ${WRKSRC}/doc/latex/a[f-m]*
	rm -rf ${WRKSRC}/doc/latex/beamer
	rm -rf ${WRKSRC}/doc/latex/ca*
	rm -rf ${WRKSRC}/doc/latex/enumitem
	rm -rf ${WRKSRC}/doc/latex/exam
	rm -rf ${WRKSRC}/doc/latex/fancy[c-z]*
	rm -rf ${WRKSRC}/doc/latex/float
	rm -rf ${WRKSRC}/doc/latex/footmisc
	rm -rf ${WRKSRC}/doc/latex/geo*
	rm -rf ${WRKSRC}/doc/latex/hyperref
	rm -rf ${WRKSRC}/doc/latex/k*
	rm -rf ${WRKSRC}/doc/latex/lis*
	rm -rf ${WRKSRC}/doc/latex/memoir
	rm -rf ${WRKSRC}/doc/latex/mflogo
	rm -rf ${WRKSRC}/doc/latex/microtype
	rm -rf ${WRKSRC}/doc/latex/moreverb
	rm -rf ${WRKSRC}/doc/latex/ms
	rm -rf ${WRKSRC}/doc/latex/n[a-s]*
	rm -rf ${WRKSRC}/doc/latex/oberdiek
	rm -rf ${WRKSRC}/doc/latex/paralist
	rm -rf ${WRKSRC}/doc/latex/placeins
	rm -rf ${WRKSRC}/doc/latex/preprint
	rm -rf ${WRKSRC}/doc/latex/rotating
	rm -rf ${WRKSRC}/doc/latex/sectsty
	rm -rf ${WRKSRC}/doc/latex/stmaryrd
	rm -rf ${WRKSRC}/doc/latex/sub*
	rm -rf ${WRKSRC}/doc/latex/ti*
	rm -rf ${WRKSRC}/doc/latex/tools
	rm -rf ${WRKSRC}/doc/latex/ty*
	rm -rf ${WRKSRC}/doc/latex/wasysym/wasydoc.dvi
	rm -rf ${WRKSRC}/doc/latex/xcolor
	rm -rf ${WRKSRC}/doc/makeindex
	rm -rf ${WRKSRC}/doc/pdftex
	rm -rf ${WRKSRC}/dvips/[b-l]*
	rm -f ${WRKSRC}/dvips/misc/resolution400.ps
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
	rm -rf ${WRKSRC}/fonts/enc/dvips/lm
	rm -rf ${WRKSRC}/fonts/enc/dvips/tetex
	rmdir ${WRKSRC}/fonts/lig
	rm -f ${WRKSRC}/fonts/map/dvipdfm/tetex/cm-dvipdfm-fix.map
	rmdir ${WRKSRC}/fonts/map/dvipdfm/updmap
	rm -rf ${WRKSRC}/fonts/map/dvips/lm
	rm -f ${WRKSRC}/fonts/map/dvips/misc/marvosym.map
	rmdir ${WRKSRC}/fonts/map/dvips/updmap
	rmdir ${WRKSRC}/fonts/map/pdftex/updmap
	rm -rf ${WRKSRC}/fonts/map/dvips/ams
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
	rm -rf ${WRKSRC}/fonts/source/public/cm
	rm -rf ${WRKSRC}/fonts/source/public/latex
	rm -rf ${WRKSRC}/fonts/source/public/mflogo
	rm -f ${WRKSRC}/fonts/source/public/misc/[0-9b-w]*.mf
	rm -f ${WRKSRC}/fonts/source/public/misc/z*.mf
	rm -rf ${WRKSRC}/fonts/source/public/[r-s]*
	rm -rf ${WRKSRC}/fonts/source/public/w*
	rm -rf ${WRKSRC}/fonts/tfm/adobe/[c-lq-y]*
	rm -rf ${WRKSRC}/fonts/tfm/adobe/zapfding
	rm -rf ${WRKSRC}/fonts/tfm/ams
	rm -rf ${WRKSRC}/fonts/tfm/cg/cou*
	rm -rf ${WRKSRC}/fonts/tfm/cg/[h-kp-s]*
	rm -rf ${WRKSRC}/fonts/tfm/cg/times
	rm -rf ${WRKSRC}/fonts/tfm/public/t*
	rm -rf ${WRKSRC}/fonts/tfm/public/ae*
	rm -rf ${WRKSRC}/fonts/tfm/public/cm
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
	rm -rf ${WRKSRC}/fonts/type1/hoekwater/[d-z]*
	rm -rf ${WRKSRC}/fonts/type1/public/lm
	rm -rf ${WRKSRC}/fonts/type1/public/marvosym
	rm -rf ${WRKSRC}/fonts/type1/public/t*
	rm -rf ${WRKSRC}/fonts/type1/urw/[c-mq-y]*
	rm -rf ${WRKSRC}/fonts/type1/urw/zapfding
	rmdir ${WRKSRC}/fonts/type3
	rmdir ${WRKSRC}/fonts/type42
	rm -rf ${WRKSRC}/fonts/vf/adobe/[c-lq-y]*
	rm -rf ${WRKSRC}/fonts/vf/public/ae*
	rm -rf ${WRKSRC}/fonts/vf/public/t*
	rm -rf ${WRKSRC}/fonts/vf/cg/cou*
	rm -rf ${WRKSRC}/fonts/vf/cg/[h-k]*
	rm -rf ${WRKSRC}/fonts/vf/cg/times
	rm -rf ${WRKSRC}/fonts/vf/yandy/times
	rm -rf ${WRKSRC}/metafont/[a-l]*
	rm -f ${WRKSRC}/metafont/misc/[a-w]*
	rm -rf ${WRKSRC}/omega/ocp/misc
	rm -rf ${WRKSRC}/omega/otp/misc
	rm -rf ${WRKSRC}/tex/generic/[a-b]*
	rm -rf ${WRKSRC}/tex/generic/config
	rm -rf ${WRKSRC}/tex/generic/enctex
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
	rm -rf ${WRKSRC}/tex/latex/bo[a-np-z]*
	rm -rf ${WRKSRC}/tex/latex/ca[m-z]*
	rm -rf ${WRKSRC}/tex/latex/carlisle
	rm -rf ${WRKSRC}/tex/latex/chngpage
	rm -rf ${WRKSRC}/tex/latex/cite
	rm -rf ${WRKSRC}/tex/latex/concrete
	rm -rf ${WRKSRC}/tex/latex/config
	rm -f ${WRKSRC}/tex/latex/dvipdfm/dvipdfm.def
	rm -rf ${WRKSRC}/tex/latex/endnotes
	rm -rf ${WRKSRC}/tex/latex/enumitem
	rm -rf ${WRKSRC}/tex/latex/etex
	rm -rf ${WRKSRC}/tex/latex/exam
	rm -rf ${WRKSRC}/tex/latex/fancy[c-z]*
	rm -rf ${WRKSRC}/tex/latex/float
	rm -rf ${WRKSRC}/tex/latex/fnpara
	rm -rf ${WRKSRC}/tex/latex/footmisc
	rm -rf ${WRKSRC}/tex/latex/framed
	rm -rf ${WRKSRC}/tex/latex/geo*
	rm -f ${WRKSRC}/tex/latex/graphics/[a-l]*
	rm -f ${WRKSRC}/tex/latex/graphics/p[a-r]*
	rm -f ${WRKSRC}/tex/latex/graphics/t[cr]*
	rm -rf ${WRKSRC}/tex/latex/hyperref
	rm -rf ${WRKSRC}/tex/latex/k*
	rm -rf ${WRKSRC}/tex/latex/lis*
	rm -rf ${WRKSRC}/tex/latex/lm
	rm -rf ${WRKSRC}/tex/latex/marvosym
	rm -rf ${WRKSRC}/tex/latex/memoir
	rm -rf ${WRKSRC}/tex/latex/mflogo
	rm -rf ${WRKSRC}/tex/latex/microtype
	rm -rf ${WRKSRC}/tex/latex/moreverb
	rm -rf ${WRKSRC}/tex/latex/ms
	rm -rf ${WRKSRC}/tex/latex/multirow
	rm -rf ${WRKSRC}/tex/latex/n[a-s]*
	rm -f ${WRKSRC}/tex/latex/oberdiek/[a-u]*
	rm -rf ${WRKSRC}/tex/latex/optional
	rm -rf ${WRKSRC}/tex/latex/par*
	rm -rf ${WRKSRC}/tex/latex/placeins
	rm -rf ${WRKSRC}/tex/latex/preprint
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
	rm -rf ${WRKSRC}/tex/plain/[c-d]*
	rm -rf ${WRKSRC}/tex/plain/etex
	rm -rf ${WRKSRC}/tex/plain/fontchart
	rm -rf ${WRKSRC}/tex/plain/[i-l]*
	rm -rf ${WRKSRC}/tex/plain/mproof
	rm -rf ${WRKSRC}/tex/plain/pdfcolor
	rm -rf ${WRKSRC}/tex/plain/[r-u]*
	rm -rf ${WRKSRC}/tex/plain/[w-z]*

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../mk/bsd.pkg.mk"
