# $NetBSD: kde3.mk,v 1.18 2016/02/25 15:31:00 jperkin Exp $
#
# This Makefile fragment is included by packages that use the KDE3
# configure-and-build process.
#
# To use this Makefile fragment, simply include this Makefile fragment in
# the package Makefile.
#
# The buildlink strategy with KDE3 packages is:
#
#     * pass UIC to the configure script, as the KDE3 configure scripts now
#	check for its existance and fail if its not found.
#
#     * pass USER_LDFLAGS to the configure script, containing the value of
#	LDFLAGS as set by bsd.pkg.mk; this should pass all of the necessary
#	library directory and rpath settings to the compiler/linker to find
#	the X11, Qt-3.x, and KDE-3.x libraries.
#
# We pass the following values via options to the configure script:
#
#     * datadir is where all of the KDE3 data files go
#     * qt-dir is the location of QT3 for build purposes
#     * extra-includes is where headers for dependencies may be found
#
# We _don't_ pass the following values via options to the configure script:
#
#     * extra-libs contains library directories that are added to both the
#	rpath via -R and to the linker flags via -L; we don't need this
#	since we pass them in directly via ${USER_LDFLAGS}
#
# We also disable the rpath setting by the configure script since it often
# guesses wrong on odd setups, and since we already pass all of the required
# flags through USER_LDFLAGS.
#
# The qt3-tools buildlink3.mk file is also pulled in as all KDE3 pkgs need it.

.if !defined(KDE3_MK)
KDE3_MK=	# defined

USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.fast.prefs.mk"

# work-around bug noted in PR #25402
BUILDLINK_TRANSFORM.Linux+=	rm:-Wl,--no-undefined

OPSYSVARS+=		GCC_REQD
GCC_REQD.SunOS+=	3.3

CONFIGURE_ARGS.NetBSD+=	--disable-pie

KDEDIR?=		${PREFIX}
QTDIR?=			${PREFIX}/qt3

CONFIGURE_ARGS+=	--datadir="${KDEDIR}/share/kde"
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-extra-includes=${_KDE3_EXTRA_INCLUDES:Q}
CONFIGURE_ARGS+=	--disable-rpath
CONFIGURE_ARGS+=	--disable-debug
.if exists(${X11BASE}/lib/libXinerama.so) || ${X11_TYPE} != "native"
CONFIGURE_ARGS+=	--with-xinerama
.include "../../x11/libXinerama/buildlink3.mk"
.endif

CONFIGURE_ENV+=		USER_LDFLAGS=${LDFLAGS:M*:Q}
LDFLAGS+=		-L${QTDIR}/lib

_KDE3_EXTRA_INCLUDES?=	${LOCALBASE}/include:${X11BASE}/include

KDE_CONFIG_SITE?=	${KDEDIR}/share/kde/config.site			\
			${PKG_SYSCONFDIR}/kde/config.site

CONFIGURE_ENV+=		KDEDIR=${KDEDIR:Q}
CONFIGURE_ENV+=		CONFIG_SITE=${KDE_CONFIG_SITE:Q}
CONFIGURE_ENV+=		kde_appsdir="${KDEDIR}/share/kde/applnk"
CONFIGURE_ENV+=		kde_cgidir="${KDEDIR}/kde-cgi-bin"
CONFIGURE_ENV+=		kde_confdir="${KDEDIR}/share/kde/config"
CONFIGURE_ENV+=		kde_datadir="${KDEDIR}/share/kde/apps"
CONFIGURE_ENV+=		kde_htmldir="${KDEDIR}/share/doc/kde/HTML"
CONFIGURE_ENV+=		kde_icondir="${KDEDIR}/share/icons"
CONFIGURE_ENV+=		kde_locale="${KDEDIR}/${PKGLOCALEDIR}/locale"
CONFIGURE_ENV+=		kde_mimedir="${KDEDIR}/share/kde/mimelnk"
CONFIGURE_ENV+=		kde_servicesdir="${KDEDIR}/share/kde/services"
CONFIGURE_ENV+=		kde_servicetypesdir="${KDEDIR}/share/kde/servicetypes"
CONFIGURE_ENV+=		kde_sounddir="${KDEDIR}/share/kde/sounds"
CONFIGURE_ENV+=		kde_templatesdir="${KDEDIR}/share/kde/templates"
CONFIGURE_ENV+=		kde_toolbardir="${KDEDIR}/share/kde/toolbar"
CONFIGURE_ENV+=		kde_wallpaperdir="${KDEDIR}/share/kde/wallpapers"
CONFIGURE_ENV+=		xdg_appsdir="${KDEDIR}/share/applications/kde"
CONFIGURE_ENV+=		xdg_directorydir="${KDEDIR}/share/desktop-directories"

_IN_ARTS_BUILD?=	no
.if !empty(_IN_ARTS_BUILD:M[nN][oO])
BUILDLINK_API_DEPENDS.qt3-libs+=	qt3-libs>=3.3.3nb1
.include "../../x11/qt3-libs/buildlink3.mk"
.endif

.include "../../x11/qt3-tools/buildlink3.mk"

.endif	# KDE3_MK
