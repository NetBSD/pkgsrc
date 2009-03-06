# $NetBSD: Makefile,v 1.24 2009/03/06 20:41:02 minskim Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
PKGREVISION=	10
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org,pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

CONFLICTS+=	teTeX-share-[0-9]*
DEPENDS+=	tex-bin-kpathsea-[0-9]*:../../print/tex-bin-kpathsea

EXTRACT_ELEMENTS+=	ChangeLog
EXTRACT_ELEMENTS+=	LICENSE.texmf
EXTRACT_ELEMENTS+=	aliases
EXTRACT_ELEMENTS+=	bibtex
EXTRACT_ELEMENTS+=	context
EXTRACT_ELEMENTS+=	doc
EXTRACT_ELEMENTS+=	dvipdfm
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

TEX_HYPHEN_DAT+=	french frhyph.tex
TEX_HYPHEN_DAT+=	= patois
TEX_HYPHEN_DAT+=	german dehypht.tex
TEX_HYPHEN_DAT+=	= austrian
TEX_HYPHEN_DAT+=	ngerman dehyphn.tex
TEX_HYPHEN_DAT+=	= naustrian
TEX_HYPHEN_DAT+=	bahasa inhyph.tex
TEX_HYPHEN_DAT+=	basque	bahyph.tex
TEX_HYPHEN_DAT+=	bulgarian bghyphen.tex
TEX_HYPHEN_DAT+=	catalan cahyph.tex
TEX_HYPHEN_DAT+=	croatian hrhyph.tex
TEX_HYPHEN_DAT+=	czech czhyph.tex
TEX_HYPHEN_DAT+=	danish dkhyphen.tex
TEX_HYPHEN_DAT+=	dutch nehyph.tex
TEX_HYPHEN_DAT+=	esperanto eohyph.tex
TEX_HYPHEN_DAT+=	estonian eehyph.tex
TEX_HYPHEN_DAT+=	finnish fi8hyph.tex
TEX_HYPHEN_DAT+=	greek grhyph.tex
TEX_HYPHEN_DAT+=	icelandic icehyph.tex
TEX_HYPHEN_DAT+=	irish gahyph.tex
TEX_HYPHEN_DAT+=	italian ithyph.tex
TEX_HYPHEN_DAT+=	latin lahyph.tex
TEX_HYPHEN_DAT+=	magyar huhyphn.tex
TEX_HYPHEN_DAT+=	norsk nohyphbx.tex
TEX_HYPHEN_DAT+=	polish plhyph.tex
TEX_HYPHEN_DAT+=	portuges pt8hyph.tex
TEX_HYPHEN_DAT+=	romanian rohyphen.tex
TEX_HYPHEN_DAT+=	russian ruhyphen.tex
TEX_HYPHEN_DAT+=	serbian srhyphc.tex
TEX_HYPHEN_DAT+=	slovak skhyph.tex
TEX_HYPHEN_DAT+=	slovene sihyph23.tex
TEX_HYPHEN_DAT+=	spanish eshyph.tex
TEX_HYPHEN_DAT+=	swedish sehyph.tex
TEX_HYPHEN_DAT+=	turkish trhyph.tex
TEX_HYPHEN_DAT+=	ukrainian ukrhyph.tex
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
TEX_MIXEDMAP_FILES+=	bsr.map
TEX_MIXEDMAP_FILES+=	bsr-interpolated.map
TEX_MIXEDMAP_FILES+=	cs.map
TEX_MIXEDMAP_FILES+=	hoekwater.map
TEX_MIXEDMAP_FILES+=	pl.map
TEX_MIXEDMAP_FILES+=	ccpl.map
TEX_MIXEDMAP_FILES+=	eurosym.map
TEX_MIXEDMAP_FILES+=	vnr.map

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive-tetex/hyphen.mk"
.include "../../print/texlive-tetex/map.mk"

post-extract:
	rm -f ${WRKSRC}/ls-R
	rmdir ${WRKSRC}/doc/generic/pdfcrop
	rm -rf ${WRKSRC}/dvips/config
	rm -rf ${WRKSRC}/dvips/tetex
	rmdir ${WRKSRC}/fonts/cmap
	rmdir ${WRKSRC}/fonts/lig
	rmdir ${WRKSRC}/fonts/map/dvipdfm/updmap
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
	rm -f ${WRKSRC}/tex/generic/config/language.dat
	rm -f ${WRKSRC}/tex/generic/hyphen/dumyhyph.tex
	rm -f ${WRKSRC}/tex/generic/hyphen/hyphen.tex
	rm -f ${WRKSRC}/tex/generic/hyphen/hypht1.tex
	rm -f ${WRKSRC}/tex/generic/hyphen/zerohyph.tex
	rm -f ${WRKSRC}/tex/plain/config/language.def

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../mk/bsd.pkg.mk"
