# $NetBSD: Makefile,v 1.4 2017/10/16 10:23:04 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.70
TEXLIVE_REV=	45065

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cweb
COMMENT=	Web system in C

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
