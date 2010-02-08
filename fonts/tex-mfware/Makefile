# $NetBSD: Makefile,v 1.1.1.1 2010/02/08 04:52:03 minskim Exp $
# TeX Live Revision 16392

DISTNAME=	mfware
PKGNAME=	tex-${DISTNAME}-2009

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supporting tools for use with MetaFont

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
