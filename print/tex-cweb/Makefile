# $NetBSD: Makefile,v 1.8 2020/05/01 00:15:12 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.70.54276
TEXLIVE_REV=	54276

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
