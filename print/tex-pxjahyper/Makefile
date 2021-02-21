# $NetBSD: Makefile,v 1.1 2021/02/21 10:46:52 markd Exp $

DISTNAME=	pxjahyper
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	57732

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjahyper
COMMENT=	Hyperref support for pLaTeX
LICENSE=	mit

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
