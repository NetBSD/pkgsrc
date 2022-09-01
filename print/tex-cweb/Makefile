# $NetBSD: Makefile,v 1.12 2022/09/01 10:26:59 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.3.63787
TEXLIVE_REV=	63787

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
