# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 19:12:15 minskim Exp $

DISTNAME=	t2
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support for using T2 encoding

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
