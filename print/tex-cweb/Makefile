# $NetBSD: Makefile,v 1.5 2019/01/27 09:54:41 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.70.49278
TEXLIVE_REV=	49278

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cweb
COMMENT=	Web system in C

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
