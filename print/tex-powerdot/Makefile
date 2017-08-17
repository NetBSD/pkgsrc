# $NetBSD: Makefile,v 1.4 2017/08/17 04:24:37 markd Exp $

DISTNAME=	powerdot
PKGNAME=	tex-${DISTNAME}-1.5b
TEXLIVE_REV=	44868

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/powerdot
COMMENT=	A presentation class
LICENSE=	lppl-1.3c

DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
