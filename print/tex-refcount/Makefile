# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:43 markd Exp $

DISTNAME=	refcount
PKGNAME=	tex-${DISTNAME}-3.6
TEXLIVE_REV=	53164

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/refcount
COMMENT=	Counter operations with label references
LICENSE=	lppl-1.3c

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
