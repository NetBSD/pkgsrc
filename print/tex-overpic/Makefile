# $NetBSD: Makefile,v 1.11 2026/03/30 10:49:38 markd Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/overpic
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-eepic-[0-9]*:../../graphics/tex-eepic

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
