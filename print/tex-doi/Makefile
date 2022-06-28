# $NetBSD: Makefile,v 1.2 2022/06/28 11:35:31 wiz Exp $

DISTNAME=	doi
PKGNAME=	tex-${DISTNAME}-20180909
PKGREVISION=	1
TEXLIVE_REV=	48634

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/doi
COMMENT=	Create correct hyperlinks for DOI numbers
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
