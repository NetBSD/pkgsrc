# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:51 rillig Exp $

DISTNAME=	context-cyrillicnumbers
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	29905

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-cyrillicnumbers
COMMENT=	Write numbers as cyrillic glyphs
LICENSE=	modified-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
