# $NetBSD: Makefile,v 1.22 2006/11/05 17:23:44 joerg Exp $

DISTNAME=	glitz-0.5.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/glitz
COMMENT=	OpenGL 2D graphics library and a backend for gl output in cairo

PKG_DESTDIR_SUPPORT=	user-destdir

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
