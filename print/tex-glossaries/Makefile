# $NetBSD: Makefile,v 1.5 2011/10/18 21:32:43 minskim Exp $

DISTNAME=	glossaries
PKGNAME=	tex-${DISTNAME}-3.01
TEXLIVE_REV=	22100

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Create glossaries and lists of acronyms

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/makeglossaries

INSTALLATION_DIRS+=	bin

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/glossaries/makeglossaries \
		${WRKSRC}/bin/
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
