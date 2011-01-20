# $NetBSD: Makefile,v 1.5 2011/01/20 16:31:23 minskim Exp $

DISTNAME=	ukrhyph
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	21081

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation pattern files for Ukrainian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-ruhyphen>=1.6:../../print/tex-ruhyphen

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
