# $NetBSD: Makefile,v 1.10 2020/05/01 00:15:13 markd Exp $

DISTNAME=	datatool
PKGNAME=	tex-${DISTNAME}-2.32
TEXLIVE_REV=	52663

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/datatool
COMMENT=	Tools to load and manipulate data
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fp-[0-9]*:../../math/tex-fp
DEPENDS+=	tex-substr-[0-9]*:../../print/tex-substr
DEPENDS+=	tex-xfor-[0-9]*:../../print/tex-xfor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
