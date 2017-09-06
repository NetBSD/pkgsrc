# $NetBSD: Makefile,v 1.4 2017/09/06 16:49:26 wiz Exp $

DISTNAME=	wasysym
PKGNAME=	tex-${DISTNAME}-2.0
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support file to use the WASY2 fonts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy
DEPENDS+=	tex-wasy2-ps-[0-9]*:../../fonts/tex-wasy2-ps

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
