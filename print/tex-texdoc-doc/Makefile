# $NetBSD: Makefile,v 1.3 2015/04/25 04:52:49 markd Exp $

DISTNAME=	texdoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	34180

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-texdoc
LICENSE=	gnu-gpl-v3

CONFLICTS+=	texlive-tetex<2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
