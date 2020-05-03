# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:37 markd Exp $

DISTNAME=	etexcmds
PKGNAME=	tex-${DISTNAME}-1.7
TEXLIVE_REV=	53171

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/etexcmds
COMMENT=	Avoid name clashes with e-TeX commands
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
