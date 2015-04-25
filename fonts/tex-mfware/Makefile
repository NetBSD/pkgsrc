# $NetBSD: Makefile,v 1.5 2015/04/25 08:13:22 markd Exp $

DISTNAME=	mfware
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	36017

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supporting tools for use with MetaFont

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	web2c-[0-9]*:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
