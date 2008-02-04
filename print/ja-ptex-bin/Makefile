# $NetBSD: Makefile,v 1.34 2008/02/04 20:10:34 tnn Exp $

DISTNAME=	ptex-src-${PTEX_VERS}
PKGNAME=	ja-ptex-bin-${PTEX_VERS}
PKGREVISION=	1
CATEGORIES=	print japanese
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		ftp://ftp.ring.gr.jp/pub/text/TeX/ascii-ptex/tetex/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} # XXX
DISTFILES+=	${DF_DVIPSK_PATCH}
DISTFILES+=	mendexk${MENDEXK_VERS}${EXTRACT_SUFX}

MAINTAINER=	kei@NetBSD.org
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

DEPENDS+=	ja-ptex-share>=2.4:../../print/ja-ptex-share

USE_DIRS+=	texmf-1.3

.include "../../print/teTeX3-bin/buildlink3.mk"
.include "../../print/teTeX3-bin/Makefile.common"
.include "../../print/teTeX/module.mk"

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
	${SED} -e "s|\$$PKG_TEXMFPREFIX/ptex/plain/||" \
	${PKG_LOCALTEXMFPREFIX}/ptex/plain/base/ptex.tex > \
		${WRKSRC_PTEX}/ptex.tex
	${RM} -f ${WRKSRC}/texmf
	${LN} -s ${PKG_TEXMFPREFIX} ${WRKSRC}
	${LN} -s ${PKG_LOCALTEXMFPREFIX} ${WRKSRC}

pre-patch:
	${PATCH} -d ${WRKSRC}/texk -p0 -s \
		< ${WRKSRC}/texk/dvipsk-${DVIPSK_PATCH_VERS}.patch

post-patch:
	${MV} ${WRKSRC}/texk/kpathsea/texmf.in \
		${WRKSRC}/texk/kpathsea/texmf.in.orig
	${SED} -e 's,@texmfsite@,${TEXMFSITE},' \
		-e 's,@texmflocal@,${PKG_LOCALTEXMFPREFIX},' \
		${WRKSRC}/texk/kpathsea/texmf.in.orig > \
		${WRKSRC}/texk/kpathsea/texmf.in

post-configure:
	cd ${WRKSRC_PTEX}; ./configure EUC ${PKG_LOCALTEXMFPREFIX}

do-build:
	cd ${WRKSRC}/texk/web2c; ${MAKE_PROGRAM}
	cd ${WRKSRC_PTEX}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	cd ${WRKSRC}/texk/dvipsk; ${MAKE_PROGRAM}
	cd ${WRKSRC}/texk/mendexk${MENDEXK_VERS}; \
		./configure EUC; ${MAKE_PROGRAM} # This needs libkpathsea.a

do-install:
	cd ${WRKSRC_PTEX}; \
		${SETENV} texmflcl=${PKG_LOCALTEXMFPREFIX} ${MAKE_PROGRAM} install
	cd ${WRKSRC}/texk/dvipsk; \
		${SETENV} texmflcl=${PKG_LOCALTEXMFPREFIX} ${MAKE_PROGRAM} install; \
	${INSTALL_DATA} psfonts.map ${PKG_LOCALTEXMFPREFIX}/dvips/base
	${INSTALL_PROGRAM} ${WRKSRC}/texk/mendexk${MENDEXK_VERS}/mendex \
		${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/dvips/pstricks
	cd ${PKG_LOCALTEXMFPREFIX}/dvips/pstricks; \
		${CP} ${PKG_TEXMFPREFIX}-dist/dvips/pstricks/pst-text.pro .; \
		${PATCH} < ${WRKSRC}/texk/PSTricks.patch; \
		${RM} -f pst-text.pro.orig

pre-clean:
	cd ../../print/teTeX3-bin && ${MAKE} clean

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
