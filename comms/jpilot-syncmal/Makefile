# $NetBSD: Makefile,v 1.11 2002/09/10 16:06:35 wiz Exp $

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

DEPENDS+=		jpilot>=0.99:../../comms/jpilot

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_DIR}"
CONFIGURE_ARGS+=	--with-mal-source="${WRKSRC}/../malsync"
CONFIGURE_ARGS+=	--with-plugin-prefix="${BUILDLINK_DIR}/include/jpilot"
CONFIGURE_ARGS+=	--with-pilot-prefix="${BUILDLINK_DIR}"

CFLAGS+=		-D__unix__=1

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libsyncmal.so ${PLUGINSDIR}

.include "../../comms/jpilot/buildlink.mk"
.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
