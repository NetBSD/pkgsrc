# $NetBSD: Makefile,v 1.16 2023/06/17 10:13:12 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.3.67372
TEXLIVE_REV=	67372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
