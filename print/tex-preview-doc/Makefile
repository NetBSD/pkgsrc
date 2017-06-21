# $NetBSD: Makefile,v 1.5 2017/06/21 11:45:58 markd Exp $

DISTNAME=	preview.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-11.90
TEXLIVE_REV=	44227

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/preview
COMMENT=	Documentation for tex-preview
LICENSE=	gnu-gpl-v3

CONFLICTS=	teTeX-texmf<3.0nb32

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
