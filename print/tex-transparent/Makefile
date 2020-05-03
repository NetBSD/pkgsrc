# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:44 markd Exp $

DISTNAME=	transparent
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	52981

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/transparent
COMMENT=	Using a color stack for transparency with pdfTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
