# $NetBSD: Makefile,v 1.3 2016/01/30 04:56:42 markd Exp $

DISTNAME=	fontname.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2013
TEXLIVE_REV=	29725

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-fontname
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<=3.0nb29

INFO_FILES=	yes

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
