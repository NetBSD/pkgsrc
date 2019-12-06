# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:09 markd Exp $

DISTNAME=	qtree
PKGNAME=	tex-${DISTNAME}-3.1b
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	TeX package to print a simple trees

DEPENDS+=	tex-pict2e-[0-9]*:../../print/tex-pict2e

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
