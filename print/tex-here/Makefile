# $NetBSD: Makefile,v 1.3 2019/12/06 20:21:34 markd Exp $

DISTNAME=	here
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	16135

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Emulation of obsolete package for "here" floats

DEPENDS+=	tex-float>=1.3d:../../print/tex-float

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
