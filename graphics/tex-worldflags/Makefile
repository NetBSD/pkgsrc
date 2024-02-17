# $NetBSD: Makefile,v 1.2 2024/02/17 01:55:29 markd Exp $

DISTNAME=	worldflags
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	68827

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/worldflags
COMMENT=	Drawing flags with TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
