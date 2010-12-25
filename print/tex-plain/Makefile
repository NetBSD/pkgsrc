# $NetBSD: Makefile,v 1.6 2010/12/25 02:40:11 minskim Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653
PKGREVISION=	2
TEXLIVE_REV=	20544

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The Plain TeX format

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../print/tex-misc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
