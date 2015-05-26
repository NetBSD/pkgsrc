# $NetBSD: Makefile,v 1.1 2015/05/26 10:52:25 jaapb Exp $

DISTNAME= europecv
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	34454

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Unofficial class for European curricula vitae
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ucs-[0-9]*:../../print/tex-ucs
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
