# $NetBSD: Makefile,v 1.1.1.1 2003/03/15 20:00:27 kei Exp $

DISTNAME=	ptex-src-${PTEX_VERS}
PKGNAME=	ja-ptex-bin-${PTEX_VERS}
CATEGORIES=	print japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		ftp://ring.gr.jp/pub/text/TeX/ascii-ptex/tetex/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} # XXX
DISTFILES+=	${DF_DVIPSK_PATCH}
DISTFILES+=	mendexk${MENDEXK_VERS}${EXTRACT_SUFX}

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.ascii.co.jp/pb/ptex/
COMMENT=	publising TeX (pTeX)

# XXX ${MAKE_VARIABLES} won't be extracted here.  strange...
SITES_dvipsk-jpatch-p1.6.tar.gz= \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/ \
		ftp://ring.gr.jp/pub/text/TeX/ascii-ptex/dvips/
SITES_mendexk2.5.tar.gz= \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/ \
		ftp://ring.gr.jp/pub/text/TeX/ascii-ptex/mendex/

DEPENDS+=	ja-ptex-share>=2.1:../../print/ja-ptex-share

.include "../../print/teTeX2-bin/Makefile.common"

PTEX_VERS=		3.1.2
DVIPSK_PATCH_VERS=	p1.6
MENDEXK_VERS=		2.5

DF_TETEX_BIN= tetex-src-${TETEX_BIN_VERS}${EXTRACT_SUFX}
DF_DVIPSK_PATCH= dvipsk-jpatch-${DVIPSK_PATCH_VERS}${EXTRACT_SUFX}
DF_MENDEXK= mendexk${MENDEXK_VERS}${EXTRACT_SUFX}

WRKDIR_=		${_PKGSRCDIR}/print/teTeX2-bin/${WRKDIR:T}
TETEX_DIR=		${WRKDIR_}/tetex-src-${TETEX_BIN_VERS}
WRKSRC=			${TETEX_DIR}
WRKSRC_PTEX=		${WRKSRC}/texk/web2c/${DISTNAME:S/-src//}
EXTRACT_ONLY=		# none

TEXMF=			${PREFIX}/share/texmf
TEXMFLOCAL=		${PREFIX}/share/texmf.local
FILES_SUBST+=		TEXMFLOCAL=${TEXMFLOCAL}
FILES_SUBST+=		TEXMFSITE=${TEXMFSITE}
FILES_SUBST+=		WRKDIR_=${WRKDIR_}
#FILES_SUBST+=		FILESDIR=${FILESDIR}
FILES_SUBST+=		PATCH=${PATCH}

pre-extract:
	if [ ! -e ${WRKSRC} ]; then \
		cd ../../print/teTeX2-bin && ${MAKE} patch; \
	elif [ ! -e ${WRKSRC_PTEX} ]; then \
		cd ../../print/teTeX2-bin && ${MAKE} clean; ${MAKE} patch; \
	fi;

post-extract:
.if defined(EXTRACT_USING_PAX)
	cd ${WRKDIR_}; \
	${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DF_TETEX_BIN} | ${PAX} -r
	cd ${WRKSRC}/texk/web2c; \
	${DECOMPRESS_CMD} \
		${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		| ${PAX} -r; \
	cd ${WRKSRC}/texk; \
	${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DF_DVIPSK_PATCH} \
		| ${PAX} -r; \
	${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DF_MENDEXK} | ${PAX} -r
.else
	cd ${WRKDIR_}; \
	${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DF_TETEX_BIN} \
		| ${GTAR} -xpf -
	cd ${WRKSRC}/texk/web2c; \
	${DECOMPRESS_CMD} \
		${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		| ${GTAR} -xpf -; \
	cd ${WRKSRC}/texk; \
	${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DF_DVIPSK_PATCH} \
		| ${GTAR} -xpf -; \
	${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DF_MENDEXK} \
		| ${GTAR} -xpf -
.endif
	${SED} -e "s|\$$TEXMF/ptex/plain/||" \
	${LOCALBASE}/share/texmf.local/ptex/plain/base/ptex.tex > \
		${WRKSRC_PTEX}/ptex.tex
	${RM} -f ${WRKSRC}/texmf ${WRKSRC}/texmf.local
	${LN} -s ${LOCALBASE}/share/texmf ${WRKSRC}
	${LN} -s ${LOCALBASE}/share/texmf.local ${WRKSRC}

pre-patch:
	${PATCH} -d ${WRKSRC}/texk -p0 -s \
		< ${WRKSRC}/texk/dvipsk-5.92b-${DVIPSK_PATCH_VERS}.patch

post-patch:
	${MV} ${WRKSRC}/texk/kpathsea/texmf.in \
		${WRKSRC}/texk/kpathsea/texmf.in.orig
	${SED} -e 's,@texmfsite@,${TEXMFSITE},' \
		-e 's,@texmflocal@,${TEXMFLOCAL},' \
		${WRKSRC}/texk/kpathsea/texmf.in.orig > \
		${WRKSRC}/texk/kpathsea/texmf.in

post-configure:
	cd ${WRKSRC_PTEX}; ./configure EUC ${TEXMFLOCAL}

do-build:
	cd ${WRKSRC}/texk/web2c; ${MAKE_PROGRAM}
	cd ${WRKSRC_PTEX}; ${MAKE_PROGRAM}
	cd ${WRKSRC}/texk/dvipsk; ${MAKE_PROGRAM}
	cd ${WRKSRC}/texk/mendexk${MENDEXK_VERS}; ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC_PTEX}; \
		${SETENV} texmflcl=${TEXMFLOCAL} ${MAKE_PROGRAM} install
	cd ${WRKSRC}/texk/dvipsk; \
		${SETENV} texmflcl=${TEXMFLOCAL} ${MAKE_PROGRAM} install; \
	${INSTALL_DATA} psfonts.map ${TEXMFLOCAL}/dvips/base
	${INSTALL_PROGRAM} ${WRKSRC}/texk/mendexk${MENDEXK_VERS}/mendex \
		${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/texk/PSTricks.patch ${TEXMF}/dvips/pstricks

pre-clean:
	cd ../../print/teTeX2-bin && ${MAKE} clean

.include "../../print/teTeX2-bin/kpathsea.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
