# $NetBSD: Makefile,v 1.3 2011/03/03 22:28:23 minskim Exp $

DISTNAME=	mfware
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	21345

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supporting tools for use with MetaFont

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
