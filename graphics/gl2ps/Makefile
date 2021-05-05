# $NetBSD: Makefile,v 1.2 2021/05/05 13:00:56 thor Exp $

DISTNAME=	gl2ps-1.4.2
CATEGORIES=	graphics
MASTER_SITES=	https://geuz.org/gl2ps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://geuz.org/gl2ps/
COMMENT=	OpenGL to PostScript printing library
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
