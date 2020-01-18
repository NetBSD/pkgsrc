# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:42 rillig Exp $

DISTNAME=	powerdot
PKGNAME=	tex-${DISTNAME}-1.5c
TEXLIVE_REV=	45165

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/powerdot
COMMENT=	A presentation class
LICENSE=	lppl-1.3c

DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
