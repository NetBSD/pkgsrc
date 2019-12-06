# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:30 markd Exp $

DISTNAME=	thmtools
PKGNAME=	tex-${DISTNAME}-66
TEXLIVE_REV=	33624

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/thmtools
COMMENT=	Extensions to theorem environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
