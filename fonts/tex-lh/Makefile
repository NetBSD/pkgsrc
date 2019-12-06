# $NetBSD: Makefile,v 1.4 2019/12/06 19:30:10 markd Exp $

DISTNAME=	lh
PKGNAME=	tex-${DISTNAME}-3.5g
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Cyrillic fonts that support LaTeX standard encodings
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ec>=1.0:../../fonts/tex-ec

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
