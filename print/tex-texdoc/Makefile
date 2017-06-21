# $NetBSD: Makefile,v 1.8 2017/06/21 13:25:34 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	44432

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v3

CONFLICTS+=	teTeX-bin<3.0nb50

REPLACE_TEXLUA=		bin/texdoc

.include "../../print/texlive/package.mk"
.include "options.mk"

post-extract: extract-texdoctk
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoc/texdoc.tlu \
		${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
