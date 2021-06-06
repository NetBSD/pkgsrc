# $NetBSD: Makefile,v 1.10 2021/06/06 11:58:20 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.2
TEXLIVE_REV=	57972

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
