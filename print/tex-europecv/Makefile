# $NetBSD: Makefile,v 1.13 2025/08/25 08:35:11 wiz Exp $

DISTNAME=	europecv
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	69661

MAINTAINER=	pkgsrc-users@kerguelen.org
HOMEPAGE=	https://ctan.org/pkg/europecv
COMMENT=	Unofficial class for European curricula vitae
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ucs-[0-9]*:../../print/tex-ucs
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
