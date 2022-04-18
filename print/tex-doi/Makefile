# $NetBSD: Makefile,v 1.1 2022/04/18 03:03:01 markd Exp $

DISTNAME=	doi
PKGNAME=	tex-${DISTNAME}-20180909
TEXLIVE_REV=	48634

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/doi
COMMENT=	Create correct hyperlinks for DOI numbers
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
