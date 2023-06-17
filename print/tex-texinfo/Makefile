# $NetBSD: Makefile,v 1.20 2023/06/17 10:45:25 markd Exp $

DISTNAME=	texinfo
PKGNAME=	tex-${DISTNAME}-6.8.67325
TEXLIVE_REV=	67325

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texinfo
COMMENT=	Texinfo documentation system
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
