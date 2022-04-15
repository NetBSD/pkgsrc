# $NetBSD: Makefile,v 1.18 2022/04/15 04:49:55 markd Exp $

DISTNAME=	texinfo
PKGNAME=	tex-${DISTNAME}-6.8
TEXLIVE_REV=	62997

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texinfo
COMMENT=	Texinfo documentation system
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
