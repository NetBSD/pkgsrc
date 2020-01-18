# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:52 rillig Exp $

DISTNAME=	context-fullpage
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47085

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-fullpage
COMMENT=	Overfull pages with ConTeXt
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
