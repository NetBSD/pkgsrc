# $NetBSD: Makefile,v 1.18 2001/02/13 11:47:01 tron Exp $

DISTNAME=		ee-0.3.12
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ee/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}
CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}

PLIST_SUBST+=		LOCALEDIR=${LOCALEDIR}

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEDIR}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEDIR=		lib
.else
LOCALEDIR=		share
.endif

.include "../../mk/bsd.pkg.mk"
