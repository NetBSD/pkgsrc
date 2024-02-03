# $NetBSD: Makefile,v 1.3 2024/02/03 03:00:57 markd Exp $

DISTNAME=	bookmark
PKGNAME=	tex-${DISTNAME}-1.31
TEXLIVE_REV=	69084

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bookmark
COMMENT=	New bookmark (outline) organization for hyperref
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atenddvi-[0-9]*:../../print/tex-atenddvi
DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend
DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
