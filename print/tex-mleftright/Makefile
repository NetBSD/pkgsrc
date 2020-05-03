# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:41 markd Exp $

DISTNAME=	mleftright
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	53021

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mleftright
COMMENT=	Variants of delimiters that act as maths open/close
LICENSE=	lppl-1.3c

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
