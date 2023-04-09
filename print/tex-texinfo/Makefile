# $NetBSD: Makefile,v 1.19 2023/04/09 06:32:44 markd Exp $

DISTNAME=	texinfo
PKGNAME=	tex-${DISTNAME}-6.8.66701
TEXLIVE_REV=	66701

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texinfo
COMMENT=	Texinfo documentation system
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
