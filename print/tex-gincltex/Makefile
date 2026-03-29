# $NetBSD: Makefile,v 1.2 2026/03/29 10:39:04 markd Exp $

DISTNAME=	gincltex
PKGNAME=	tex-${DISTNAME}-0.3.78251
TEXLIVE_REV=	78251

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/gincltex
COMMENT=	Include TeX files as graphics (.tex support for \includegraphics)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-adjustbox-[0-9]*:../../print/tex-adjustbox
DEPENDS+=	tex-svn-prov-[0-9]*:../../print/tex-svn-prov

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
