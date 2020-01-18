# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:19 rillig Exp $

DISTNAME=	clearsans
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	34405

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/clearsans
COMMENT=	Clear Sans fonts with LaTeX support
LICENSE=	apache-2.0

TEX_MAP_FILES+=	ClearSans.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
