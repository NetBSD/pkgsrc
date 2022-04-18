# $NetBSD: Makefile,v 1.4 2022/04/18 00:12:45 markd Exp $

DISTNAME=	pxjahyper
PKGNAME=	tex-${DISTNAME}-1.0a
TEXLIVE_REV=	63040

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjahyper
COMMENT=	Hyperref support for pLaTeX
LICENSE=	mit

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
