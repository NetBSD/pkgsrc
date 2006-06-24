# $NetBSD: Makefile,v 1.20 2006/06/24 10:48:06 hira Exp $

DISTNAME=	ptex-texmf-2.4
PKGNAME=	ja-ptex-share-2.4
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

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.ascii.co.jp/pb/ptex/
COMMENT=	Library files for pTeX

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_DIRS+=	texmf-1.3

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/bibtex/bib/jbibtex
	${INSTALL_DATA} ${WRKSRC}/jbibtex/bib/jxampl.bib \
		${PKG_LOCALTEXMFPREFIX}/bibtex/bib/jbibtex
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/bibtex/bst/jbibtex
	${INSTALL_DATA} ${WRKSRC}/jbibtex/bst/* \
		${PKG_LOCALTEXMFPREFIX}/bibtex/bst/jbibtex
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/bibtex/jbibtex
	${INSTALL_DATA} ${WRKSRC}/doc/jbibtex/doc-ascii/* \
		${PKG_LOCALTEXMFPREFIX}/doc/bibtex/jbibtex
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/ptex
	${INSTALL_DATA} ${WRKSRC}/doc/ptex/* ${PKG_LOCALTEXMFPREFIX}/doc/ptex
.for f in COPYRIGHT COPYRIGHT.jis Changes.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/doc/ptex
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/ptex
.for type in plain platex
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/ptex/${type}
.  for dir in base config
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/ptex/${type}/${dir}
	${INSTALL_DATA} ${WRKSRC}/ptex/${type}/${dir}/* \
		${PKG_LOCALTEXMFPREFIX}/ptex/${type}/${dir}
.  endfor
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/fonts/jis
	${INSTALL_DATA} ${WRKSRC}/jis/README.txt \
		${PKG_LOCALTEXMFPREFIX}/doc/fonts/jis
.for font in morisawa nmin-ngoth
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/fonts/${font}
.  for f in COPYRIGHT COPYRIGHT.jis README.txt
	${INSTALL_DATA} ${WRKSRC}/${font}/${f} \
		${PKG_LOCALTEXMFPREFIX}/doc/fonts/${font}
.  endfor
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/fonts/ptex-standard
.  for f in COPYRIGHT COPYRIGHT.jis README.txt
	${INSTALL_DATA} ${WRKSRC}/standard/${f} \
		${PKG_LOCALTEXMFPREFIX}/doc/fonts/ptex-standard
.  endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/map/dvips/ptex
.for font in jis morisawa nmin-ngoth
	${INSTALL_DATA} ${WRKSRC}/${font}/*.map \
		${PKG_LOCALTEXMFPREFIX}/fonts/map/dvips/ptex
.endfor
.for type in source tfm vf
.  for font in ascgrp ptex
.    if exists(${WRKSRC}/fonts/${type}/${font})
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/${type}/${font}
	${INSTALL_DATA} ${WRKSRC}/fonts/${type}/${font}/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/${type}/${font}
.    endif
.  endfor
.endfor
.for font in jis morisawa nmin-ngoth
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/${font}
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/${font}/dvips
	${INSTALL_DATA} ${WRKSRC}/${font}/tfm/dvips/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/tfm/${font}/dvips
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/${font}/ptex
	${INSTALL_DATA} ${WRKSRC}/${font}/tfm/ptex/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/tfm/${font}/ptex
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/ptex-standard
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/ptex-standard/dvips
	${INSTALL_DATA} ${WRKSRC}/standard/tfm/dvips/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/tfm/ptex-standard/dvips
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/ptex-standard/ptex
	${INSTALL_DATA} ${WRKSRC}/standard/tfm/ptex/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/tfm/ptex-standard/ptex
.for font in jis morisawa nmin-ngoth
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/vf/${font}
	${INSTALL_DATA} ${WRKSRC}/${font}/vf/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/vf/${font}
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/vf/ptex-standard
	${INSTALL_DATA} ${WRKSRC}/standard/vf/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/vf/ptex-standard

.include "../../mk/bsd.pkg.mk"
