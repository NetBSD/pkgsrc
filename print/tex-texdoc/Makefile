# $NetBSD: Makefile,v 1.22 2025/05/10 23:42:32 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-4.1.1
TEXLIVE_REV=	73876

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
