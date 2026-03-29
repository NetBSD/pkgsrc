# $NetBSD: Makefile,v 1.3 2026/03/29 10:57:48 markd Exp $

DISTNAME=	hypdestopt
PKGNAME=	tex-${DISTNAME}-2.9
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hypdestopt
COMMENT=	Hyperref destination optimizer
LICENSE=	lppl-1.3c

DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
