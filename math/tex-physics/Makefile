# $NetBSD: Makefile,v 1.1 2021/03/18 03:46:00 markd Exp $

DISTNAME=	physics
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	28590

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/physics
COMMENT=	Macros supporting the Mathematics of Physics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
