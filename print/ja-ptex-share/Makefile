# $NetBSD: Makefile,v 1.9 2005/05/16 01:15:32 jlam Exp $

DISTNAME=	ptex-texmf-2.1
PKGNAME=	ja-ptex-share-2.1
PKGREVISION=	2
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

DEPENDS+=	teTeX>=2.0.1:../../print/teTeX

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		teTeX
NO_CONFIGURE=		YES
NO_BUILD=		YES
TEXMFLOCAL=		${PREFIX}/share/texmf.local
.if !defined(EXTRACT_USING_PAX)
PKGSRC_USE_TOOLS+=	gtar
.endif

do-install:
	${INSTALL_DATA_DIR} ${TEXMFLOCAL}
.if defined(EXTRACT_USING_PAX)
	cd ${TEXMFLOCAL} && \
		${PAX} -O -zrf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}
	cd ${TEXMFLOCAL}/fonts && \
	for f in jis nmin-ngoth standard morisawa; do \
		${PAX} -O -zrf ${DISTDIR}/${DIST_SUBDIR}/$$f${EXTRACT_SUFX}; \
		${MV} ${TEXMFLOCAL}/fonts/$$f/tfm ${TEXMFLOCAL}/fonts/tfm/$$f;\
		${MV} ${TEXMFLOCAL}/fonts/$$f/vf ${TEXMFLOCAL}/fonts/vf/$$f;\
	done
.else
	cd ${TEXMFLOCAL} && \
		${GTAR} -zxpf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}
	cd ${TEXMFLOCAL}/fonts && \
	for f in jis nmin-ngoth standard morisawa; do \
		${GTAR} -zxpf ${DISTDIR}/${DIST_SUBDIR}/$$f${EXTRACT_SUFX}; \
		${MV} ${TEXMFLOCAL}/fonts/$$f/tfm ${TEXMFLOCAL}/fonts/tfm/$$f;\
		${MV} ${TEXMFLOCAL}/fonts/$$f/vf ${TEXMFLOCAL}/fonts/vf/$$f;\
	done
.endif

.include "../../mk/bsd.pkg.mk"
