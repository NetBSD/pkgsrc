# $NetBSD: Makefile,v 1.10 2008/05/26 02:13:18 joerg Exp $
#

DISTNAME=	fonts-unttf-20070507
PKGNAME=	${DISTNAME:S/fonts-unttf-/tex-unttf-1.0.1./}
CATEGORIES=	fonts
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/hangul-ucs/fonts/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/Hangul-ucs
COMMENT=	TeX fonts based on Un fonts

DEPENDS+=	ttf2pk>=1.5:../../fonts/ttf2pk
DEPENDS+=	un-core-ttf>=1.0:../../fonts/un-core-ttf
DEPENDS+=	un-extra-ttf>=1.0.1:../../fonts/un-extra-ttf

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fonts-unttf
USE_DIRS+=	texmf-1.0
USE_TOOLS+=	pax
NO_CONFIGURE=	yes

TEX_FONTMAPS=		unttf-pdftex-dhucs.map
DVIPDFMX_FONTMAPS=	cid-unttf-dhucs.map

.include "../../print/dvipdfmx/map.mk"
.include "../../print/teTeX/module.mk"

SYSTTFDIR=	${LOCALBASE}/lib/X11/fonts/TTF
TEXTTFDIR=	${PKG_LOCALTEXMFPREFIX}/fonts/truetype/unttf

do-build:
	${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/
	cd ${WRKSRC}/fonts; pax -rw . ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unbt
	${LN} -sf ${SYSTTFDIR}/UnBatang.ttf ${DESTDIR}${TEXTTFDIR}/unbt/
	${LN} -sf ${SYSTTFDIR}/UnBatangBold.ttf ${DESTDIR}${TEXTTFDIR}/unbt/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/ungt
	${LN} -sf ${SYSTTFDIR}/UnDotum.ttf ${DESTDIR}${TEXTTFDIR}/ungt/
	${LN} -sf ${SYSTTFDIR}/UnDotumBold.ttf ${DESTDIR}${TEXTTFDIR}/ungt/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/ungr
	${LN} -sf ${SYSTTFDIR}/UnGraphic.ttf ${DESTDIR}${TEXTTFDIR}/ungr/
	${LN} -sf ${SYSTTFDIR}/UnGraphicBold.ttf ${DESTDIR}${TEXTTFDIR}/ungr/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/ungs
	${LN} -sf ${SYSTTFDIR}/UnGungseo.ttf ${DESTDIR}${TEXTTFDIR}/ungs/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unbm
	${LN} -sf ${SYSTTFDIR}/UnBom.ttf ${DESTDIR}${TEXTTFDIR}/unbm/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unpn
	${LN} -sf ${SYSTTFDIR}/UnPen.ttf ${DESTDIR}${TEXTTFDIR}/unpn/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unph
	${LN} -sf ${SYSTTFDIR}/UnPenheulim.ttf ${DESTDIR}${TEXTTFDIR}/unph/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unpg
	${LN} -sf ${SYSTTFDIR}/UnPilgi.ttf ${DESTDIR}${TEXTTFDIR}/unpg/
	${LN} -sf ${SYSTTFDIR}/UnPilgiBold.ttf ${DESTDIR}${TEXTTFDIR}/unpg/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unsh
	${LN} -sf ${SYSTTFDIR}/UnShinmun.ttf ${DESTDIR}${TEXTTFDIR}/unsh/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/untz
	${LN} -sf ${SYSTTFDIR}/UnTaza.ttf ${DESTDIR}${TEXTTFDIR}/untz/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unyt
	${LN} -sf ${SYSTTFDIR}/UnYetgul.ttf ${DESTDIR}${TEXTTFDIR}/unyt/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unjbt
	${LN} -sf ${SYSTTFDIR}/UnJamoBatang.ttf ${DESTDIR}${TEXTTFDIR}/unjbt/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unjgt
	${LN} -sf ${SYSTTFDIR}/UnJamoDotum.ttf ${DESTDIR}${TEXTTFDIR}/unjgt/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unjnv
	${LN} -sf ${SYSTTFDIR}/UnJamoNovel.ttf ${DESTDIR}${TEXTTFDIR}/unjnv/
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXTTFDIR}/unjsr
	${LN} -sf ${SYSTTFDIR}/UnJamoSora.ttf ${DESTDIR}${TEXTTFDIR}/unjsr/

.include "../../mk/bsd.pkg.mk"
