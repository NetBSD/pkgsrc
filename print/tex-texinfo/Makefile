# $NetBSD: Makefile,v 1.2 2015/06/14 12:50:06 markd Exp $

DISTNAME=	texinfo
PKGNAME=	tex-${DISTNAME}-5.1.37342
TEXLIVE_REV=	37342

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Texinfo documentation system
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb46
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
