# $NetBSD: Makefile,v 1.28 2009/04/15 09:19:44 minskim Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
PKGREVISION=	13
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

CONFLICTS+=	teTeX-share-[0-9]*
DEPENDS+=	tex-bin-kpathsea-[0-9]*:../../print/tex-bin-kpathsea
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
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
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-misc-[0-9]*:../../print/tex-misc
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

EXTRACT_ELEMENTS+=	ChangeLog
EXTRACT_ELEMENTS+=	LICENSE.texmf
EXTRACT_ELEMENTS+=	aliases
EXTRACT_ELEMENTS+=	bibtex
EXTRACT_ELEMENTS+=	context
EXTRACT_ELEMENTS+=	doc
EXTRACT_ELEMENTS+=	dvips
EXTRACT_ELEMENTS+=	fonts
EXTRACT_ELEMENTS+=	makeindex
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
TEX_MAP_FILES+=		charter.map
TEX_MAP_FILES+=		cmcyr.map
TEX_MAP_FILES+=		contnav.map
TEX_MAP_FILES+=		cork-lm.map
TEX_MAP_FILES+=		qx-lm.map
TEX_MAP_FILES+=		texnansi-lm.map
TEX_MAP_FILES+=		ts1-lm.map
TEX_MAP_FILES+=		marvosym.map
TEX_MAP_FILES+=		mathpple.map
TEX_MAP_FILES+=		omega.map
TEX_MAP_FILES+=		pazo.map
TEX_MAP_FILES+=		pxfonts.map
TEX_MAP_FILES+=		txfonts.map
TEX_MAP_FILES+=		xypic.map
TEX_MAP_FILES+=		mt-belleek.map
TEX_MAP_FILES+=		urwvn.map
TEX_MAP_FILES+=		dstroke.map
TEX_MAP_FILES+=		fpls.map
TEX_MIXEDMAP_FILES+=	ttcmex.map
TEX_MIXEDMAP_FILES+=	cs.map
TEX_MIXEDMAP_FILES+=	hoekwater.map
TEX_MIXEDMAP_FILES+=	pl.map
TEX_MIXEDMAP_FILES+=	ccpl.map
TEX_MIXEDMAP_FILES+=	eurosym.map
TEX_MIXEDMAP_FILES+=	vnr.map

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive-tetex/map.mk"

post-extract:
	rm -f ${WRKSRC}/ls-R
	rmdir ${WRKSRC}/doc/generic/pdfcrop
	rm -rf ${WRKSRC}/doc/etex
	rm -f ${WRKSRC}/dvips/bluesky/config.cm*
	rm -rf ${WRKSRC}/dvips/config
	rm -rf ${WRKSRC}/dvips/tetex
	rmdir ${WRKSRC}/fonts/cmap
	rmdir ${WRKSRC}/fonts/lig
	rmdir ${WRKSRC}/fonts/map/dvipdfm/updmap
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/bsr*
	rmdir ${WRKSRC}/fonts/map/dvips/updmap
	rmdir ${WRKSRC}/fonts/map/pdftex/updmap
	rmdir ${WRKSRC}/fonts/misc
	rmdir ${WRKSRC}/fonts/opentype
	rmdir ${WRKSRC}/fonts/pk
	rmdir ${WRKSRC}/fonts/sfd
	rmdir ${WRKSRC}/fonts/truetype
	rmdir ${WRKSRC}/fonts/type3
	rmdir ${WRKSRC}/fonts/type42
	rm -rf ${WRKSRC}/fonts/enc/dvipdfm/tetex
	rm -rf ${WRKSRC}/fonts/enc/dvips/tetex
	rm -f ${WRKSRC}/fonts/map/dvipdfm/tetex/cm-dvipdfm-fix.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/dvipdfm35.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/dvips35.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/mathpple.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/mt-belleek.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/mt-plus.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/mt-yy.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/pdftex35.map
	rm -f ${WRKSRC}/fonts/map/dvips/tetex/ps2pk35.map
	rm -rf ${WRKSRC}/fonts/source/public/cm
	rm -rf ${WRKSRC}/fonts/source/public/latex
	rm -f ${WRKSRC}/fonts/source/public/misc/[b-q]*.mf
	rm -f ${WRKSRC}/fonts/source/public/misc/random.mf
	rm -f ${WRKSRC}/fonts/source/public/misc/s*.mf
	rm -rf ${WRKSRC}/fonts/tfm/public/cm
	rm -rf ${WRKSRC}/fonts/tfm/public/latex
	rm -f ${WRKSRC}/fonts/tfm/public/misc/[b-q]*.tfm
	rm -rf ${WRKSRC}/fonts/type1/bluesky/cm
	rm -rf ${WRKSRC}/fonts/type1/bluesky/latex
	rm -f ${WRKSRC}/makeindex/g*
	rm -rf ${WRKSRC}/omega/ocp/misc
	rm -rf ${WRKSRC}/omega/otp/misc
	rm -rf ${WRKSRC}/tex/generic/bghyph
	rm -f ${WRKSRC}/tex/generic/config/language.dat
	rm -f ${WRKSRC}/tex/generic/config/pdftexconfig.tex
	rm -rf ${WRKSRC}/tex/generic/german
	rm -rf ${WRKSRC}/tex/generic/hyphen
	rm -rf ${WRKSRC}/tex/generic/null
	rm -rf ${WRKSRC}/tex/generic/ruhyphen
	rm -rf ${WRKSRC}/tex/generic/texnames
	rm -rf ${WRKSRC}/tex/generic/ukrhyph
	rm -rf ${WRKSRC}/tex/latex/base
	rm -f ${WRKSRC}/tex/latex/dvipdfm/dvipdfm.def
	rm -rf ${WRKSRC}/tex/latex/config
	rm -f ${WRKSRC}/tex/plain/base/[gmp-z]*
	rm -f ${WRKSRC}/tex/plain/base/letter*
	rm -rf ${WRKSRC}/tex/plain/config
	rm -rf ${WRKSRC}/tex/plain/etex
	rm -rf ${WRKSRC}/tex/plain/fontchart
	rm -rf ${WRKSRC}/tex/plain/[i-l]*
	rm -rf ${WRKSRC}/tex/plain/mproof
	rm -rf ${WRKSRC}/tex/plain/pdfcolor
	rm -rf ${WRKSRC}/tex/plain/tetex
	rm -rf ${WRKSRC}/tex/plain/wlist
	rm -rf ${WRKSRC}/tex/plain/xepsf

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../mk/bsd.pkg.mk"
