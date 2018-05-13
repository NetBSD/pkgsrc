# $NetBSD: Makefile,v 1.10 2018/05/13 11:00:26 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47446

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoc
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v3

REPLACE_TEXLUA=		bin/texdoc

.include "../../print/texlive/package.mk"
.include "options.mk"

post-extract: extract-texdoctk
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoc/texdoc.tlu \
		${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
