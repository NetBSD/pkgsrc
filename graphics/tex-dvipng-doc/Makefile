# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:21 markd Exp $

DISTNAME=	dvipng.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.14
TEXLIVE_REV=	29821

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for dvipng
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	dvipng<1.12

INFO_FILES=	yes

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
