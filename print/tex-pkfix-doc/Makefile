# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:03 markd Exp $

DISTNAME=	pkfix.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.7
TEXLIVE_REV=	26032

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pkfix
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
