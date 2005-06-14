#	$NetBSD: bsd.pkg.use.mk,v 1.20 2005/06/14 20:14:50 jlam Exp $
#
# Turn USE_* macros into proper depedency logic.  Included near the top of
# bsd.pkg.mk, after bsd.prefs.mk.

############################################################################
# ${PREFIX} selection
############################################################################

.if defined(USE_IMAKE) || !empty(USE_TOOLS:Mimake)
PLIST_SUBST+=		IMAKE_MAN_SOURCE_PATH=${IMAKE_MAN_SOURCE_PATH}
PLIST_SUBST+=		IMAKE_MAN_DIR=${IMAKE_MAN_DIR}
PLIST_SUBST+=		IMAKE_LIBMAN_DIR=${IMAKE_LIBMAN_DIR}
PLIST_SUBST+=		IMAKE_KERNMAN_DIR=${IMAKE_KERNMAN_DIR}
PLIST_SUBST+=		IMAKE_FILEMAN_DIR=${IMAKE_FILEMAN_DIR}
PLIST_SUBST+=		IMAKE_MISCMAN_DIR=${IMAKE_MISCMAN_DIR}
PLIST_SUBST+=		IMAKE_MAN_SUFFIX=${IMAKE_MAN_SUFFIX}
PLIST_SUBST+=		IMAKE_LIBMAN_SUFFIX=${IMAKE_LIBMAN_SUFFIX}
PLIST_SUBST+=		IMAKE_KERNMAN_SUFFIX=${IMAKE_KERNMAN_SUFFIX}
PLIST_SUBST+=		IMAKE_FILEMAN_SUFFIX=${IMAKE_FILEMAN_SUFFIX}
PLIST_SUBST+=		IMAKE_MISCMAN_SUFFIX=${IMAKE_MISCMAN_SUFFIX}
PLIST_SUBST+=		IMAKE_MANNEWSUFFIX=${IMAKE_MANNEWSUFFIX}
.endif

.if defined(USE_IMAKE)
USE_X11BASE?=		implied
INSTALL_TARGET+=	${NO_INSTALL_MANPAGES:D:Uinstall.man}
MAKE_FLAGS+=		CC=${CC:Q} CXX=${CXX:Q}
.endif

.if defined(USE_X11BASE)
MTREE_FILE?=		${PKGSRCDIR}/mk/${OPSYS}.x11.dist
.  include "../../mk/x11.buildlink3.mk"
.endif

.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
PREFIX=			${DEPOTBASE}/${PKGNAME}
NO_MTREE=		yes
.elif ${PKG_INSTALLATION_TYPE} == "overwrite"
.  if defined(INSTALLATION_PREFIX)
PREFIX=			${INSTALLATION_PREFIX}
.  elif defined(USE_X11BASE)
PREFIX=			${X11PREFIX}
.  elif defined(USE_CROSSBASE)
PREFIX=			${CROSSBASE}
NO_MTREE=		yes
.  else
PREFIX=			${LOCALBASE}
.  endif
.endif

.if (${PKG_INSTALLATION_TYPE} == "pkgviews") && defined(INSTALLATION_PREFIX)
PKG_SKIP_REASON=	"INSTALLATION_PREFIX can't be used in a pkgviews package"
.endif

############################################################################
# General settings
############################################################################

### BUILD_USES_MSGFMT

.if defined(BUILD_USES_MSGFMT) && \
    (!exists(/usr/bin/msgfmt) || ${_USE_GNU_GETTEXT} == "yes")
BUILD_DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
.endif

### PKG_USE_KERBEROS

.if defined(PKG_USE_KERBEROS)
CRYPTO?=		uses Kerberos encryption code
BUILD_DEFS+=		KERBEROS
.endif

### USE_DIRS

USE_DIRS?=		# empty
.if !empty(USE_DIRS) && ${PKG_INSTALLATION_TYPE} == "overwrite"
.  include "../../mk/dirs.mk"
.endif

### USE_LIBTOOL, PKG_[SH]LIBTOOL

#
# PKG_LIBTOOL is the path to the libtool script installed by libtool-base.
# _LIBTOOL is the path the libtool used by the build, which could be the
#	path to a libtool wrapper script.
# LIBTOOL is the publicly-readable variable that should be used by
#	Makefiles to invoke the proper libtool.
#
PKG_LIBTOOL?=		${LOCALBASE}/bin/libtool
PKG_SHLIBTOOL?=		${LOCALBASE}/bin/shlibtool
_LIBTOOL?=		${PKG_LIBTOOL}
_SHLIBTOOL?=		${PKG_SHLIBTOOL}
LIBTOOL?=		${PKG_LIBTOOL}
SHLIBTOOL?=		${PKG_SHLIBTOOL}
.if defined(USE_LIBTOOL)
LIBTOOL_REQD?=		1.5.18nb1
BUILD_DEPENDS+=		libtool-base>=${_OPSYS_LIBTOOL_REQD:U${LIBTOOL_REQD}}:../../devel/libtool-base
CONFIGURE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
LIBTOOL_OVERRIDE?=	libtool */libtool */*/libtool
.endif

### USE_MAKEINFO, INFO_FILES

INFO_FILES?=		# empty
USE_MAKEINFO?=		no

.if !empty(INFO_FILES) || empty(USE_MAKEINFO:M[nN][oO])
.  include "../../mk/texinfo.mk"
.endif

### USE_RMAN

# Check if we got "rman" with XFree86, for packages that need "rman".
.if defined(USE_RMAN)
.  if !exists(${X11BASE}/bin/rman)
DEPENDS+=		rman-3.0.9:../../textproc/rman
RMAN?=			${LOCALBASE}/bin/rman
.  else
RMAN?=			${X11BASE}/bin/rman
.  endif
.endif

### USE_XPKGWEDGE

.if (defined(USE_X11BASE) || \
     defined(USE_IMAKE) || !empty(USE_TOOLS:Mimake)) && \
    !empty(USE_XPKGWEDGE:M[yY][eE][sS])
BUILD_DEPENDS+=		xpkgwedge>=${_XPKGWEDGE_REQD:U1.14}:../../pkgtools/xpkgwedge
.endif
