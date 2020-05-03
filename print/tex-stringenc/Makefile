# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:44 markd Exp $

DISTNAME=	stringenc
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	52982

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/stringenc
COMMENT=	Converting a string between different encodings
LICENSE=	lppl-1.3c

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
