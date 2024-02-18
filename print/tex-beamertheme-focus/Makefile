# $NetBSD: Makefile,v 1.4 2024/02/18 09:50:54 markd Exp $

DISTNAME=	beamertheme-focus
PKGNAME=	tex-${DISTNAME}-3.4.0
TEXLIVE_REV=	69742

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/beamertheme-focus
COMMENT=	Minimalist presentation theme for LaTeX Beamer
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-appendixnumberbeamer-[0-9]*:../../print/tex-appendixnumberbeamer
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
