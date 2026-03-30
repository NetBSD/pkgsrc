# $NetBSD: Makefile,v 1.20 2026/03/30 08:37:57 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-3.2d
TEXLIVE_REV=	78228

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/microtype
COMMENT=	Subliminal refinements towards typographical perfection
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
