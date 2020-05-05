# $NetBSD: Makefile,v 1.15 2020/05/05 12:01:03 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	53859

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texdoc
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v2

REPLACE_TEXLUA=		bin/texdoc

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoc/texdoc.tlu \
		${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
