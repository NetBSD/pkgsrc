# $NetBSD: Makefile,v 1.15 2022/09/01 05:17:02 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-3.1.6
TEXLIVE_REV=	64080

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/siunitx
COMMENT=	Comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
