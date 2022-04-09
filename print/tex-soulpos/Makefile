# $NetBSD: Makefile,v 1.3 2022/04/09 03:17:44 markd Exp $

DISTNAME=	soulpos
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	60772

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/soulpos
COMMENT=	Fancy means of underlining
LICENSE=	mit

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
