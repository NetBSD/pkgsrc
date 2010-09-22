# $NetBSD: Makefile,v 1.5 2010/09/22 03:00:19 minskim Exp $

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	19817

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live infrastructure programs
LICENSE=	gnu-gpl-v2 AND public-domain

CONFLICTS+=	tex-bin-texlive-[0-9]*

REPLACE_TEXLUA=		bin/rungs
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/texlive/rungs.tlu ${WRKSRC}/bin/rungs

.include "../../mk/bsd.pkg.mk"
