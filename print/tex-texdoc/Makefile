# $NetBSD: Makefile,v 1.19 2023/04/09 06:31:15 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-4.0.1
TEXLIVE_REV=	66227

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texdoc
COMMENT=	Documentation access for TeX Live
LICENSE=	gnu-gpl-v2

REPLACE_TEXLUA=	bin/texdoc

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoc/texdoc.tlu \
		${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
