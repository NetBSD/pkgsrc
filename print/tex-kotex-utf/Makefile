# $NetBSD: Makefile,v 1.7 2022/09/01 10:46:47 markd Exp $

DISTNAME=	kotex-utf
PKGNAME=	tex-${DISTNAME}-3.0.0
TEXLIVE_REV=	63690

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kotex-utf
COMMENT=	Typeset Hangul, coded in UTF-8
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cjk-ko-[0-9]*:../../print/tex-cjk-ko

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
