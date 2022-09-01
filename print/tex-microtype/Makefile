# $NetBSD: Makefile,v 1.16 2022/09/01 04:46:32 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-3.0f
TEXLIVE_REV=	63708

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/microtype
COMMENT=	Subliminal refinements towards typographical perfection
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
