# $NetBSD: Makefile,v 1.17 2021/06/05 06:32:36 markd Exp $

DISTNAME=	texinfo
PKGNAME=	tex-${DISTNAME}-5.1.57911
TEXLIVE_REV=	57911

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texinfo
COMMENT=	Texinfo documentation system
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
