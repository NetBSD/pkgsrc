# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:51 markd Exp $

DISTNAME=	ocherokee
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	25689

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ocherokee
COMMENT=	LaTeX Support for the Cherokee language
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	cherokee.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
