# $NetBSD: Makefile,v 1.4 2001/03/02 17:38:09 jlam Exp $

DISTNAME=		jpilot-syncmal_0.60
PKGNAME=		jpilot-syncmal-0.60
CATEGORIES=		comms
MASTER_SITES=		http://people.atl.mediaone.net/jasonday/code/syncmal/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		malsync_2.0.5.src${EXTRACT_SUFX}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://people.atl.mediaone.net/jasonday/code/syncmal/syncmal.html
COMMENT=		MAL synchronization plugin for J-Pilot

DEPENDS+=		jpilot>=0.99:../../comms/jpilot

GNU_CONFIGURE=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

EVAL_PREFIX+=		GTKDIR=gtk+
EVAL_PREFIX+=		JPILOTDIR=jpilot
EVAL_PREFIX+=		PILOTLINKDIR=pilot-link
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-mal-source="${WRKSRC}/../malsync"
CONFIGURE_ARGS+=	--with-plugin-prefix="${JPILOTDIR}/include/jpilot"
CONFIGURE_ARGS+=	--with-pilot-prefix="${PILOTLINKDIR}"

CFLAGS+=		-D__unix__=1

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libsyncmal.so ${PLUGINSDIR}

.include "../../mk/bsd.pkg.mk"
