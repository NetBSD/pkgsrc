# $NetBSD: Makefile,v 1.14 2020/01/18 23:34:55 rillig Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50627

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texdoc
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v2

REPLACE_TEXLUA=		bin/texdoc

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoc/texdoc.tlu \
		${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
