# $NetBSD: Makefile,v 1.11 2022/04/15 03:28:44 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.3
TEXLIVE_REV=	62620

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
