# $NetBSD: Makefile,v 1.1 2020/07/16 01:03:32 markd Exp $

DISTNAME=	beamertheme-focus
PKGNAME=	tex-${DISTNAME}-2.6
TEXLIVE_REV=	55475

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/beamertheme-focus
COMMENT=	Minimalist presentation theme for LaTeX Beamer
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-appendixnumberbeamer-[0-9]*:../../print/tex-appendixnumberbeamer
DEPENDS+=	tex-beamer-[0-9]*:../../print/tex-beamer

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
