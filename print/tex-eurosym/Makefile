# $NetBSD: Makefile,v 1.7 2003/12/24 13:02:01 jmmv Exp $
#

DISTNAME=	eurosym-1.0
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/eurosym
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	ftp://ftp.univie.ac.at/packages/tex/fonts/eurosym/
COMMENT=	Euro symbols for LaTeX

# included in teTeX2
DEPENDS+=	teTeX-bin-1.0.*:../../print/teTeX1-bin

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/doc/fonts/eurosym
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/source/eurosym
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/tfm/eurosym
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/eurosym
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/texmf/doc/fonts/eurosym
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${PREFIX}/share/texmf/fonts/source/eurosym
	${INSTALL_DATA} ${WRKSRC}/tfm/* \
		${PREFIX}/share/texmf/fonts/tfm/eurosym
	${INSTALL_DATA} ${WRKSRC}/sty/* \
		${PREFIX}/share/texmf/tex/latex/eurosym
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/bsd.pkg.mk"
