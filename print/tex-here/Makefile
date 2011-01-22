# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 22:06:30 minskim Exp $

DISTNAME=	here
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	16135

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Emulation of obsolete package for "here" floats

CONFLICTS+=	teTeX-texmf<3.0nb29
DEPENDS+=	tex-float>=1.3d:../../print/tex-float

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
