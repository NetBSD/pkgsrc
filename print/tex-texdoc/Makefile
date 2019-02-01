# $NetBSD: Makefile,v 1.11 2019/02/01 23:31:07 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-2018.47946
TEXLIVE_REV=	47946

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoc
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v2

REPLACE_TEXLUA=		bin/texdoc

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoc/texdoc.tlu \
		${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
