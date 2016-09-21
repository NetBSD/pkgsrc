# $NetBSD: Makefile,v 1.2 2016/09/21 17:11:31 prlw1 Exp $

DISTNAME=	revtex
PKGNAME=	tex-${DISTNAME}-4.1r
TEXLIVE_REV=	19652

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Styles for various Physics Journals
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-textcase-[0-9]*:../../print/tex-textcase
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
