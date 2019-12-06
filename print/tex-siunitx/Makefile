# $NetBSD: Makefile,v 1.8 2019/12/06 20:23:17 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-2.7s
TEXLIVE_REV=	47746

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/siunitx
COMMENT=	A comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
