# $NetBSD: Makefile,v 1.21 2006/08/03 18:22:17 rillig Exp $

DISTNAME=	glitz-0.5.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/glitz
COMMENT=	OpenGL 2D graphics library and a backend for gl output in cairo

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	src/agl/glitz-agl.pc.in src/glx/glitz-glx.pc.in \
			src/glitz.pc.in

.if exists(/System/Library/Frameworks/AGL.framework)
PLIST_SUBST+=	AGL=""
CONFIGURE_ENV+=	AGL_LIBS="-framework AGL"
.else
PLIST_SUBST+=	AGL="@comment "
.endif

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99
.endif

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
