# $NetBSD: Makefile,v 1.5 2022/09/01 11:07:37 markd Exp $

DISTNAME=	pxjahyper
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	64072

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pxjahyper
COMMENT=	Hyperref support for pLaTeX
LICENSE=	mit

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
