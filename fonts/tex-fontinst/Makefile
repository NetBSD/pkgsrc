# $NetBSD: Makefile,v 1.1 2013/11/18 19:02:57 minskim Exp $

DISTNAME=	fontinst
PKGNAME=	tex-${DISTNAME}-1.933
TEXLIVE_REV=	29764

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Help with installing fonts for TeX and LaTeX
LICENSE=	lppl-1.3c

USE_TOOLS+=	sh:run
REPLACE_SH=	bin/fontinst

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/fontinst.sh \
		${WRKSRC}/bin/fontinst
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
