# $NetBSD: Makefile,v 1.1.1.1 2001/10/03 23:20:46 wiz Exp $
#

DISTNAME=	eurosym-1.0
WRKSRC=		${WRKDIR}/eurosym
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://ftp.univie.ac.at/packages/tex/fonts/eurosym/
COMMENT=	Euro symbols for LaTeX

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_CONFIGURE=	yes
NO_PATCH=	yes
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
