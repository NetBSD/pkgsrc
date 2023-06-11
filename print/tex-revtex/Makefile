# $NetBSD: Makefile,v 1.7 2023/06/11 07:44:00 markd Exp $

DISTNAME=	revtex
PKGNAME=	tex-${DISTNAME}-4.2f
TEXLIVE_REV=	67271

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
