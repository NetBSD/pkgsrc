# $NetBSD: Makefile,v 1.49 2004/04/24 04:56:17 minskim Exp $

DISTNAME=		glib-2.4.0
PKGNAME=		${DISTNAME:S/glib/glib2/}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.4/ \
			${MASTER_SITE_GNOME:=sources/glib/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gtk.org/docs/glib_toc.html
COMMENT=		Some useful routines for C programming

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_PERL5=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE=	glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0.pc.in

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=gnu

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

.include "../../mk/bsd.prefs.mk"

# FreeBSD fix for libgthread:
# Be sure libgthread is linked to the threaded library (libc_r), otherwise
# -pthread is added and this won't work with libraries, only executable
# binaries.

.if ${OPSYS} == "FreeBSD"

SUBST_CLASSES=		thr
SUBST_STAGE.thr=	post-patch
SUBST_FILES.thr=	gthread/Makefile.in
SUBST_SED.thr=		-e "s|@G_THREAD_LIBS_FOR_GTHREAD@|-Wc,-lc_r|g"
SUBST_MESSAGE.thr=	"Fixing libgthread."

.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
