# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:54 rillig Exp $

DISTNAME=	context-simplefonts
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	29229

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-simplefonts
COMMENT=	Simplified font usage for ConTeXt
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
