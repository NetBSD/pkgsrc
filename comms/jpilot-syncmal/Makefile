# $NetBSD: Makefile,v 1.18 2003/12/13 00:45:22 wiz Exp $

DISTNAME=		jpilot-syncmal_0.71.2
PKGREVISION=		3
PKGNAME=		jpilot-syncmal-0.71.2
CATEGORIES=		comms
MASTER_SITES=		http://jasonday.home.att.net/code/syncmal/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://jasonday.home.att.net/code/syncmal/syncmal.html
COMMENT=		MAL synchronization plugin for J-Pilot

BUILDLINK_DEPMETHOD.jpilot=	full

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined

USE_LIBTOOL=		# defined
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--with-plugin-prefix=${BUILDLINK_PREFIX.jpilot}/include/jpilot
CONFIGURE_ARGS+=	--with-pilot-prefix=${BUILDLINK_PREFIX.pilot-link-libs}
MAKE_ENV+=		PILOT_LINK_DIR=${BUILDLINK_PREFIX.pilot-link-libs}
CFLAGS+=		-D__unix__=1

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

.include "../../comms/jpilot/buildlink2.mk"
.include "../../comms/pilot-link-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
