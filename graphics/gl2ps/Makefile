# $NetBSD: Makefile,v 1.5 2022/08/11 05:08:41 gutteridge Exp $

DISTNAME=	gl2ps-1.4.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://geuz.org/gl2ps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://geuz.org/gl2ps/
COMMENT=	OpenGL to PostScript printing library
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
