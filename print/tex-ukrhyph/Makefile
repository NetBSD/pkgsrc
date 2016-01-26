# $NetBSD: Makefile,v 1.6 2016/01/26 10:44:43 markd Exp $

DISTNAME=	ukrhyph
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	21081

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation pattern files for Ukrainian
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-ruhyphen>=1.6:../../print/tex-ruhyphen

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
