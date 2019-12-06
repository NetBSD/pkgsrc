# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:17 markd Exp $

DISTNAME=	context-simplefonts
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	29229

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-simplefonts
COMMENT=	Simplified font usage for ConTeXt
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
