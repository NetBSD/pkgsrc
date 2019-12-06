# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:10 markd Exp $

DISTNAME=	realscripts
PKGNAME=	tex-${DISTNAME}-0.3d
TEXLIVE_REV=	39706

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Access OpenType subscript and superscript glyphs
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fontspec>=2.1e:../../fonts/tex-fontspec

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
