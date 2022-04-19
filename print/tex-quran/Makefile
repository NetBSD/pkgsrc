# $NetBSD: Makefile,v 1.1 2022/04/19 02:57:16 markd Exp $

DISTNAME=	quran
PKGNAME=	tex-${DISTNAME}-1.81
TEXLIVE_REV=	57601

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/quran
COMMENT=	An easy way to typeset any part of The Holy Quran
LICENSE=	lppl-1.3c

DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
