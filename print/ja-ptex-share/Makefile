# $NetBSD: Makefile,v 1.1.1.1 2003/03/15 20:02:49 kei Exp $

DISTNAME=	ptex-texmf-2.1
PKGNAME=	ja-ptex-share-2.1
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

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.ascii.co.jp/pb/ptex/
COMMENT=	library files for pTeX

DEPENDS+=	teTeX2>=2.0.1:../../print/teTeX2

DIST_SUBDIR=		teTeX
WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES
NO_BUILD=		YES
TEXMFLOCAL=		${PREFIX}/share/texmf.local

do-install:
	${INSTALL_DATA_DIR} ${TEXMFLOCAL}
.if defined(EXTRACT_USING_PAX)
	cd ${TEXMFLOCAL}; \
	${DECOMPRESS_CMD} \
	${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} | ${PAX} -r
	cd ${TEXMFLOCAL}/fonts; \
	for f in jis nmin-ngoth standard morisawa; do \
		${DECOMPRESS_CMD} \
		${DISTDIR}/${DIST_SUBDIR}/$$f${EXTRACT_SUFX} | ${PAX} -r; \
		${MV} ${TEXMFLOCAL}/fonts/$$f/tfm ${TEXMFLOCAL}/fonts/tfm/$$f;\
		${MV} ${TEXMFLOCAL}/fonts/$$f/vf ${TEXMFLOCAL}/fonts/vf/$$f;\
	done
.else
	cd ${TEXMFLOCAL}; \
	${DECOMPRESS_CMD} \
	${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} | ${GTAR} -xpf -
	cd ${TEXMFLOCAL}/fonts; \
	for f in jis nmin-ngoth standard morisawa; do \
		${DECOMPRESS_CMD} \
		${DISTDIR}/${DIST_SUBDIR}/$$f${EXTRACT_SUFX} | ${GTAR} -xpf -;\
		${MV} ${TEXMFLOCAL}/fonts/$$f/tfm ${TEXMFLOCAL}/fonts/tfm/$$f;\
		${MV} ${TEXMFLOCAL}/fonts/$$f/vf ${TEXMFLOCAL}/fonts/vf/$$f;\
	done
.endif

.include "../../mk/bsd.pkg.mk"
