# $NetBSD: Makefile,v 1.3 2016/06/16 04:06:15 markd Exp $

DISTNAME=	powerdot
PKGNAME=	tex-${DISTNAME}-1.5a
TEXLIVE_REV=	38984

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	A presentation class
LICENSE=	lppl-1.3c

DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
