# $NetBSD: Makefile,v 1.10 2019/12/06 20:19:29 markd Exp $

DISTNAME=	enumitem
PKGNAME=	tex-${DISTNAME}-3.9
TEXLIVE_REV=	51423

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/enumitem
COMMENT=	Control layout of itemize, enumerate, and description
LICENSE=	mit

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
