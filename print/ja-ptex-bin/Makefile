# $NetBSD: Makefile,v 1.40 2011/01/13 13:40:12 wiz Exp $

DISTNAME=	ptex-src-${PTEX_VERS}
PKGNAME=	ja-ptex-bin-${PTEX_VERS}
PKGREVISION=	6
CATEGORIES=	print japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		ftp://ftp.ring.gr.jp/pub/text/TeX/ascii-ptex/tetex/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} # XXX
DISTFILES+=	${DF_DVIPSK_PATCH}
DISTFILES+=	mendexk${MENDEXK_VERS}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ascii.co.jp/pb/ptex/
COMMENT=	Publishing TeX (pTeX)

USE_TOOLS+=	lex

# XXX ${MAKE_VARIABLES} won't be extracted here.  strange...
SITES.dvipsk-jpatch-p1.7a.tar.gz= \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/ \
		ftp://ftp.ring.gr.jp/pub/text/TeX/ascii-ptex/dvips/
SITES.mendexk2.6d.tar.gz= \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/ \
		ftp://ftp.ring.gr.jp/pub/text/TeX/ascii-ptex/mendex/

DEPENDS+=	ja-ptex-share>=2.4nb1:../../print/ja-ptex-share
DEPENDS+=	teTeX-bin>=3.0nb26:../../print/teTeX3-bin
DEPENDS+=	teTeX-texmf>=3.0nb10:../../print/teTeX3-texmf
DEPENDS+=	tex-dvips-[0-9]*:../../print/tex-dvips

.include "../../print/teTeX3-bin/Makefile.common"

PTEX_VERS=		3.1.9
DVIPSK_PATCH_VERS=	p1.7a
MENDEXK_VERS=		2.6d

DF_TETEX_BIN= tetex-src-${TETEX_BIN_VERS}${EXTRACT_SUFX}
DF_DVIPSK_PATCH= dvipsk-jpatch-${DVIPSK_PATCH_VERS}${EXTRACT_SUFX}
DF_MENDEXK= mendexk${MENDEXK_VERS}${EXTRACT_SUFX}

WRKDIR_!=		cd ${PKGSRCDIR}/print/teTeX3-bin; \
				${MAKE} show-var VARNAME=WRKDIR
TETEX_DIR=		${WRKDIR_}/tetex-src-${TETEX_BIN_VERS}
WRKSRC=			${TETEX_DIR}
WRKSRC_PTEX=		${WRKSRC}/texk/web2c/${DISTNAME}
EXTRACT_ONLY=		# none
MAKE_ENV+=		TRUE=${TRUE}

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-local

.include "../../print/kpathsea/texmf.mk"

pre-extract:
	if [ ! -r ${WRKSRC} ]; then \
		cd ../../print/teTeX3-bin && ${MAKE} patch; \
	elif [ ! -r ${WRKSRC_PTEX} ]; then \
		cd ../../print/teTeX3-bin && ${MAKE} clean; ${MAKE} patch; \
	fi;

post-extract:
	cd ${WRKDIR_};							\
		extract_file=${_DISTDIR:Q}/${DF_TETEX_BIN:Q};		\
		${EXTRACT_CMD}
	cd ${WRKSRC}/texk/web2c;					\
		extract_file=${_DISTDIR:Q}/${DISTNAME:Q}${EXTRACT_SUFX}; \
		${EXTRACT_CMD}
	cd ${WRKSRC}/texk;						\
		extract_file=${_DISTDIR:Q}/${DF_DVIPSK_PATCH:Q};	\
		${EXTRACT_CMD}
	cd ${WRKSRC}/texk;						\
		extract_file=${_DISTDIR:Q}/${DF_MENDEXK:Q};		\
		${EXTRACT_CMD}
	${RM} -f ${WRKSRC}/texmf
	${LN} -s ${LOCALBASE}/share/texmf ${WRKSRC}
	${LN} -s ${LOCALBASE}/share/texmf-local ${WRKSRC}

pre-patch:
	${PATCH} -d ${WRKSRC}/texk -p0 -s \
		< ${WRKSRC}/texk/dvipsk-${DVIPSK_PATCH_VERS}.patch

post-patch:
	${MV} ${WRKSRC}/texk/kpathsea/texmf.in \
		${WRKSRC}/texk/kpathsea/texmf.in.orig
	${SED} -e 's,@texmfsite@,${TEXMFSITE},' \
		-e 's,@texmflocal@,${PREFIX}/share/texmf-local,' \
		${WRKSRC}/texk/kpathsea/texmf.in.orig > \
		${WRKSRC}/texk/kpathsea/texmf.in

post-configure:
	cd ${WRKSRC_PTEX}; ./configure EUC ${PREFIX}/share/texmf-local

do-build:
	cd ${WRKSRC}/texk/web2c; ${MAKE_PROGRAM}
	cd ${WRKSRC_PTEX}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	cd ${WRKSRC}/texk/dvipsk; ${MAKE_PROGRAM}
	cd ${WRKSRC}/texk/mendexk${MENDEXK_VERS}; \
		./configure EUC; ${MAKE_PROGRAM} # This needs libkpathsea.a

do-install:
	cd ${WRKSRC_PTEX}; \
		${SETENV} texmflcl=${PREFIX}/share/texmf-local ${MAKE_PROGRAM} install
	cd ${WRKSRC}/texk/dvipsk; \
		${SETENV} texmflcl=${PREFIX}/share/texmf-local ${MAKE_PROGRAM} install; \
	${INSTALL_DATA} psfonts.map ${PREFIX}/share/texmf-local/dvips/base
	${INSTALL_PROGRAM} ${WRKSRC}/texk/mendexk${MENDEXK_VERS}/mendex \
		${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf-local/dvips/pstricks
	cd ${PREFIX}/share/texmf-local/dvips/pstricks; \
		${CP} ${LOCALBASE}/share/texmf-dist/dvips/pstricks/pst-text.pro .; \
		${PATCH} < ${WRKSRC}/texk/PSTricks.patch; \
		${RM} -f pst-text.pro.orig

pre-clean:
	cd ../../print/teTeX3-bin && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
