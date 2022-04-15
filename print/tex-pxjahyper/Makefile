# $NetBSD: Makefile,v 1.3 2022/04/15 04:33:53 markd Exp $

DISTNAME=	pxjahyper
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	62921

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjahyper
COMMENT=	Hyperref support for pLaTeX
LICENSE=	mit

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
