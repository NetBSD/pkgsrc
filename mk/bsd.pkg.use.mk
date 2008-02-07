#	$NetBSD: bsd.pkg.use.mk,v 1.46 2008/02/07 12:26:55 tnn Exp $
#
# Turn USE_* macros into proper depedency logic.  Included near the top of
# bsd.pkg.mk, after bsd.prefs.mk.
#
# Package-settable variables:
#
# USE_BSD_MAKEFILE
#	Should be set to "yes" whenever a package uses a BSD-style
#	Makefile. These Makefiles typically end with a line including
#	<bsd.prog.mk>.

# USE_IMAKE
#	When set to "yes", means that the package uses imake as the
#	primary (and often only) build system. This is different from
#	USE_TOOLS+=imake, which only states that the package uses imake
#	among other tools.
#
#	Keywords: imake
#

.if defined(USE_BSD_MAKEFILE)
MAKE_ENV+=		${BSD_MAKE_ENV}
.endif

.if defined(USE_IMAKE) || !empty(USE_TOOLS:Mimake)
PLIST_SUBST+=		IMAKE_MAN_SOURCE_PATH=${IMAKE_MAN_SOURCE_PATH:Q}
PLIST_SUBST+=		IMAKE_MAN_DIR=${IMAKE_MAN_DIR:Q}
PLIST_SUBST+=		IMAKE_LIBMAN_DIR=${IMAKE_LIBMAN_DIR:Q}
PLIST_SUBST+=		IMAKE_KERNMAN_DIR=${IMAKE_KERNMAN_DIR:Q}
PLIST_SUBST+=		IMAKE_FILEMAN_DIR=${IMAKE_FILEMAN_DIR:Q}
PLIST_SUBST+=		IMAKE_GAMEMAN_DIR=${IMAKE_GAMEMAN_DIR:Q}
PLIST_SUBST+=		IMAKE_MISCMAN_DIR=${IMAKE_MISCMAN_DIR:Q}
PLIST_SUBST+=		IMAKE_MAN_SUFFIX=${IMAKE_MAN_SUFFIX:Q}
PLIST_SUBST+=		IMAKE_LIBMAN_SUFFIX=${IMAKE_LIBMAN_SUFFIX:Q}
PLIST_SUBST+=		IMAKE_KERNMAN_SUFFIX=${IMAKE_KERNMAN_SUFFIX:Q}
PLIST_SUBST+=		IMAKE_FILEMAN_SUFFIX=${IMAKE_FILEMAN_SUFFIX:Q}
PLIST_SUBST+=		IMAKE_GAMEMAN_SUFFIX=${IMAKE_GAMEMAN_SUFFIX:Q}
PLIST_SUBST+=		IMAKE_MISCMAN_SUFFIX=${IMAKE_MISCMAN_SUFFIX:Q}
PLIST_SUBST+=		IMAKE_MANNEWSUFFIX=${IMAKE_MANNEWSUFFIX:Q}
.endif

.if defined(USE_IMAKE) && empty(USE_TOOLS:Mitools)
USE_X11BASE?=		implied
.endif

.if defined(USE_IMAKE)
MAKE_FLAGS+=		CC=${CC:Q} CXX=${CXX:Q}
.endif

.if defined(USE_X11BASE) && ${X11_TYPE} != "modular"
.  include "x11.buildlink3.mk"
.endif

.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
PREFIX=			${DEPOTBASE}/${PKGNAME}
.elif ${PKG_INSTALLATION_TYPE} == "overwrite"
.  if defined(INSTALLATION_PREFIX)
PREFIX=			${INSTALLATION_PREFIX}
.  elif defined(USE_X11BASE)
PREFIX=			${X11PREFIX}
.  elif defined(USE_CROSSBASE)
PREFIX=			${CROSSBASE}
.  else
PREFIX=			${LOCALBASE}
.  endif
.endif

.if (${PKG_INSTALLATION_TYPE} == "pkgviews") && defined(INSTALLATION_PREFIX)
PKG_FAIL_REASON=	"INSTALLATION_PREFIX can't be used in a pkgviews package"
.endif

############################################################################
# General settings
############################################################################

### PKG_USE_KERBEROS

.if defined(PKG_USE_KERBEROS)
CRYPTO?=		uses Kerberos encryption code
BUILD_DEFS+=		KERBEROS
.endif

### USE_DIRS

USE_DIRS?=		# empty
.if !empty(USE_DIRS) && ${PKG_INSTALLATION_TYPE} == "overwrite"
.  include "dirs.mk"
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
LIBTOOL_REQD?=		1.5.18nb5
BUILD_DEPENDS+=		libtool-base>=${_OPSYS_LIBTOOL_REQD:U${LIBTOOL_REQD}}:../../devel/libtool-base
CONFIGURE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
.endif

### USE_XPKGWEDGE

.if (defined(USE_X11BASE) || \
     defined(USE_IMAKE) || !empty(USE_TOOLS:Mimake) || \
     !empty(USE_TOOLS:Mimake\:*:Nimake\:pkgsrc)) && \
    empty(USE_TOOLS:Mitools) && \
    empty(PKGPATH:Mpkgtools/xpkgwedge) && \
    !empty(USE_XPKGWEDGE:M[yY][eE][sS])
BUILD_DEPENDS+=		xpkgwedge>=${_XPKGWEDGE_REQD:U1.15}:../../pkgtools/xpkgwedge
.endif
