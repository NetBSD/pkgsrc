# $NetBSD: Makefile,v 1.7 2019/12/06 20:22:03 markd Exp $

DISTNAME=	moreverb
PKGNAME=	tex-${DISTNAME}-2.3a
TEXLIVE_REV=	22126

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended verbatim
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
