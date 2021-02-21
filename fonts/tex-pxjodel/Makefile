# $NetBSD: Makefile,v 1.1 2021/02/21 08:56:13 markd Exp $

DISTNAME=	pxjodel
PKGNAME=	tex-${DISTNAME}-0.3
TEXLIVE_REV=	55006

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjodel
COMMENT=	Help change metrics of fonts from japanese-otf
LICENSE=	mit

DEPENDS+=	tex-ifptex-[0-9]*:../../print/tex-ifptex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
