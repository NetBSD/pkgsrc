# $NetBSD: Makefile,v 1.21 2026/03/31 09:15:48 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-3.5.1
TEXLIVE_REV=	78509

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/siunitx
COMMENT=	Comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
