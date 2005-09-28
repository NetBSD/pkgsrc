# $NetBSD: Makefile,v 1.7 2005/09/28 14:31:08 rillig Exp $
#

DISTNAME=	ocr-b
PKGNAME=	tex-ocrb-1.0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/${DISTNAME}/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=
COMMENT=	OCR-B font for LaTeX

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/doc/fonts/ocrb
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/source/ocrb
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/tfm/ocrb
	${INSTALL_DATA} ${WRKSRC}/ocrbinfo \
		${PREFIX}/share/texmf/doc/fonts/ocrb
	${INSTALL_DATA} ${WRKSRC}/*.mf \
		${PREFIX}/share/texmf/fonts/source/ocrb
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/bsd.pkg.mk"
