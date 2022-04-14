# $NetBSD: Makefile,v 1.15 2022/04/14 02:46:05 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-3.0d
TEXLIVE_REV=	62717

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/microtype
COMMENT=	Subliminal refinements towards typographical perfection
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
