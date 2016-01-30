# $NetBSD: Makefile,v 1.3 2016/01/30 04:56:45 markd Exp $

DISTNAME=	wasysym
PKGNAME=	tex-${DISTNAME}-2.0
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support file to use the WASY2 fonts
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy
DEPENDS+=	tex-wasy2-ps-[0-9]*:../../fonts/tex-wasy2-ps

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
