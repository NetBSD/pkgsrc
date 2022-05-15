# $NetBSD: Makefile,v 1.14 2022/05/15 04:40:03 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-3.1.1
TEXLIVE_REV=	63218

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/siunitx
COMMENT=	Comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
