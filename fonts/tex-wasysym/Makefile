# $NetBSD: Makefile,v 1.6 2020/04/26 12:21:21 markd Exp $

DISTNAME=	wasysym
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	54080

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/wasysym
COMMENT=	LaTeX support for the wasy fonts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy
DEPENDS+=	tex-wasy-type1-[0-9]*:../../fonts/tex-wasy-type1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
