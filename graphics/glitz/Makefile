# $NetBSD: Makefile,v 1.6 2005/02/09 21:20:03 xtraeme Exp $

DISTNAME=	glitz-0.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/glitz
COMMENT=	OpenGL 2D graphics library and a backend for gl output in cairo

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	glitz-agl.pc.in glitz-glx.pc.in glitz.pc.in
USE_X11=		yes

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
