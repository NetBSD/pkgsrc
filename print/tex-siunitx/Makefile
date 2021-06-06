# $NetBSD: Makefile,v 1.12 2021/06/06 12:32:49 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-3.0.10
TEXLIVE_REV=	59464

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/siunitx
COMMENT=	A comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
