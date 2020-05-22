# $NetBSD: Makefile,v 1.1 2020/05/22 03:26:50 markd Exp $

DISTNAME=	threeparttablex
PKGNAME=	tex-${DISTNAME}-0.3
TEXLIVE_REV=	34206

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/threeparttablex
COMMENT=	Notes in longtables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-environ-[0-9]*:../../print/tex-environ
DEPENDS+=	tex-threeparttable-[0-9]*:../../print/tex-threeparttable

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
