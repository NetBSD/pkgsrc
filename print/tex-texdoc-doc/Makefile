# $NetBSD: Makefile,v 1.10 2020/05/05 12:01:04 markd Exp $

DISTNAME=	texdoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020
TEXLIVE_REV=	53859

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texdoc
COMMENT=	Documentation for tex-texdoc
LICENSE=	gnu-gpl-v2

CONFLICTS+=	texlive-tetex<2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
