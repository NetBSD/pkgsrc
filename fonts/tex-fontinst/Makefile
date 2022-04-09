# $NetBSD: Makefile,v 1.6 2022/04/09 20:57:20 markd Exp $

DISTNAME=	fontinst
PKGNAME=	tex-${DISTNAME}-1.933.62517
TEXLIVE_REV=	62517

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontinst
COMMENT=	Help with installing fonts for TeX and LaTeX
LICENSE=	lppl-1.3c

USE_TOOLS+=	sh:run
REPLACE_SH=	bin/fontinst

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive-extra/fontinst.sh \
		${WRKSRC}/bin/fontinst
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
