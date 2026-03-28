# $NetBSD: Makefile,v 1.2 2026/03/28 22:39:12 markd Exp $

DISTNAME=	l3kernel-dev
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78446

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/l3kernel-dev
COMMENT=	Development pre-release of l3kernel
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3backend-dev-[0-9]*:../../devel/tex-l3backend-dev
DEPENDS+=	tex-lua-uni-algos-[0-9]*:../../print/tex-lua-uni-algos

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
