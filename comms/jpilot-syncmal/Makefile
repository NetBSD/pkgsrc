# $NetBSD: Makefile,v 1.1.1.1 2001/03/01 20:40:06 jlam Exp $

DISTNAME=		jpilot-syncmal_0.60
PKGNAME=		jpilot-syncmal-0.60
CATEGORIES=		comms
MASTER_SITES=		http://people.atl.mediaone.net/jasonday/code/syncmal/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://people.atl.mediaone.net/jasonday/code/syncmal/syncmal.html
COMMENT=		MAL synchronization plugin for J-Pilot

BUILD_DEPENDS+=		${MALSRC}/client/unix/MAL31UserConfig.c:${MALDIR}:patch
DEPENDS+=		jpilot>=0.99:../../comms/jpilot

MALDIR=			${PKGSRCDIR}/comms/malsync
MALSRC=			${MALDIR}/${WRKDIR:T}/malsync

GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

EVAL_PREFIX+=		GTKDIR=gtk+
EVAL_PREFIX+=		JPILOTDIR=jpilot
EVAL_PREFIX+=		PILOTLINKDIR=pilot-link
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-mal-source="${MALSRC}"
CONFIGURE_ARGS+=	--with-plugin-prefix="${JPILOTDIR}/include/jpilot"
CONFIGURE_ARGS+=	--with-pilot-prefix="${PILOTLINKDIR}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libsyncmal.so ${PLUGINSDIR}

pre-clean:
	@cd ${MALDIR} && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
