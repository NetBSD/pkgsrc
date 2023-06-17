# $NetBSD: Makefile,v 1.18 2023/06/17 10:41:52 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-3.2.6
TEXLIVE_REV=	67346

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/siunitx
COMMENT=	Comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
