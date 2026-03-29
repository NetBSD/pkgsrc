# $NetBSD: Makefile,v 1.3 2026/03/29 03:10:26 markd Exp $

DISTNAME=	embedfile
PKGNAME=	tex-${DISTNAME}-2.13
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/embedfile
COMMENT=	Embed files into PDF
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-kvdefinekeys-[0-9]*:../../print/tex-kvdefinekeys
DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
