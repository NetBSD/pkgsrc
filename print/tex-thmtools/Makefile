# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:57 rillig Exp $

DISTNAME=	thmtools
PKGNAME=	tex-${DISTNAME}-66
TEXLIVE_REV=	33624

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/thmtools
COMMENT=	Extensions to theorem environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
