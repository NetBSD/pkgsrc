# $NetBSD: Makefile,v 1.5 2018/05/13 11:00:26 markd Exp $

DISTNAME=	texdoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2018
TEXLIVE_REV=	47446

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoc
COMMENT=	Documentation for tex-texdoc
LICENSE=	gnu-gpl-v3

CONFLICTS+=	texlive-tetex<2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
