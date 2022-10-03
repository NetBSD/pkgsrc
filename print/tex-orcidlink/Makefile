# $NetBSD: Makefile,v 1.1 2022/10/03 19:24:55 markd Exp $

DISTNAME=	orcidlink
PKGNAME=	tex-${DISTNAME}-1.0.4
TEXLIVE_REV=	59560

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/orcidlink
COMMENT=	Insert hyperlinked ORCiD logo
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
