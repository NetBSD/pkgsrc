# $NetBSD: Makefile,v 1.2 2021/06/06 22:19:59 markd Exp $

DISTNAME=	pxjahyper
PKGNAME=	tex-${DISTNAME}-0.9b
TEXLIVE_REV=	59395

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjahyper
COMMENT=	Hyperref support for pLaTeX
LICENSE=	mit

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
