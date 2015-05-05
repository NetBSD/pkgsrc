# $NetBSD: Makefile,v 1.6 2015/05/05 20:37:55 wiz Exp $

DISTNAME=	misc
PKGNAME=	tex-${DISTNAME}-2012
PKGREVISION=	1
TEXLIVE_REV=	24955

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Miscellaneous files for TeX

CONFLICTS+=	teTeX-texmf<=3.0nb11

TEXLIVE_IGNORE_PATTERNS=	omega

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
