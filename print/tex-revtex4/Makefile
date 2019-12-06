# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:11 markd Exp $

DISTNAME=	revtex4
PKGNAME=	tex-${DISTNAME}-4.0.45873
TEXLIVE_REV=	45873

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/revtex4-0
COMMENT=	Styles for various Physics Journals (old version)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
