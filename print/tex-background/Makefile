# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:40 rillig Exp $

DISTNAME=	background
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	33100

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/background
COMMENT=	Placement of background material on pages of a document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-everypage-[0-9]*:../../print/tex-everypage
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
