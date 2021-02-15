# $NetBSD: Makefile,v 1.6 2021/02/15 00:33:09 markd Exp $

DISTNAME=	revtex
PKGNAME=	tex-${DISTNAME}-4.2e
TEXLIVE_REV=	56591

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/revtex
COMMENT=	Styles for various Physics Journals
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-textcase-[0-9]*:../../print/tex-textcase
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
