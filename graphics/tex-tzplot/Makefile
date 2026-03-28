# $NetBSD: Makefile,v 1.2 2026/03/28 00:02:53 markd Exp $

DISTNAME=	tzplot
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	77181

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tzplot
COMMENT=	Plot graphs with TikZ abbreviations
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
