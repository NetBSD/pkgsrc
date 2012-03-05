# $NetBSD: Makefile,v 1.1.1.1 2012/03/05 16:20:18 minskim Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.64ad
TEXLIVE_REV=	23089

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Web system in C

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
