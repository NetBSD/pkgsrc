# $NetBSD: Makefile,v 1.15 2006/02/05 23:10:40 joerg Exp $
#

DISTNAME=	eurosym-1.0
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	ftp://ftp.univie.ac.at/packages/tex/fonts/eurosym/
COMMENT=	Euro symbols for LaTeX

# included in teTeX[23]
#TEX_ACCEPTED=	teTeX1
CONFLICTS+=	teTeX>1

WRKSRC=		${WRKDIR}/eurosym
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/fonts/eurosym
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/source/eurosym
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/eurosym
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/eurosym
	${INSTALL_DATA} ${WRKSRC}/README \
		${PKG_LOCALTEXMFPREFIX}/doc/fonts/eurosym
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/source/eurosym
	${INSTALL_DATA} ${WRKSRC}/tfm/* \
		${PKG_LOCALTEXMFPREFIX}/fonts/tfm/eurosym
	${INSTALL_DATA} ${WRKSRC}/sty/* \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/eurosym
	${LOCALBASE}/bin/texconfig rehash

.include "../../print/teTeX1-bin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
