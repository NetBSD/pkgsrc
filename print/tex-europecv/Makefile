# $NetBSD: Makefile,v 1.9 2021/06/03 06:53:00 markd Exp $

DISTNAME=	europecv
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	59162

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	https://ctan.org/pkg/europecv
COMMENT=	Unofficial class for European curricula vitae
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ucs-[0-9]*:../../print/tex-ucs
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
