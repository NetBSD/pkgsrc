# $NetBSD: Makefile,v 1.17 2023/04/08 10:50:06 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-3.1a
TEXLIVE_REV=	66587

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/microtype
COMMENT=	Subliminal refinements towards typographical perfection
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
