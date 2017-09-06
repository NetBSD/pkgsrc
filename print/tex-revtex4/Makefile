# $NetBSD: Makefile,v 1.2 2017/09/06 16:49:43 wiz Exp $

DISTNAME=	revtex4
PKGNAME=	tex-${DISTNAME}-4.0
TEXLIVE_REV=	16488

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	style for APS and AIP manuscripts

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
