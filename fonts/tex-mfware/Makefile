# $NetBSD: Makefile,v 1.2 2010/09/14 00:24:38 minskim Exp $

DISTNAME=	mfware
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supporting tools for use with MetaFont

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
