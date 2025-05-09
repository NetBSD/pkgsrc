# $NetBSD: Makefile,v 1.18 2025/05/09 23:35:11 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.3.73848
TEXLIVE_REV=	73848

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
