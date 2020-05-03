# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:38 markd Exp $

DISTNAME=	grfext
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	53024

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/grfext
COMMENT=	Manipulate the graphics package's list of extensions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-kvdefinekeys-[0-9]*:../../print/tex-kvdefinekeys

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
