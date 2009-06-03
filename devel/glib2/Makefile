# $NetBSD: Makefile,v 1.161 2009/06/03 12:40:32 obache Exp $

# When updating glib2, please apply patch-ak to configure.in
# Then run a matching version of autoconf to regen patch-aa.
DISTNAME=		glib-2.20.2
PKGNAME=		${DISTNAME:S/glib/glib2/}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/glib/2.20/ \
			${MASTER_SITE_GNOME:=sources/glib/2.20/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/doc/API/2.0/glib/glib.html
COMMENT=		Some useful routines for C programming (glib2)
LICENSE=		gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl:run pkg-config
USE_LANGUAGES=		c c++ c99
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
PKGCONFIG_OVERRIDE+=	gio-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-unix-2.0.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}
CONFIGURE_ARGS.gnu-iconv+=	--with-libiconv=gnu
CONFIGURE_ARGS+=	--with-pcre=system

CONFIGURE_ENV+=		PERL_PATH=${PERL5:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# configure detects wrongly
CONFIGURE_ENV+=		ac_cv_func_statfs=no
.endif

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""
CPPFLAGS+=		-DPKGLOCALEDIR="\"${PKGLOCALEDIR}\""
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

.if ${OPSYS} == "FreeBSD"
SUBST_CLASSES+=		thr
SUBST_STAGE.thr=	post-patch
SUBST_FILES.thr=	gthread/Makefile.in
.  if ${OS_VERSION:R} >= 5
SUBST_SED.thr+=		-e "s|@G_THREAD_LIBS_FOR_GTHREAD@|-lpthread|g"
.  else
SUBST_SED.thr+=		-e "s|@G_THREAD_LIBS_FOR_GTHREAD@|-Wc,-lc_r|g"
.  endif
SUBST_MESSAGE.thr=	Fixing libgthread.

.endif

.if !empty(MACHINE_PLATFORM:MDarwin-[56].*-*)
CONFIGURE_ENV+=		gt_cv_c_wchar_t=no
.endif

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=		gtkdoc-rebase

.if ${OPSYS} == "HPUX"
CONFIGURE_ENV+=		ac_cv_func_mmap_fixed_mapped=yes
.endif

# Handle directories shared with devel/glib.
PRINT_PLIST_AWK+=	/^@dirrm include\/glib$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

PLIST_VARS+=		fam

.if ${OPSYS} != "HPUX" && ${OPSYS} != "OSF1"
.include "options.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CONFIGURE_ARGS+=	--disable-threads
.else
.include "../../mk/pthread.buildlink3.mk"
.endif
# need pcre utf8 + unicode-properties
BUILDLINK_API_DEPENDS.pcre+= pcre>=7.4nb1
.include "../../devel/pcre/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
