# $NetBSD: Makefile,v 1.19 2026/03/29 03:02:32 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-4.3.77830
TEXLIVE_REV=	77830

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	CWEB for ANSI-C/C++ compilers

DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
