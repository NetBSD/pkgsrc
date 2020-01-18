# $NetBSD: Makefile,v 1.5 2020/01/18 23:34:45 rillig Exp $

DISTNAME=	revtex
PKGNAME=	tex-${DISTNAME}-4.2c
TEXLIVE_REV=	49751

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/revtex
COMMENT=	Styles for various Physics Journals
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-textcase-[0-9]*:../../print/tex-textcase
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
