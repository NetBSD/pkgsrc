# $NetBSD: Makefile,v 1.20 2024/02/18 10:54:31 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-4.0.2
TEXLIVE_REV=	69672

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
