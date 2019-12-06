# $NetBSD: Makefile,v 1.8 2019/12/06 20:23:38 markd Exp $

DISTNAME=	ukrhyph
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	21081

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation pattern files for Ukrainian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ruhyphen>=1.6:../../print/tex-ruhyphen

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
