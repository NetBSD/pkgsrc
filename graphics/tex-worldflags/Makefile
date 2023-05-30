# $NetBSD: Makefile,v 1.1 2023/05/30 11:55:26 markd Exp $

DISTNAME=	worldflags
PKGNAME=	tex-${DISTNAME}-2022
TEXLIVE_REV=	59171

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
