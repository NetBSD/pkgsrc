# $NetBSD: Makefile,v 1.6 2019/02/01 23:31:07 markd Exp $

DISTNAME=	texdoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2018.47946
TEXLIVE_REV=	47946

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoc
COMMENT=	Documentation for tex-texdoc
LICENSE=	gnu-gpl-v2

CONFLICTS+=	texlive-tetex<2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
