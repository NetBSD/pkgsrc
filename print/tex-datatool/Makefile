# $NetBSD: Makefile,v 1.11 2025/05/09 23:40:10 markd Exp $

DISTNAME=	datatool
PKGNAME=	tex-${DISTNAME}-3.4.1
TEXLIVE_REV=	75019

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
