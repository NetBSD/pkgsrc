# $NetBSD: Makefile,v 1.6 2021/02/15 00:37:02 markd Exp $

DISTNAME=	revtex4
PKGNAME=	tex-${DISTNAME}-4.0a
TEXLIVE_REV=	56589

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/revtex4-0
COMMENT=	Styles for various Physics Journals (old version)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
