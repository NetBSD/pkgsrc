# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:15 markd Exp $

DISTNAME=	context-fullpage
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47085

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-fullpage
COMMENT=	Overfull pages with ConTeXt
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
