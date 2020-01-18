# $NetBSD: Makefile,v 1.9 2020/01/18 23:31:43 rillig Exp $

DISTNAME=	mfware
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	36017

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mfware
COMMENT=	Supporting tools for use with MetaFont
#LICENSE=	knuth

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
