# $NetBSD: Makefile,v 1.5 2019/12/06 20:21:47 markd Exp $

DISTNAME=	kotex-utf
PKGNAME=	tex-${DISTNAME}-2.1.2
TEXLIVE_REV=	38558

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/kotex-utf
COMMENT=	Typeset Hangul, coded in UTF-8
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cjk-ko-[0-9]*:../../print/tex-cjk-ko

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
