# $NetBSD: Makefile,v 1.17 2024/02/03 04:39:45 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.3.69586
TEXLIVE_REV=	69586

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
