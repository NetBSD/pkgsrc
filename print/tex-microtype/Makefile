# $NetBSD: Makefile,v 1.18 2024/12/26 18:17:15 riastradh Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-3.1a
PKGREVISION=	1
TEXLIVE_REV=	66587

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/microtype
COMMENT=	Subliminal refinements towards typographical perfection
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
