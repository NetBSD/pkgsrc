# $NetBSD: Makefile,v 1.3 2023/09/28 21:43:10 joerg Exp $

DISTNAME=	tabularray
PKGNAME=	tex-${DISTNAME}-2023A
PKGREVISION=	1
TEXLIVE_REV=	66276

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tabularray
COMMENT=	Tabular implementation
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-ninecolors-[0-9]*:../../print/tex-ninecolors

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
