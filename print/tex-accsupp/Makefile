# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:34 markd Exp $

DISTNAME=	accsupp
PKGNAME=	tex-${DISTNAME}-0.6
TEXLIVE_REV=	53052

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/accsupp
COMMENT=	Better accessibility support for PDF files
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
