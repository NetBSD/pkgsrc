# $NetBSD: Makefile,v 1.9 2006/10/23 18:39:24 drochner Exp $
#

DISTNAME=	liboil-0.3.9
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liboil.freedesktop.org/wiki/
COMMENT=	Library of simple, CPU-optimized functions

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-glib # Only used by examples.
#CONFIGURE_ARGS+=	--enable-debug

PKGCONFIG_OVERRIDE+=	liboil-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	liboil.pc.in

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.8-*)
SUBST_CLASSES+=		solaris
SUBST_STAGE.solaris=	pre-configure
SUBST_MESSAGE.solaris=	Replacing <stdint.h> with <inttypes.h>
SUBST_FILES.solaris=	liboil/*.h
SUBST_SED.solaris=	-e 's,<stdint\.h>,<inttypes.h>,'
.endif

.include "../../mk/bsd.pkg.mk"
