# $NetBSD: Makefile,v 1.2 2015/04/26 12:09:55 ryoon Exp $

DISTNAME=	wasysym
PKGNAME=	tex-${DISTNAME}-2.0
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support file to use the WASY2 fonts

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy
DEPENDS+=	tex-wasy2-ps-[0-9]*:../../fonts/tex-wasy2-ps

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
