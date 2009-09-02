# $NetBSD: Makefile,v 1.22 2009/09/02 08:34:14 wiz Exp $

DISTNAME=	ptex-texmf-2.4
PKGNAME=	ja-ptex-share-2.4
PKGREVISION=	1
CATEGORIES=	print japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/ \
		http://www.ring.gr.jp/pub/text/TeX/ascii-ptex/tetex/ \
		http://www.ring.gr.jp/pub/text/TeX/ascii-ptex/jvf/
DISTFILES=	ptex-texmf-2.4${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX} \
		nmin-ngoth${EXTRACT_SUFX} \
		standard${EXTRACT_SUFX} \
		morisawa${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ascii.co.jp/pb/ptex/
COMMENT=	Library files for pTeX

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
NO_CONFIGURE=	YES
NO_BUILD=	YES

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf
TEXMFPREFIX=	${DESTDIR}${PREFIX}/share/texmf

.include "../../print/kpathsea/texmf.mk"

do-install:
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/bibtex/bib/jbibtex
	${INSTALL_DATA} ${WRKSRC}/jbibtex/bib/jxampl.bib \
		${TEXMFPREFIX}/bibtex/bib/jbibtex
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/bibtex/bst/jbibtex
	${INSTALL_DATA} ${WRKSRC}/jbibtex/bst/* \
		${TEXMFPREFIX}/bibtex/bst/jbibtex
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/doc/bibtex/jbibtex
	${INSTALL_DATA} ${WRKSRC}/doc/jbibtex/doc-ascii/* \
		${TEXMFPREFIX}/doc/bibtex/jbibtex
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/doc/ptex
	${INSTALL_DATA} ${WRKSRC}/doc/ptex/* ${TEXMFPREFIX}/doc/ptex
.for f in COPYRIGHT COPYRIGHT.jis Changes.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${TEXMFPREFIX}/doc/ptex
.endfor
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/ptex
.for type in plain platex
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/ptex/${type}
.  for dir in base config
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/ptex/${type}/${dir}
	${INSTALL_DATA} ${WRKSRC}/ptex/${type}/${dir}/* \
		${TEXMFPREFIX}/ptex/${type}/${dir}
.  endfor
.endfor
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/doc/fonts/jis
	${INSTALL_DATA} ${WRKSRC}/jis/README.txt \
		${TEXMFPREFIX}/doc/fonts/jis
.for font in morisawa nmin-ngoth
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/doc/fonts/${font}
.  for f in COPYRIGHT COPYRIGHT.jis README.txt
	${INSTALL_DATA} ${WRKSRC}/${font}/${f} \
		${TEXMFPREFIX}/doc/fonts/${font}
.  endfor
.endfor
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/doc/fonts/ptex-standard
.  for f in COPYRIGHT COPYRIGHT.jis README.txt
	${INSTALL_DATA} ${WRKSRC}/standard/${f} \
		${TEXMFPREFIX}/doc/fonts/ptex-standard
.  endfor
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/map/dvips/ptex
.for font in jis morisawa nmin-ngoth
	${INSTALL_DATA} ${WRKSRC}/${font}/*.map \
		${TEXMFPREFIX}/fonts/map/dvips/ptex
.endfor
.for type in source tfm
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/${type}/ascgrp
	${INSTALL_DATA} ${WRKSRC}/fonts/${type}/ascgrp/* \
		${TEXMFPREFIX}/fonts/${type}/ascgrp
.endfor
.for type in source tfm vf
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/${type}/ptex
	${INSTALL_DATA} ${WRKSRC}/fonts/${type}/ptex/* \
		${TEXMFPREFIX}/fonts/${type}/ptex
.endfor
.for font in jis morisawa nmin-ngoth
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/tfm/${font}
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/tfm/${font}/dvips
	${INSTALL_DATA} ${WRKSRC}/${font}/tfm/dvips/* \
		${TEXMFPREFIX}/fonts/tfm/${font}/dvips
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/tfm/${font}/ptex
	${INSTALL_DATA} ${WRKSRC}/${font}/tfm/ptex/* \
		${TEXMFPREFIX}/fonts/tfm/${font}/ptex
.endfor
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/tfm/ptex-standard
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/tfm/ptex-standard/dvips
	${INSTALL_DATA} ${WRKSRC}/standard/tfm/dvips/* \
		${TEXMFPREFIX}/fonts/tfm/ptex-standard/dvips
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/tfm/ptex-standard/ptex
	${INSTALL_DATA} ${WRKSRC}/standard/tfm/ptex/* \
		${TEXMFPREFIX}/fonts/tfm/ptex-standard/ptex
.for font in jis morisawa nmin-ngoth
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/vf/${font}
	${INSTALL_DATA} ${WRKSRC}/${font}/vf/* \
		${TEXMFPREFIX}/fonts/vf/${font}
.endfor
	${INSTALL_DATA_DIR} ${TEXMFPREFIX}/fonts/vf/ptex-standard
	${INSTALL_DATA} ${WRKSRC}/standard/vf/* \
		${TEXMFPREFIX}/fonts/vf/ptex-standard

.include "../../mk/bsd.pkg.mk"
