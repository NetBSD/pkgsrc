# $NetBSD: Makefile,v 1.8 2019/12/06 20:04:22 markd Exp $

DISTNAME=	epstopdf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.28
TEXLIVE_REV=	48684

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/epstopdf
COMMENT=	Documentation for tex-epstopdf
LICENSE=	modified-bsd

CONFLICTS=	texlive-pdftools<2011

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
