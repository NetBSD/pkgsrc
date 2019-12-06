# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:37 markd Exp $

DISTNAME=	uhrzeit
PKGNAME=	tex-${DISTNAME}-0.2c
TEXLIVE_REV=	39570

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/uhrzeit
COMMENT=	Time printing, in German
LICENSE=	lppl-1.3c

DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
