# $NetBSD: Makefile,v 1.1 2026/04/03 02:19:29 markd Exp $

DISTNAME=	seatingchart
PKGNAME=	tex-${DISTNAME}-0.5.0
TEXLIVE_REV=	76924

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/seatingchart
COMMENT=	Generation of seating charts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
