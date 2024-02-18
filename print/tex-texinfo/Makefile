# $NetBSD: Makefile,v 1.21 2024/02/18 10:56:00 markd Exp $

DISTNAME=	texinfo
PKGNAME=	tex-${DISTNAME}-6.8.69818
TEXLIVE_REV=	69818

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texinfo
COMMENT=	Texinfo documentation system
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
