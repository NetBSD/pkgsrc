# $NetBSD: Makefile,v 1.4 2023/04/09 05:55:33 markd Exp $

DISTNAME=	pbibtex-base
PKGNAME=	tex-${DISTNAME}-2022
TEXLIVE_REV=	66085

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pbibtex-base
COMMENT=	Bibliography styles and miscellaneous files for pBibTeX
LICENSE=	modified-bsd

CONFLICTS+=	tex-ptex<=3.2pl36135

post-patch:
	mkdir ${WRKSRC}/texmf-dist
	mv ${WRKSRC}/pbibtex ${WRKSRC}/texmf-dist/pbibtex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
