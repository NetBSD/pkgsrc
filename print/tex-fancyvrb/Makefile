# $NetBSD: Makefile,v 1.7 2019/12/06 20:21:22 markd Exp $

DISTNAME=	fancyvrb
PKGNAME=	tex-${DISTNAME}-3.2a
TEXLIVE_REV=	49717

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fancyvrb
COMMENT=	Sophisticated verbatim text
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
