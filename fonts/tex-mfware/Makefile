# $NetBSD: Makefile,v 1.4 2013/11/30 23:18:45 minskim Exp $

DISTNAME=	mfware
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	29764

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supporting tools for use with MetaFont

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	web2c-[0-9]*:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
