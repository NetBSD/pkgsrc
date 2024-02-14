# $NetBSD: Makefile,v 1.10 2024/02/14 20:01:16 markd Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	69343

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/overpic
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-eepic-[0-9]*:../../graphics/tex-eepic

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
