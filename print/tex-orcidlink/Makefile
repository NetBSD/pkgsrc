# $NetBSD: Makefile,v 1.2 2024/02/14 20:00:00 markd Exp $

DISTNAME=	orcidlink
PKGNAME=	tex-${DISTNAME}-1.0.5
TEXLIVE_REV=	69253

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/orcidlink
COMMENT=	Insert hyperlinked ORCiD logo
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
