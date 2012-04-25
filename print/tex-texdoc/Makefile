# $NetBSD: Makefile,v 1.2 2012/04/25 15:47:49 minskim Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME:S/./-/}-2011
TEXLIVE_REV=	24354

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v3

CONFLICTS+=	teTeX-bin<3.0nb50

REPLACE_TEXLUA=		bin/texdoc
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "options.mk"

post-extract: extract-texdoctk
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/texdoc/texdoc.tlu ${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
