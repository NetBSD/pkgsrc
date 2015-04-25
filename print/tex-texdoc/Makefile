# $NetBSD: Makefile,v 1.7 2015/04/25 04:52:49 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	34180

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
