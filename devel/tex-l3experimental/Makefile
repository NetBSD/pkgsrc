# $NetBSD: Makefile,v 1.12 2019/12/06 19:18:34 markd Exp $

DISTNAME=	l3experimental
PKGNAME=	tex-${DISTNAME}-2019.51546
TEXLIVE_REV=	51546

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/l3experimental
COMMENT=	Experimental LaTeX3 concepts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
