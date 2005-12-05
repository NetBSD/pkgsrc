# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:19 rillig Exp $
#

DISTNAME=	freeglut-2.2.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://freeglut.sourceforge.net/
COMMENT=	Alternative to the OpenGL Utility Toolkit (GLUT) library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-replace-glut

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
