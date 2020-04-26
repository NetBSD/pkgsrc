# $NetBSD: Makefile,v 1.5 2020/04/26 12:21:14 markd Exp $

DISTNAME=	fontinst
PKGNAME=	tex-${DISTNAME}-1.933.53562
TEXLIVE_REV=	53562

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
