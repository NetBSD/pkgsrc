# $NetBSD: Makefile,v 1.17 2023/06/11 07:46:40 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-3.2.5
TEXLIVE_REV=	66840

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/siunitx
COMMENT=	Comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
