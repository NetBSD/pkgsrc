# $NetBSD: Makefile,v 1.9 2020/05/03 11:57:33 markd Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	53889

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/overpic
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-eepic-[0-9]*:../../graphics/tex-eepic

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
