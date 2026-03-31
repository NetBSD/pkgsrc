# $NetBSD: Makefile,v 1.3 2026/03/31 19:50:09 markd Exp $

DISTNAME=	transparent
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/transparent
COMMENT=	Using a color stack for transparency with pdfTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
