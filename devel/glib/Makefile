# $NetBSD: Makefile,v 1.36 2001/06/19 06:04:41 jlam Exp $
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

USE_BUILDINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib

INFO_FILES=		glib.info

# XXX egcs is still broken on arm32.
.if (${MACHINE_ARCH} == arm32)
CFLAGS=		-O0
.endif

.include "../../mk/bsd.prefs.mk"

# GLib needs a working pthreads implementation, and pth is proven to work.
.if (${OPSYS} != SunOS)
.include "../../devel/pth/buildlink.mk"
.endif

GLIB_VERSION=		${DISTNAME:S/glib-//}

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

.include "../../mk/bsd.pkg.mk"
