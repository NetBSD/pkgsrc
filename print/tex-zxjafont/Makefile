# $NetBSD: Makefile,v 1.6 2020/05/05 12:01:06 markd Exp $

DISTNAME=	zxjafont
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	53884

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/zxjafont
COMMENT=	Set up Japanese font families for XeLaTeX
LICENSE=	mit

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
