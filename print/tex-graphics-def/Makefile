# $NetBSD: Makefile,v 1.13 2023/09/28 21:43:10 joerg Exp $

DISTNAME=	graphics-def
PKGNAME=	tex-${DISTNAME}-2022.64487
PKGREVISION=	1
TEXLIVE_REV=	64487

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/graphics-def
COMMENT=	Colour and graphics option files
LICENSE=	lppl-1.3c

DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
