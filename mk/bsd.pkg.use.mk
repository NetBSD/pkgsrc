#	$NetBSD: bsd.pkg.use.mk,v 1.61 2016/06/19 18:01:58 wiz Exp $
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
MAKE_ENV+=		${BSD_MAKE_ENV} INSTALL=${TOOLS_INSTALL:Q}
.  if defined(HAVE_LLVM)
MAKE_ENV+=		HAVE_LLVM=${HAVE_LLVM:Q}
.  endif
.  if defined(HAVE_GCC)
MAKE_ENV+=		HAVE_GCC=${HAVE_GCC:Q}
.  endif
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

.if defined(USE_IMAKE)
MAKE_FLAGS+=		CC=${CC:Q} CXX=${CXX:Q}
.endif

.if defined(INSTALLATION_PREFIX)
PREFIX=			${INSTALLATION_PREFIX}
.else
PREFIX=			${LOCALBASE}
.endif

############################################################################
# General settings
############################################################################

### PKG_USE_KERBEROS

.if defined(PKG_USE_KERBEROS)
CRYPTO?=		uses Kerberos encryption code
BUILD_DEFS+=		KERBEROS
.endif

### USE_LIBTOOL, PKG_[SH]LIBTOOL

#
# PKG_LIBTOOL is the path to the libtool script installed by libtool-base.
# LIBTOOL is the publicly-readable variable that should be used by
#	Makefiles to invoke the proper (wrapped) libtool.
#
.if defined(USE_LANGUAGES) && !empty(USE_LANGUAGES:Mfortran) || \
    defined(USE_LANGUAGES) && !empty(USE_LANGUAGES:Mfortran77)
.  if !empty(USE_CROSS_COMPILE:M[yY][eE][sS]) # XXX
PKG_FAIL_REASON+=	"Cross-compiling Fortran with libtool NYI."
.  endif

PKG_LIBTOOL?=		${LOCALBASE}/bin/libtool-fortran
PKG_SHLIBTOOL?=		${LOCALBASE}/bin/shlibtool-fortran

.  if defined(USE_LIBTOOL)
BUILD_DEPENDS+=		libtool-fortran>=${_OPSYS_LIBTOOL_REQD:U${LIBTOOL_REQD}}:../../devel/libtool-fortran
.  endif
.else
.  if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
PKG_LIBTOOL?=		${CROSSBASE}/bin/libtool
PKG_SHLIBTOOL?=		${CROSSBASE}/bin/shlibtool
.  else
PKG_LIBTOOL?=		${LOCALBASE}/bin/libtool
PKG_SHLIBTOOL?=		${LOCALBASE}/bin/shlibtool
.  endif
.endif
LIBTOOL?=		${WRAPPER_BINDIR}/libtool
SHLIBTOOL?=		${WRAPPER_BINDIR}/shlibtool
.if defined(USE_LIBTOOL)
LIBTOOL_REQD?=		2.2.6bnb3
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
TOOL_DEPENDS+=		cross-libtool-base-${MACHINE_ARCH}>=${_OPSYS_LIBTOOL_REQD:U${LIBTOOL_REQD}}:../../cross/libtool-base
.else
TOOL_DEPENDS+=		libtool-base>=${_OPSYS_LIBTOOL_REQD:U${LIBTOOL_REQD}}:../../devel/libtool-base
.endif
CONFIGURE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
.endif
