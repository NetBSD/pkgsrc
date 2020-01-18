# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:51 rillig Exp $

DISTNAME=	context-chromato
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	23167

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-chromato
COMMENT=	ConTeXt macros for chromatograms
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
