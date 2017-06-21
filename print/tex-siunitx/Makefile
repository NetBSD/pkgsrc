# $NetBSD: Makefile,v 1.4 2017/06/21 13:25:32 markd Exp $

DISTNAME=	siunitx
PKGNAME=	tex-${DISTNAME}-2.7g
TEXLIVE_REV=	44428

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/siunitx
COMMENT=	A comprehensive (SI) units package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
