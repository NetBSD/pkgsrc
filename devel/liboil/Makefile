# $NetBSD: Makefile,v 1.25 2023/12/30 20:58:29 zafer Exp $
#

DISTNAME=	liboil-0.3.17
CATEGORIES=	devel
MASTER_SITES=	https://liboil.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://liboil.freedesktop.org/wiki/
COMMENT=	Library of simple, CPU-optimized functions

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-glib # Only used by examples.

PKGCONFIG_OVERRIDE+=	liboil-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	liboil.pc.in

TEST_TARGET=		check

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.8-*)
SUBST_CLASSES+=		solaris
SUBST_STAGE.solaris=	pre-configure
SUBST_MESSAGE.solaris=	Replacing <stdint.h> with <inttypes.h>
SUBST_FILES.solaris=	liboil/*.h
SUBST_SED.solaris=	-e 's,<stdint\.h>,<inttypes.h>,'
.endif

.include "../../mk/bsd.pkg.mk"
