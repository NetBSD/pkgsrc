# $NetBSD: Makefile,v 1.4 2026/04/03 23:33:37 markd Exp $

DISTNAME=	hologo
PKGNAME=	tex-${DISTNAME}-1.17
TEXLIVE_REV=	78580

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hologo
COMMENT=	Collection of logos with bookmark support
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-kvdefinekeys-[0-9]*:../../print/tex-kvdefinekeys
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
