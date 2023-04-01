# $NetBSD: Makefile,v 1.5 2023/04/01 11:07:12 markd Exp $

DISTNAME=	fvextra
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	65158

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
