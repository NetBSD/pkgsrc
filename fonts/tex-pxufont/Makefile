# $NetBSD: Makefile,v 1.2 2024/02/15 19:45:04 markd Exp $

DISTNAME=	pxufont
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	67573

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxufont
COMMENT=	Emulate non-Unicode Japanese fonts using Unicode fonts
LICENSE=	mit

DEPENDS+=	tex-ifptex-[0-9]*:../../print/tex-ifptex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
