# $NetBSD: Makefile,v 1.8 2019/12/06 20:23:45 markd Exp $

DISTNAME=	xkeyval
PKGNAME=	tex-${DISTNAME}-2.7a
TEXLIVE_REV=	35741

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Macros for setting keys and class or package options
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
