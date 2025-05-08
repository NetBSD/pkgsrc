# $NetBSD: Makefile,v 1.2 2025/05/08 11:10:21 markd Exp $

DISTNAME=	hypdestopt
PKGNAME=	tex-${DISTNAME}-2.8
TEXLIVE_REV=	71991

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hypdestopt
COMMENT=	Hyperref destination optimizer
LICENSE=	lppl-1.3c

DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
