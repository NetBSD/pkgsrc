# $NetBSD: Makefile,v 1.2 2026/03/26 10:03:46 markd Exp $

DISTNAME=	pxjodel
PKGNAME=	tex-${DISTNAME}-0.3a
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjodel
COMMENT=	Help change metrics of fonts from japanese-otf
LICENSE=	mit

DEPENDS+=	tex-ifptex-[0-9]*:../../print/tex-ifptex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
