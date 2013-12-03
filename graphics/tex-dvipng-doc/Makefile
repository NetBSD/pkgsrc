# $NetBSD: Makefile,v 1.2 2013/12/03 02:18:49 minskim Exp $

DISTNAME=	dvipng.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.14
TEXLIVE_REV=	29821

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for dvipng

CONFLICTS+=	dvipng<1.12

INFO_FILES=	yes

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
