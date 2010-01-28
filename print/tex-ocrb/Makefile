# $NetBSD: Makefile,v 1.14 2010/01/28 00:17:48 joerg Exp $
#

DISTNAME=	ocr-b
PKGNAME=	tex-ocrb-1.0
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/${DISTNAME}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=
COMMENT=	OCR-B font for LaTeX

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ocr-b
DIST_SUBDIR=	${DISTNAME}
DISTFILES= ocrb10.mf ocrb10e.mf ocrb10f.mf ocrb10g.mf ocrb10l.mf \
	ocrb10s.mf ocrb10x.mf ocrb5.mf ocrb6.mf ocrb7.mf ocrb8.mf \
	ocrb9.mf ocrbdef.mf ocrbinfo ocrbmac.mf

NO_CONFIGURE=	yes
NO_BUILD=	yes

PLIST_SUBST+=	LOCALTEXMF=${PKG_LOCALTEXMFPREFIX:S/${PREFIX}\///}

.include "../../print/teTeX/module.mk"

do-extract:
	${MKDIR} ${WRKSRC}
	for f in ${DISTFILES}; do \
		${CP} ${DISTDIR}/${DIST_SUBDIR}/$$f ${WRKSRC}; \
	done

INSTALLATION_DIRS+=	${PKG_LOCALTEXMFPREFIX}/doc/fonts/ocrb \
			${PKG_LOCALTEXMFPREFIX}/fonts/source/ocrb \
			${PKG_LOCALTEXMFPREFIX}/fonts/tfm/ocrb

do-install:
	${INSTALL_DATA} ${WRKSRC}/ocrbinfo \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/fonts/ocrb
	${INSTALL_DATA} ${WRKSRC}/*.mf \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/source/ocrb

.include "../../mk/bsd.pkg.mk"
