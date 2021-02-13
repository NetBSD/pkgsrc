# $NetBSD: Makefile,v 1.1 2021/02/13 05:05:47 markd Exp $

DISTNAME=	hypdestopt
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	56253

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hypdestopt
COMMENT=	Hyperref destination optimizer
LICENSE=	lppl-1.3c

DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
