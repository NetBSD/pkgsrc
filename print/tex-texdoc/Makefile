# $NetBSD: Makefile,v 1.12 2019/05/12 03:26:38 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50627

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
