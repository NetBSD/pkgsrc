# $NetBSD: Makefile,v 1.2 2001/10/17 01:47:31 dmcmahill Exp $
#

DISTNAME=	bakoma-20010719
PKGNAME=	bakoma-fonts-1.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}
# The "on the fly" distfile creation from CTAN messes up the checksums.
#MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/cm/ps-type1/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ctan.org/tex-archive/fonts/cm/ps-type1/bakoma/
COMMENT=	BaKoMa Fonts for TeX

WRKSRC=			${WRKDIR}/bakoma
LICENSE+=		no-commercial-use
NO_SRC_ON_CDROM=	#defined
NO_BIN_ON_CDROM=	#defined
BAKOMA_DIR=		${PREFIX}/share/tex-contrib/BaKoMa

do-build:
	${RM} -f ${WRKSRC}/fontmap.map
	${CAT} ${WRKSRC}/etc/cmfonts.map ${WRKSRC}/etc/amsfonts.map  | \
		${SED} 's;<;<${BAKOMA_DIR}/pfb/;g' > ${WRKSRC}/fontmap.map

do-install:
.for d in afm etc pfb pfm tfm ttf
	${INSTALL_DATA_DIR} ${BAKOMA_DIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/* ${BAKOMA_DIR}/${d}
.endfor
.for f in fontmap.map BaKoMa-AMS.Fonts BaKoMa-CM.Fonts README.news
	${INSTALL_DATA} ${WRKSRC}/${f} ${BAKOMA_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
