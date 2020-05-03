# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:36 markd Exp $

DISTNAME=	catchfile
PKGNAME=	tex-${DISTNAME}-1.8
TEXLIVE_REV=	53084

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/catchfile
COMMENT=	Catch an external file into a macro
LICENSE=	lppl-1.3c

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
