# $NetBSD: Makefile,v 1.1 2015/05/03 10:31:57 markd Exp $

DISTNAME=	revtex4
PKGNAME=	tex-${DISTNAME}-4.0
TEXLIVE_REV=	16488

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	style for APS and AIP manuscripts

CONFLICTS+=	teTeX-texmf<=3.0nb47
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
