# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:01 rillig Exp $

DISTNAME=	uhrzeit
PKGNAME=	tex-${DISTNAME}-0.2c
TEXLIVE_REV=	39570

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/uhrzeit
COMMENT=	Time printing, in German
LICENSE=	lppl-1.3c

DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
