# $NetBSD: Makefile,v 1.33 2005/09/28 20:52:18 rillig Exp $

DISTNAME=		jpilot-syncmal_0.71.2
PKGNAME=		jpilot-syncmal-0.71.2
PKGREVISION=		5
CATEGORIES=		comms
MASTER_SITES=		http://jasonday.home.att.net/code/syncmal/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://jasonday.home.att.net/code/syncmal/syncmal.html
COMMENT=		MAL synchronization plugin for J-Pilot

BUILDLINK_DEPMETHOD.jpilot=	full

USE_TOOLS+=		gmake pkg-config

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--with-plugin-prefix=${BUILDLINK_PREFIX.jpilot}/include/jpilot
CONFIGURE_ARGS+=	--with-pilot-prefix=${BUILDLINK_PREFIX.pilot-link-libs}
MAKE_ENV+=		PILOT_LINK_DIR=${BUILDLINK_PREFIX.pilot-link-libs}
CFLAGS+=		-D__unix__=1

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

.include "../../comms/jpilot/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
