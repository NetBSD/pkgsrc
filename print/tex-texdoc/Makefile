# $NetBSD: Makefile,v 1.9 2017/09/06 16:49:45 wiz Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	44432

MAINTAINER=	minskim@NetBSD.org
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
