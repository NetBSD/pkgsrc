# $NetBSD: Makefile,v 1.9 2021/02/15 03:43:41 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.70.57710
TEXLIVE_REV=	57710

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
