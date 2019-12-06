# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:19 markd Exp $

DISTNAME=	context-typescripts
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	25411

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-typescripts
COMMENT=	Small modules to load various fonts for use in ConTeXt
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
