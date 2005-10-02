# $NetBSD: Makefile,v 1.82 2005/10/02 12:15:09 jmmv Exp $

DISTNAME=		glib-2.8.2
PKGNAME=		${DISTNAME:S/glib/glib2/}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.8/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.8/ \
			${MASTER_SITE_GNOME:=sources/glib/2.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gtk.org/docs/glib_toc.html
COMMENT=		Some useful routines for C programming (glib2)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
USE_LIBTOOL=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE=	glib-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-no-export-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-no-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=gnu

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

CONFIGURE_ENV+=		PERL_PATH=${PERL5}

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""
CPPFLAGS+=		-DPKGLOCALEDIR="\"${PKGLOCALEDIR}\""
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

.if ${OPSYS} == "FreeBSD"

SUBST_CLASSES=		thr
SUBST_STAGE.thr=	post-patch
SUBST_FILES.thr=	gthread/Makefile.in
.  if ${OS_VERSION:R} >= 5
SUBST_SED.thr=		-e "s|@G_THREAD_LIBS_FOR_GTHREAD@|-lpthread|g"
.  else
SUBST_SED.thr=		-e "s|@G_THREAD_LIBS_FOR_GTHREAD@|-Wc,-lc_r|g"
.  endif
SUBST_MESSAGE.thr=	"Fixing libgthread."

.endif

# Handle directories shared with devel/glib.
PRINT_PLIST_AWK+=	/^@dirrm include\/glib$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
