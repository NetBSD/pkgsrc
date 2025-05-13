# $NetBSD: Makefile,v 1.1 2025/05/13 09:17:41 markd Exp $

DISTNAME=	latex2pydata
PKGNAME=	tex-${DISTNAME}-0.6.0
TEXLIVE_REV=	74766

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex2pydata
COMMENT=	Write data to file in Python literal format
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fvextra-[0-9]*:../../print/tex-fvextra
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
