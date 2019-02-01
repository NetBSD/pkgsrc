# $NetBSD: Makefile,v 1.3 2019/02/01 21:52:59 markd Exp $

DISTNAME=	europecv
PKGNAME=	tex-${DISTNAME}-2018.49814
TEXLIVE_REV=	49814

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ctan.org/pkg/europecv
COMMENT=	Unofficial class for European curricula vitae
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ucs-[0-9]*:../../print/tex-ucs
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
