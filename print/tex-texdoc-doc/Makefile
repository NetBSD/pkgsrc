# $NetBSD: Makefile,v 1.4 2017/06/21 13:25:34 markd Exp $

DISTNAME=	texdoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	44432

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoc
COMMENT=	Documentation for tex-texdoc
LICENSE=	gnu-gpl-v3

CONFLICTS+=	texlive-tetex<2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
