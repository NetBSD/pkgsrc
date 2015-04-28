# $NetBSD: Makefile,v 1.2 2015/04/28 20:08:35 markd Exp $

DISTNAME=	powerdot
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	32549

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	A presentation class
LICENSE=	lppl-1.3c

DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
