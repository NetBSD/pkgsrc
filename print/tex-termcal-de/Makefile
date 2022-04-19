# $NetBSD: Makefile,v 1.1 2022/04/19 03:11:48 markd Exp $

DISTNAME=	termcal-de
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	47111

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/termcal-de
COMMENT=	German localization for termcal
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgfopts-[0-9]*:../../devel/tex-pgfopts
DEPENDS+=	tex-termcal-[0-9]*:../../print/tex-termcal

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
