# $NetBSD: Makefile,v 1.2 2019/12/06 20:21:45 markd Exp $

DISTNAME=	jadetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.13
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-jadetex

CONFLICTS=	tex-jadetex<=3.13nb7

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
