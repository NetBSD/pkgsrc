# $NetBSD: Makefile,v 1.4 2006/07/13 17:04:51 rillig Exp $
#

DISTNAME=	liboil-0.3.6
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liboil.freedesktop.org/wiki/
COMMENT=	Library of simple, CPU-optimized functions

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-glib # Only used by examples.
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE+=	liboil-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	liboil.pc.in

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.8-*)
pre-configure:
	${ECHO} "#include <inttypes.h>" > ${BUILDLINK_DIR}/include/stdint.h
.endif

.include "../../mk/bsd.pkg.mk"
