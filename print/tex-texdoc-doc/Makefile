# $NetBSD: Makefile,v 1.7 2019/05/12 03:26:38 markd Exp $

DISTNAME=	texdoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2019
TEXLIVE_REV=	50627

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoc
COMMENT=	Documentation for tex-texdoc
LICENSE=	gnu-gpl-v2

CONFLICTS+=	texlive-tetex<2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
