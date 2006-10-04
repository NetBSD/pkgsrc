# $NetBSD: Makefile,v 1.7 2006/10/04 21:39:31 wiz Exp $
#

DISTNAME=	fonts-unttf-20060215
PKGNAME=	${DISTNAME:S/fonts-unttf-/tex-unttf-1.0.1./}
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/hangul-ucs/fonts/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/Hangul-ucs
COMMENT=	TeX fonts based on Un fonts

DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk
DEPENDS+=	un-core-ttf>=1.0:../../fonts/un-core-ttf
DEPENDS+=	un-extra-ttf>=1.0.1:../../fonts/un-extra-ttf

WRKSRC=		${WRKDIR}/fonts-unttf
USE_DIRS+=	texmf-1.0
NO_CONFIGURE=	yes

TEX_FONTMAPS=		unttf-pdftex.map
DVIPDFMX_FONTMAPS=	cid-unttf.map

.include "../../print/dvipdfmx/map.mk"
.include "../../print/teTeX/module.mk"

SYSTTFDIR=	${LOCALBASE}/lib/X11/fonts/TTF
TEXTTFDIR=	${PKG_LOCALTEXMFPREFIX}/fonts/truetype/unttf

do-build:
	${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

do-install:
	cd ${WRKSRC}/fonts; ${PAX} -rw . ${PKG_LOCALTEXMFPREFIX}/fonts/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unbt
	${LN} -sf ${SYSTTFDIR}/UnBatang.ttf ${TEXTTFDIR}/unbt/
	${LN} -sf ${SYSTTFDIR}/UnBatangBold.ttf ${TEXTTFDIR}/unbt/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/ungt
	${LN} -sf ${SYSTTFDIR}/UnDotum.ttf ${TEXTTFDIR}/ungt/
	${LN} -sf ${SYSTTFDIR}/UnDotumBold.ttf ${TEXTTFDIR}/ungt/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/ungr
	${LN} -sf ${SYSTTFDIR}/UnGraphic.ttf ${TEXTTFDIR}/ungr/
	${LN} -sf ${SYSTTFDIR}/UnGraphicBold.ttf ${TEXTTFDIR}/ungr/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/ungs
	${LN} -sf ${SYSTTFDIR}/UnGungseo.ttf ${TEXTTFDIR}/ungs/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unbm
	${LN} -sf ${SYSTTFDIR}/UnBom.ttf ${TEXTTFDIR}/unbm/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unpn
	${LN} -sf ${SYSTTFDIR}/UnPen.ttf ${TEXTTFDIR}/unpn/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unph
	${LN} -sf ${SYSTTFDIR}/UnPenheulim.ttf ${TEXTTFDIR}/unph/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unpg
	${LN} -sf ${SYSTTFDIR}/UnPilgi.ttf ${TEXTTFDIR}/unpg/
	${LN} -sf ${SYSTTFDIR}/UnPilgiBold.ttf ${TEXTTFDIR}/unpg/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unsh
	${LN} -sf ${SYSTTFDIR}/UnShinmun.ttf ${TEXTTFDIR}/unsh/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/untz
	${LN} -sf ${SYSTTFDIR}/UnTaza.ttf ${TEXTTFDIR}/untz/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unyt
	${LN} -sf ${SYSTTFDIR}/UnYetgul.ttf ${TEXTTFDIR}/unyt/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unjbt
	${LN} -sf ${SYSTTFDIR}/UnJamoBatang.ttf ${TEXTTFDIR}/unjbt/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unjgt
	${LN} -sf ${SYSTTFDIR}/UnJamoDotum.ttf ${TEXTTFDIR}/unjgt/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unjnv
	${LN} -sf ${SYSTTFDIR}/UnJamoNovel.ttf ${TEXTTFDIR}/unjnv/
	${INSTALL_DATA_DIR} ${TEXTTFDIR}/unjsr
	${LN} -sf ${SYSTTFDIR}/UnJamoSora.ttf ${TEXTTFDIR}/unjsr/

.include "../../mk/bsd.pkg.mk"
