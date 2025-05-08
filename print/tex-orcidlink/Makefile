# $NetBSD: Makefile,v 1.3 2025/05/08 09:39:18 markd Exp $

DISTNAME=	orcidlink
PKGNAME=	tex-${DISTNAME}-1.1.0
TEXLIVE_REV=	71633

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/orcidlink
COMMENT=	Insert hyperlinked ORCiD logo
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
