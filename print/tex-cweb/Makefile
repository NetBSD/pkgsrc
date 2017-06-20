# $NetBSD: Makefile,v 1.3 2017/06/20 22:07:26 markd Exp $

DISTNAME=	cweb
PKGNAME=	tex-${DISTNAME}-3.64b
TEXLIVE_REV=	44166

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cweb
COMMENT=	Web system in C

DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
