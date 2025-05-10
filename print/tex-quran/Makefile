# $NetBSD: Makefile,v 1.3 2025/05/10 23:03:22 markd Exp $

DISTNAME=	quran
PKGNAME=	tex-${DISTNAME}-2.41
TEXLIVE_REV=	75029

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/quran
COMMENT=	An easy way to typeset any part of The Holy Quran
LICENSE=	lppl-1.3c

DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
