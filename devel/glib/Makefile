# $NetBSD: Makefile,v 1.72 2004/10/03 00:13:27 tv Exp $
# FreeBSD Id: Makefile,v 1.2 1998/08/06 14:55:12 vanilla Exp
#

DISTNAME=		glib-1.2.10
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v1.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
			${MASTER_SITE_GNOME:=sources/glib/1.2/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/doc/API/glib/index.html
COMMENT=		Some useful routines for C programming

CONFLICTS=		gtk+-1.0.*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
PKGCONFIG_OVERRIDE=	glib.pc.in
PKGCONFIG_OVERRIDE+=	gmodule.pc.in
PKGCONFIG_OVERRIDE+=	gthread.pc.in
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib

INFO_FILES=		glib.info

TEST_TARGET=		check

PTHREAD_OPTS+=		require
CFLAGS.FreeBSD+=	${PTHREAD_CFLAGS}

.include "../../mk/bsd.prefs.mk"

# Force the result of this configure test, because the testing technique
# breaks with NetBSD's native libpthread.so.
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		glib_cv_rtldglobal_broken=no
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		3.0
.endif

GLIB_VERSION=		${DISTNAME:S/glib-//}
GLIB_MAJOR_VERSION=	${GLIB_VERSION:C/\..*//}
GLIB_MINOR_VERSION=	${GLIB_VERSION:C/[^.]*\.//:C/\..*//}
GLIB_MICRO_VERSION=	${GLIB_VERSION:C/.*\.//}

# We patch the version info in the configure scripts for reasons related to
# shared library numbering, but we don't want it to leak into the various
# installed files.  Explicitly replace the version number with the correct
# one derived from the package name.
#
pre-configure:
	@cd ${WRKSRC};							\
	files="glib-config.in docs/glib-config.1.in glib.pc.in gmodule.pc.in gthread.pc.in"; \
	for f in $${files}; do						\
		${SED}	-e "s|@GLIB_VERSION@|${GLIB_VERSION}|g"		\
			-e "s|@VERSION@|${GLIB_VERSION}|g"		\
			$${f} > $${f}.fixed;				\
		${MV} -f $${f}.fixed $${f};				\
	done

post-configure:
	@cd ${WRKSRC};							\
	files="config.status config.h glibconfig.h";		\
	for f in $${files}; do						\
		${SED}	-e "s|^\(#define.*GLIB_MAJOR_VERSION\).*|\1	${GLIB_MAJOR_VERSION}|" \
			-e "s|^\(#define.*GLIB_MINOR_VERSION\).*|\1	${GLIB_MINOR_VERSION}|" \
			-e "s|^\(#define.*GLIB_MICRO_VERSION\).*|\1	${GLIB_MICRO_VERSION}|" \
			$${f} > $${f}.fixed;				\
		${MV} $${f}.fixed $${f};				\
	done;								\
	${CHMOD} +x config.status
.if exists(/usr/include/sys/null.h)
	@cd ${WRKSRC};							\
	files="glib.h";							\
	for f in $${files}; do						\
		${SED}	-e "s|^#define.NULL.*|#include <sys/null.h>|"	\
			$${f} > $${f}.fixed;				\
		${MV} $${f}.fixed $${f};				\
	done
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
