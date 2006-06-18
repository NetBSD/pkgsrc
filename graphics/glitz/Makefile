# $NetBSD: Makefile,v 1.17 2006/06/18 13:17:12 minskim Exp $

DISTNAME=	glitz-0.4.4
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/glitz
COMMENT=	OpenGL 2D graphics library and a backend for gl output in cairo

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	src/agl/glitz-agl.pc.in src/glx/glitz-glx.pc.in \
			src/glitz.pc.in

LIBS.Darwin+=		-lXext

.if exists(/System/Library/Frameworks/AGL.framework)
PLIST_SUBST+=	AGL=""
.else
PLIST_SUBST+=	AGL="@comment "
.endif

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99
.endif

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
