# $NetBSD: Makefile,v 1.3 2016/06/16 04:06:16 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-2.6q
TEXLIVE_REV=	39922

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/siunitx
COMMENT=	A comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
