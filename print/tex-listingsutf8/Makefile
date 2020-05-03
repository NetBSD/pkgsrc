# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:40 markd Exp $

DISTNAME=	listingsutf8
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	53097

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/listingsutf8
COMMENT=	Allow UTF-8 in listings input
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-stringenc-[0-9]*:../../print/tex-stringenc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
