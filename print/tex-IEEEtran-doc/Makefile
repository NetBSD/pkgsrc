# $NetBSD: Makefile,v 1.7 2019/12/06 20:17:04 markd Exp $

DISTNAME=	IEEEtran.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.8b
TEXLIVE_REV=	38238

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-IEEEtran
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-IEEEtran<=1.7nb1

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
