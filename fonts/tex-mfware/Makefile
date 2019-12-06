# $NetBSD: Makefile,v 1.8 2019/12/06 19:30:16 markd Exp $

DISTNAME=	mfware
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	36017

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mfware
COMMENT=	Supporting tools for use with MetaFont
#LICENSE=	knuth

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
