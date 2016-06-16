# $NetBSD: Makefile,v 1.2 2016/06/16 04:06:02 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.64af
TEXLIVE_REV=	40768

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Web system in C

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
