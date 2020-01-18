# $NetBSD: Makefile,v 1.8 2020/01/18 23:34:07 rillig Exp $

DISTNAME=	fancyvrb
PKGNAME=	tex-${DISTNAME}-3.2a
TEXLIVE_REV=	49717

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fancyvrb
COMMENT=	Sophisticated verbatim text
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
