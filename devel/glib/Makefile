# $NetBSD: Makefile,v 1.40 2001/12/24 19:38:07 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1998/08/06 14:55:12 vanilla Exp
#

DISTNAME=		glib-1.2.10
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v1.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
			http://www.ameth.org/gimp/pub/gtk/v1.2/ \
			${MASTER_SITE_GNOME:=stable/sources/glib/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gtk.org/docs/glib_toc.html
COMMENT=		Some useful routines for C programming

CONFLICTS=		gtk+-1.0.*

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib

INFO_FILES=		glib.info

# XXX egcs is still broken on arm32.
.if (${MACHINE_ARCH} == arm32)
CFLAGS=		-O0
.endif

# GLib needs a working pthreads implementation, and pth is proven to work.
USE_PTHREAD=	native pth

.include "../../mk/bsd.prefs.mk"

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
	for file in $${files}; do					\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|@GLIB_VERSION@|${GLIB_VERSION}|g"		\
			-e "s|@VERSION@|${GLIB_VERSION}|g"		\
			$${file}.fixme > $${file};			\
		${RM} $${file}.fixme;					\
	done

post-configure:
	@cd ${WRKSRC};							\
	files="config.status config.h glibconfig.h";			\
	for file in $${files}; do					\
		${MV} $${file} $${file}.fixme;				\
		${SED}	-e "s|^\(#define.*GLIB_MAJOR_VERSION\).*|\1	${GLIB_MAJOR_VERSION}|" \
			-e "s|^\(#define.*GLIB_MINOR_VERSION\).*|\1	${GLIB_MINOR_VERSION}|" \
			-e "s|^\(#define.*GLIB_MICRO_VERSION\).*|\1	${GLIB_MICRO_VERSION}|" \
			$${file}.fixme > $${file};			\
		${RM} $${file}.fixme;					\
	done;								\
	${CHMOD} +x config.status
.if exists(/usr/include/sys/null.h)
	@cd ${WRKSRC};							\
	${MV} glib.h glib.h.fixme;					\
	${SED} -e 's|^#define.NULL.*|#include <sys/null.h>|'		\
	    glib.h.fixme >glib.h;					\
	${RM} glib.h.fixme
.endif

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
