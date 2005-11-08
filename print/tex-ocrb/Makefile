# $NetBSD: Makefile,v 1.8 2005/11/08 21:45:01 tonio Exp $
#

DISTNAME=	ocr-b
PKGNAME=	tex-ocrb-1.0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/${DISTNAME}/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=
COMMENT=	OCR-B font for LaTeX

WRKSRC=		${WRKDIR}/ocr-b
DIST_SUBDIR=	${DISTNAME}
DISTFILES= ocrb10.mf ocrb10e.mf ocrb10f.mf ocrb10g.mf ocrb10l.mf \
	ocrb10s.mf ocrb10x.mf ocrb5.mf ocrb6.mf ocrb7.mf ocrb8.mf \
	ocrb9.mf ocrbdef.mf ocrbinfo ocrbmac.mf

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	for f in ${DISTFILES}; do \
		${CP} ${DISTDIR}/${DIST_SUBDIR}/$$f ${WRKSRC}; \
	done

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/fonts/ocrb
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/source/ocrb
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/ocrb
	${INSTALL_DATA} ${WRKSRC}/ocrbinfo \
		${PKG_LOCALTEXMFPREFIX}/doc/fonts/ocrb
	${INSTALL_DATA} ${WRKSRC}/*.mf \
		${PKG_LOCALTEXMFPREFIX}/fonts/source/ocrb
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
