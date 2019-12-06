# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:16 markd Exp $

DISTNAME=	context-letter
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47085

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-letter
COMMENT=	ConTeXt package for writing letters
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
