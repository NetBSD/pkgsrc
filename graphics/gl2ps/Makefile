# $NetBSD: Makefile,v 1.7 2025/08/17 12:33:31 wiz Exp $

DISTNAME=	gl2ps-1.4.2
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	https://geuz.org/gl2ps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://geuz.org/gl2ps/
COMMENT=	OpenGL to PostScript printing library
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
# TODO: not all of this is needed, please reduce it to the required set
TOOL_DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
