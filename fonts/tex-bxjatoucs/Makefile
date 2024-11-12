# $NetBSD: Makefile,v 1.2 2024/11/12 22:42:00 markd Exp $

DISTNAME=	bxjatoucs
PKGNAME=	tex-${DISTNAME}-0.3a
TEXLIVE_REV=	71870

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxjatoucs
COMMENT=	Convert Japanese character code to Unicode
LICENSE=	mit

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
