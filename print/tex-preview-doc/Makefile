# $NetBSD: Makefile,v 1.6 2017/08/23 22:37:59 markd Exp $

DISTNAME=	preview.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-11.91
TEXLIVE_REV=	44883

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/preview
COMMENT=	Documentation for tex-preview
LICENSE=	gnu-gpl-v3

CONFLICTS=	teTeX-texmf<3.0nb32

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
