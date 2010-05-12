# $NetBSD: Makefile,v 1.2 2010/05/12 04:12:52 minskim Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-3.1m
TEXLIVE_REV=	16715

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Customising captions in floating environments

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
