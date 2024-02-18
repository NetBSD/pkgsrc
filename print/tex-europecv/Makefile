# $NetBSD: Makefile,v 1.12 2024/02/18 10:00:36 markd Exp $

DISTNAME=	europecv
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	69661

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	https://ctan.org/pkg/europecv
COMMENT=	Unofficial class for European curricula vitae
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ucs-[0-9]*:../../print/tex-ucs
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
