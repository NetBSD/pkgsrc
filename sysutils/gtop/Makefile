# $NetBSD: Makefile,v 1.14 2001/02/17 17:42:14 wiz Exp $

DISTNAME=		gtop-1.0.9
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtop/}

MAINTAINER=		tron@netbsd.org
COMMENT=		GNOME system monitor - top like, memory graphs, processes detailed view

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=		msgfmt:../../devel/gettext
BUILD_DEPENDS+=		gettextize:../../devel/gettext
DEPENDS+=		gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.9:../../devel/libgtop

OSVERSION_SPECIFIC=	YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_LIBINTL=		YES

GNU_CONFIGURE=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}
CFLAGS+=		-I${LOCALBASE}/include

PLIST_SUBST+=		LOCALEDIR=${LOCALEDIR}

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

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
