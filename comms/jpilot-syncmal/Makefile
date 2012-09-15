# $NetBSD: Makefile,v 1.53 2012/09/15 10:03:58 obache Exp $

DISTNAME=		jpilot-syncmal-0.80
PKGREVISION=		12
CATEGORIES=		comms
MASTER_SITES=		http://www.jlogday.com/code/syncmal/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jlogday.com/code/syncmal/index.html
COMMENT=		MAL synchronization plugin for J-Pilot

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_DEPMETHOD.jpilot=	full

USE_TOOLS+=		gmake pkg-config

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	# empty

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--with-plugin-prefix=${BUILDLINK_PREFIX.jpilot}/include/jpilot
CONFIGURE_ARGS+=	--with-pilot-prefix=${BUILDLINK_PREFIX.pilot-link-libs}
CONFIGURE_ARGS+=	--with-libmal=${BUILDLINK_PREFIX.libmal}
MAKE_ENV+=		PILOT_LINK_DIR=${BUILDLINK_PREFIX.pilot-link-libs}
CFLAGS+=		-D__unix__=1

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

.include "../../comms/jpilot/buildlink3.mk"
.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
