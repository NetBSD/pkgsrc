# $NetBSD: Makefile,v 1.8 2026/03/29 03:52:04 markd Exp $

DISTNAME=	fvextra
PKGNAME=	tex-${DISTNAME}-1.14.0
TEXLIVE_REV=	78296

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fvextra
COMMENT=	Extensions and patches for fancyvrb
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-upquote-[0-9]*:../../print/tex-upquote

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
