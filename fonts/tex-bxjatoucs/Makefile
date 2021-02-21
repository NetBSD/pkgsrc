# $NetBSD: Makefile,v 1.1 2021/02/21 08:30:29 markd Exp $

DISTNAME=	bxjatoucs
PKGNAME=	tex-${DISTNAME}-0.2
TEXLIVE_REV=	52509

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxjatoucs
COMMENT=	Convert Japanese character code to Unicode
LICENSE=	mit

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
