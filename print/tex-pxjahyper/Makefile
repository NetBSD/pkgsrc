# $NetBSD: Makefile,v 1.6 2023/04/09 06:16:59 markd Exp $

DISTNAME=	pxjahyper
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	66272

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjahyper
COMMENT=	Hyperref support for pLaTeX
LICENSE=	mit

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
