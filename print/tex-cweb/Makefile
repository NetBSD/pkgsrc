# $NetBSD: Makefile,v 1.13 2022/09/22 10:10:08 wiz Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.3.63787
PKGREVISION=	1
TEXLIVE_REV=	63787

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
