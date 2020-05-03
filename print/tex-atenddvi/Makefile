# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:34 markd Exp $

DISTNAME=	atenddvi
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	53107

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/atenddvi
COMMENT=	Provides the \AtEndDvi command
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-zref-[0-9]*:../../print/tex-zref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
