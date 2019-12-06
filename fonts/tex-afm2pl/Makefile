# $NetBSD: Makefile,v 1.2 2019/12/06 19:29:30 markd Exp $

DISTNAME=	afm2pl
PKGNAME=	tex-${DISTNAME}-0.7.1
TEXLIVE_REV=	33736

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert an Adobe font metric file to a TeX font property list
LICENSE=	gnu-gpl-v2

DEPENDS+=	afm2pl>=0.7.1:../../fonts/afm2pl

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
