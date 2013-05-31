# $NetBSD: Makefile,v 1.4 2013/05/31 12:41:50 wiz Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME:S/./-/}-2011
PKGREVISION=	2
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
