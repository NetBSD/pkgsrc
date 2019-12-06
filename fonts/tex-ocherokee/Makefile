# $NetBSD: Makefile,v 1.4 2019/12/06 19:32:16 markd Exp $

DISTNAME=	ocherokee
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	25689

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ocherokee
COMMENT=	LaTeX Support for the Cherokee language
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	cherokee.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
