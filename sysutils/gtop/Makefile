# $NetBSD: Makefile,v 1.7 2000/11/09 22:28:21 mycroft Exp $

DISTNAME=		gtop-1.0.9
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtop/}

MAINTAINER=		tron@netbsd.org

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
BUILD_DEPENDS+=		automake:../../devel/automake
DEPENDS+=		gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.9:../../devel/libgtop

USE_GMAKE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=            # defined

GNU_CONFIGURE=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		LOCALEBASE=${LOCALEBASE}

PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEBASE}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEBASE=		lib
.else
LOCALEBASE=		share
.endif

.include "../../mk/bsd.pkg.mk"
