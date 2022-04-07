# $NetBSD: Makefile,v 1.3 2022/04/07 05:27:34 markd Exp $

DISTNAME=	beamertheme-focus
PKGNAME=	tex-${DISTNAME}-3.3.0
TEXLIVE_REV=	62551

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/beamertheme-focus
COMMENT=	Minimalist presentation theme for LaTeX Beamer
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-appendixnumberbeamer-[0-9]*:../../print/tex-appendixnumberbeamer
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
