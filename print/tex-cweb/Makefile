# $NetBSD: Makefile,v 1.7 2020/01/18 23:33:59 rillig Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.70.49278
TEXLIVE_REV=	49278

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cweb
COMMENT=	Web system in C

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
