#	$NetBSD: bsd.pkg.use.mk,v 1.12 2005/05/17 22:49:55 jlam Exp $
#
# Turn USE_* macros into proper depedency logic.  Included near the top of
# bsd.pkg.mk, after bsd.prefs.mk.

############################################################################
# ${PREFIX} selection
############################################################################

.if defined(USE_IMAKE) || !empty(USE_TOOLS:Mimake)
INSTALL_TARGET+=	${NO_INSTALL_MANPAGES:D:Uinstall.man}
USE_X11BASE?=		implied
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
MAKE_FLAGS+=		CC=${CC:Q} CXX=${CXX:Q}
.endif

.if defined(USE_X11BASE)
MTREE_FILE?=		${PKGSRCDIR}/mk/${OPSYS}.x11.dist
USE_X11?=		implied
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
LIBTOOL_REQD?=		1.5.14
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

### USE_PERL5, PERL5_REQD

# Distill the PERL5_REQD list into a single _PERL5_REQD value that is the
# highest version of Perl required.
#
PERL5_REQD+=		5.0
PERL5_REQD+=		${_OPSYS_PERL_REQD}

_PERL5_STRICTEST_REQD?=	none
.for _version_ in ${PERL5_REQD}
.  for _pkg_ in perl-${_version_}
.    if ${_PERL5_STRICTEST_REQD} == "none"
_PERL5_PKG_SATISFIES_DEP=	YES
.      for _vers_ in ${PERL5_REQD}
.        if !empty(_PERL5_PKG_SATISFIES_DEP:M[yY][eE][sS])
_PERL5_PKG_SATISFIES_DEP!=	\
	if ${PKG_ADMIN} pmatch 'perl>=${_vers_}' ${_pkg_} 2>/dev/null; then \
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.      if !empty(_PERL5_PKG_SATISFIES_DEP:M[yY][eE][sS])
_PERL5_STRICTEST_REQD=	${_version_}
.      endif
.    endif
.  endfor
.endfor
_PERL5_REQD=	${_PERL5_STRICTEST_REQD}

.if defined(USE_PERL5) || !empty(USE_TOOLS:Mperl)
_PERL5_DEPENDS=		{perl>=${_PERL5_REQD},perl-thread>=${_PERL5_REQD}}
PERL5_PKGSRCDIR?=	../../lang/perl58
.endif

# Convert USE_PERL5 to be two-valued: either "build" or "run" to denote
# whether we want a build-time or run-time dependency on perl.
#
.if defined(USE_PERL5)
.  if (${USE_PERL5} == "build")
_PERL5_DEPMETHOD=	BUILD_DEPENDS
.  else
USE_PERL5:=		run
_PERL5_DEPMETHOD=	DEPENDS
.  endif
_PERL5_DEPENDS=		{perl>=${_PERL5_REQD},perl-thread>=${_PERL5_REQD}}
.  if !defined(BUILDLINK_DEPENDS.perl)
${_PERL5_DEPMETHOD}+=	${_PERL5_DEPENDS}:${PERL5_PKGSRCDIR}
.  endif
.endif

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
.if defined(USE_PERL5) && (${USE_PERL5} == "run")
CONFIGURE_ENV+=		PERL=${PERL5:Q}
.  include "../../lang/perl5/vars.mk"
.endif       # USE_PERL5 == run
.endif

.if defined(USE_PERL5)
PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SUB_INSTALLSITELIB}
PLIST_SUBST+=	PERL5_SITEARCH=${PERL5_SUB_INSTALLSITEARCH}
PLIST_SUBST+=	PERL5_ARCHLIB=${PERL5_SUB_INSTALLARCHLIB}
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

### USE_X11

.if defined(USE_X11)
X11_LDFLAGS+=		${COMPILER_RPATH_FLAG}${X11BASE}/lib${LIBABISUFFIX}
X11_LDFLAGS+=		-L${X11BASE}/lib${LIBABISUFFIX}
.endif

### USE_XPKGWEDGE

.if defined(USE_X11BASE) && !empty(USE_XPKGWEDGE:M[yY][eE][sS])
BUILD_DEPENDS+=		xpkgwedge>=${_XPKGWEDGE_REQD:U1.5}:../../pkgtools/xpkgwedge
.endif
