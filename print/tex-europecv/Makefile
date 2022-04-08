# $NetBSD: Makefile,v 1.10 2022/04/08 21:23:48 markd Exp $

DISTNAME=	europecv
PKGNAME=	tex-${DISTNAME}-2021.62684
TEXLIVE_REV=	62684

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	https://ctan.org/pkg/europecv
COMMENT=	Unofficial class for European curricula vitae
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ucs-[0-9]*:../../print/tex-ucs
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
