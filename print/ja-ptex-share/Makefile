# $NetBSD: Makefile,v 1.19 2006/02/05 23:10:37 joerg Exp $

DISTNAME=	ptex-texmf-2.1
PKGNAME=	ja-ptex-share-2.1
PKGREVISION=	4
CATEGORIES=	print japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/ \
		http://www.ring.gr.jp/pub/text/TeX/ascii-ptex/tetex/ \
		http://www.ring.gr.jp/pub/text/TeX/ascii-ptex/jvf/
DISTFILES=	ptex-texmf-2.1${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX} \
		nmin-ngoth${EXTRACT_SUFX} \
		standard${EXTRACT_SUFX} \
		morisawa${EXTRACT_SUFX}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.ascii.co.jp/pb/ptex/
COMMENT=	Library files for pTeX

#TEX_ACCEPTED=	teTeX2
.include "../../print/teTeX-bin/buildlink3.mk"

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		teTeX
NO_CONFIGURE=		YES
NO_BUILD=		YES
TEXMFLOCAL=		${PREFIX}/share/texmf.local

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${TEXMFLOCAL}
	cd ${TEXMFLOCAL};						\
		extract_file=${_DISTDIR:Q}/${DISTNAME:Q}${EXTRACT_SUFX}; \
		${EXTRACT_CMD}
	cd ${TEXMFLOCAL}/fonts;						\
	for f in jis nmin-ngoth standard morisawa; do			\
		extract_file=${_DISTDIR:Q}/$$f${EXTRACT_SUFX};		\
		${EXTRACT_CMD};						\
		${MV} ${TEXMFLOCAL}/fonts/$$f/tfm ${TEXMFLOCAL}/fonts/tfm/$$f; \
		${MV} ${TEXMFLOCAL}/fonts/$$f/vf ${TEXMFLOCAL}/fonts/vf/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
