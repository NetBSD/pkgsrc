# $NetBSD: Makefile,v 1.3 2016/01/30 04:05:50 markd Exp $

DISTNAME=	dvipng.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.14
TEXLIVE_REV=	29821

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for dvipng
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	dvipng<1.12

INFO_FILES=	yes

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
