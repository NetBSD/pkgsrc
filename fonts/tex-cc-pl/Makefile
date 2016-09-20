# $NetBSD: Makefile,v 1.1 2016/09/20 12:27:48 markd Exp $

DISTNAME=	cc-pl
PKGNAME=	tex-${DISTNAME}-1.02.2
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cc-pl
COMMENT=	Polish extension of Computer Concrete fonts
LICENSE=	public-domain

CONFLICTS+=	teTeX-texmf<=3.0nb56

TEX_MIXEDMAP_FILES+=	ccpl.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
