# $NetBSD: Makefile,v 1.12 2002/09/21 07:25:02 jlam Exp $

DISTNAME=		jpilot-syncmal_0.60
PKGNAME=		jpilot-syncmal-0.60
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://people.atl.mediaone.net/jasonday/code/syncmal/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		malsync_2.0.5.src${EXTRACT_SUFX}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://people.atl.mediaone.net/jasonday/code/syncmal/syncmal.html
COMMENT=		MAL synchronization plugin for J-Pilot

BUILDLINK_DEPMETHOD.jpilot=	full

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
CONFIGURE_ARGS+=	--with-mal-source="${WRKSRC}/../malsync"
CONFIGURE_ARGS+=	--with-plugin-prefix="${BUILDLINK_PREFIX.jpilot}/include/jpilot"
CONFIGURE_ARGS+=	--with-pilot-prefix="${BUILDLINK_PREFIX.pilot-link-libs}"

CFLAGS+=		-D__unix__=1

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libsyncmal.so ${PLUGINSDIR}

.include "../../comms/jpilot/buildlink2.mk"
.include "../../comms/pilot-link-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
