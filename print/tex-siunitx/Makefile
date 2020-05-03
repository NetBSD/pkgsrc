# $NetBSD: Makefile,v 1.10 2020/05/03 11:57:36 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-2.8b
TEXLIVE_REV=	53914

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/siunitx
COMMENT=	A comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
