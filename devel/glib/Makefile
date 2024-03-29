# $NetBSD: Makefile,v 1.97 2024/03/16 21:33:11 nia Exp $

DISTNAME=		glib-1.2.10
PKGREVISION=		11
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glib/1.2/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://developer.gnome.org/glib/
COMMENT=		Some useful routines for C programming (glib1)
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		gtk+-1.0.*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	glib.pc.in
PKGCONFIG_OVERRIDE+=	gmodule.pc.in
PKGCONFIG_OVERRIDE+=	gthread.pc.in
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

TEST_TARGET=		check

PTHREAD_OPTS+=		require

.include "../../mk/bsd.prefs.mk"

# Force the result of this configure test, because the testing technique
# breaks with NetBSD's native libpthread.so.
CONFIGURE_ENV.NetBSD+=	glib_cv_rtldglobal_broken=no

# Tests are insufficient, override with correct values.
.if ${OPSYS} == "Darwin" && ${PKGSRC_COMPILER:Mclang}
CONFIGURE_ENV+=		glib_cv_has__inline=yes
CONFIGURE_ENV+=		glib_cv_has__inline__=yes
CONFIGURE_ENV+=		glib_cv_hasinline=yes
.endif

GLIB_VERSION=		${DISTNAME:S/glib-//}
GLIB_MAJOR_VERSION=	${GLIB_VERSION:C/\..*//}
GLIB_MINOR_VERSION=	${GLIB_VERSION:C/[^.]*\.//:C/\..*//}
GLIB_MICRO_VERSION=	${GLIB_VERSION:C/.*\.//}

SUBST_CLASSES+=		shlib1
SUBST_MESSAGE.shlib1=	Fixing shared library versions (part 1)
SUBST_STAGE.shlib1=	pre-configure
SUBST_FILES.shlib1=	glib-config.in docs/glib-config.1.in glib.pc.in \
			gmodule.pc.in gthread.pc.in
SUBST_VARS.shlib1=	GLIB_VERSION
SUBST_SED.shlib1+=	-e "s|@VERSION@|${GLIB_VERSION}|g"

SUBST_CLASSES+=		shlib2
SUBST_MESSAGE.shlib2=	Fixing shared library versions (part 2)
SUBST_STAGE.shlib2=	post-configure
SUBST_FILES.shlib2=	config.status config.h glibconfig.h
SUBST_SED.shlib2=	-e "s|^\\(\#define.*GLIB_MAJOR_VERSION\\).*|\\1	${GLIB_MAJOR_VERSION}|"
SUBST_SED.shlib2+=	-e "s|^\\(\#define.*GLIB_MINOR_VERSION\\).*|\\1	${GLIB_MINOR_VERSION}|"
SUBST_SED.shlib2+=	-e "s|^\\(\#define.*GLIB_MICRO_VERSION\\).*|\\1	${GLIB_MICRO_VERSION}|"

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath=	glib-config.in
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

#post-configure:
#	${CHMOD} +x config.status

.if exists(/usr/include/sys/null.h)
SUBST_CLASSES+=		null
SUBST_MESSAGE.null=	Using "sys/null.h" to get definition of NULL.
SUBST_STAGE.null=	post-configure
SUBST_FILES.null=	glib.h
SUBST_SED.null=		-e "s|^\#define.NULL.*|\#include <sys/null.h>|"
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
