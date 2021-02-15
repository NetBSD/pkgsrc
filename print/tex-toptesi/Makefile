# $NetBSD: Makefile,v 1.11 2021/02/15 00:39:21 markd Exp $

DISTNAME=	toptesi
PKGNAME=	tex-${DISTNAME}-6.4.06
TEXLIVE_REV=	56276

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/toptesi
COMMENT=	Bundle for typesetting multilanguage theses
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
