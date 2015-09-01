# $NetBSD: Makefile,v 1.3 2015/09/01 21:41:02 markd Exp $

DISTNAME=	texinfo
PKGNAME=	tex-${DISTNAME}-5.1.37747
TEXLIVE_REV=	37747

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texinfo
COMMENT=	Texinfo documentation system
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb46
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
