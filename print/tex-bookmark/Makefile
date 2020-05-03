# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:36 markd Exp $

DISTNAME=	bookmark
PKGNAME=	tex-${DISTNAME}-1.28
TEXLIVE_REV=	53026

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
