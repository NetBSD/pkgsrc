# $NetBSD: Makefile,v 1.1.1.1 2003/03/12 00:50:02 mjl Exp $
#

DISTNAME=	ocr-b
PKGNAME=	tex-ocrb-1.0
# PKGREVISION=	1
WRKSRC=		${WRKDIR}/ocr-b
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	
COMMENT=	OCR-B font for LaTeX

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

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
