# $NetBSD: Makefile,v 1.29 2013/04/13 20:22:25 dholland Exp $
#

DISTNAME=	gle-3.1.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gle/}		\
		http://www.linas.org/gle/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linas.org/gle/
COMMENT=	GL subroutines for drawing tubing and extrusions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBS+=			-lXext

BUILDLINK_DEPMETHOD.libXt?=      build

# GLUT is used only by the examples, which aren't built or installed.
#.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
