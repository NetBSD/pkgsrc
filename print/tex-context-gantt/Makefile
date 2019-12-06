# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:16 markd Exp $

DISTNAME=	context-gantt
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	27472

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-gantt
COMMENT=	GANTT module for ConTeXt
LICENSE=	public-domain

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-hatching-[0-9]*:../../graphics/tex-hatching

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
