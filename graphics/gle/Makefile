# $NetBSD: Makefile,v 1.34 2020/01/26 17:31:21 rillig Exp $
#

DISTNAME=	gle-3.1.0
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gle/}
MASTER_SITES+=	http://www.linas.org/gle/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.linas.org/gle/
COMMENT=	GL subroutines for drawing tubing and extrusions

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBS+=			-lXext

BUILDLINK_DEPMETHOD.libXt?=	build

# GLUT is used only by the examples, which aren't built or installed.
#.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
