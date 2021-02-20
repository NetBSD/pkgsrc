# $NetBSD: Makefile,v 1.2 2021/02/20 09:45:09 markd Exp $

DISTNAME=	atenddvi
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	56922

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/atenddvi
COMMENT=	Provides the \AtEndDvi command
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-zref-[0-9]*:../../print/tex-zref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
