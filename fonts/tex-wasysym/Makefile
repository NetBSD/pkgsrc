# $NetBSD: Makefile,v 1.5 2019/12/06 19:32:32 markd Exp $

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
