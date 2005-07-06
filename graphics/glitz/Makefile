# $NetBSD: Makefile,v 1.10 2005/07/06 18:23:27 drochner Exp $

DISTNAME=	glitz-0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/glitz
COMMENT=	OpenGL 2D graphics library and a backend for gl output in cairo

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	glitz-agl.pc.in glitz-glx.pc.in glitz.pc.in

LIBS.Darwin+=		-lXext

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
