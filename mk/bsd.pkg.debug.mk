# $NetBSD: bsd.pkg.debug.mk,v 1.5 2006/07/20 17:56:27 rillig Exp $
#

# The `debug' target outputs the values of some commonly used variables
# and the contents of some files which are useful for tracking bugs,
# especially for packages that use the GNU autotools.
#
# The `build-env' target is intended to be used interactively when
# debugging build problems. It runs a shell in exactly the same
# environment as in the default do-build target, starting in WRKSRC.

PRINTF?=	printf

.PHONY: \
	debug \
	_show-dbginfo-file-versions \
	_show-dbginfo-tools \
	_show-dbginfo-configure \
	_show-dbginfo-config.status \
	_show-dbginfo-config.h \
	_show-dbginfo-build \
	_show-dbginfo-install \
	_show-dbginfo-plist-subst

debug: \
	_show-dbginfo-file-versions \
	_show-dbginfo-tools \
	_show-dbginfo-configure \
	_show-dbginfo-config.status \
	_show-dbginfo-config.h \
	_show-dbginfo-build \
	_show-dbginfo-install \
	_show-dbginfo-plist-subst

_show-dbginfo-file-versions:
	@${PRINTF} "File versions:\\n"
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	sedexpr='s,.*\([$$]NetBSD:[^$$]*\$$\).*,\1,p';			\
	${FIND} * -type f -print					\
	| while read fname; do						\
	  ident=`${SED} -n "$${sedexpr}" "$${fname}"` || continue;	\
	  case $${ident} in						\
	  *?*) ${PRINTF} "\\t%s: %s\\n" "$${fname}" "$${ident}";;	\
	  esac;								\
	done

# Use an ODE variable loop to output the "TOOL" name and value for each
# unique tool listed in USE_TOOLS.
#
_show-dbginfo-tools:
	@${PRINTF} "TOOLS:\\n"
	@${USE_TOOLS:C/:.*//:O:u:@_t_@${_TOOLS_VARNAME.${_t_}:D${PRINTF} "\\t%s=%s\\n" ${_TOOLS_VARNAME.${_t_}} ${${_TOOLS_VARNAME.${_t_}}:Q};}@}

_show-dbginfo-configure:
	@${PRINTF} "CONFIGURE_DIRS:\\n"
	@${PRINTF} "\\t%s\\n" ${CONFIGURE_DIRS}
	@${PRINTF} "CONFIGURE_ENV (sorted alphabetically):\\n"
	@${PRINTF} "\\t%s\\n" ${CONFIGURE_ENV:O}
	@${PRINTF} "CONFIGURE_SCRIPT:\\n\\t%s\\n" ${CONFIGURE_SCRIPT:Q}
	@${PRINTF} "CONFIGURE_ARGS:\\n"
	@${CONFIGURE_ARGS:@_ca_@${PRINTF} "\\t%s\\n" ${_ca_:Q};@}

_show-dbginfo-config.status:
.if !empty(CONFIGURE_DIRS:M*)
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	if ${TEST} -d ${WRKSRC:Q}; then cd ${WRKSRC:Q};			\
	for cs in ${CONFIGURE_DIRS:=/config.status}; do			\
	  if ${TEST} ! -f "$${cs}"; then continue; fi;			\
	  ${PRINTF} "%s:\\n" "$${cs}";					\
	  ${SED} -n 's:^s,@\([^@]*\)\@,\(.*\),;t t$$:	\1=\2:p' "$${cs}" \
	  | ${SORT};							\
	done; fi
.else
	@${DO_NADA}
.endif

_show-dbginfo-config.h:
.if !empty(CONFIGURE_DIRS:M*)
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	if ${TEST} -d ${WRKSRC:Q}; then cd ${WRKSRC:Q};			\
	for cdir in ${CONFIGURE_DIRS}; do				\
	  ch="$${cdir}/config.h";					\
	  if ${TEST} ! -f "$${ch}"; then				\
	    cac="$${cdir}/configure.ac";				\
	    if ${TEST} ! -f "$${cac}"; then				\
	      cac="$${cdir}/configure.in";				\
	    fi;								\
	    if ${TEST} ! -f "$${cac}"; then				\
	      continue;							\
	    fi;								\
	    ch="$${cdir}/"`${SED} -n 's,.*AC_CONFIG_HEADERS(\[\([[:graph:]]*\)\]).*,\1,p' < "$${cac}"`; \
	    if ${TEST} ! -f "$${ch}"; then				\
	      continue;							\
	    fi;								\
	  fi;								\
	  ${PRINTF} "%s:\\n" "$${ch}";					\
	  ${AWK} '/^#define / { print "\t"$$0; } /^\/\* #undef / { print "\t" $$2 " " $$3; }' < "$${ch}"; \
	done; fi
.else
	@${DO_NADA}
.endif

_show-dbginfo-build:
	@${PRINTF} "BUILD_ENV (sorted alphabetically):\\n"
	@${PRINTF} "\\t%s\\n" ${BUILD_ENV:O}
	@${PRINTF} "BUILD_DIRS:\\n"
	@${PRINTF} "\\t%s\\n" ${BUILD_DIRS}
	@${PRINTF} "MAKE_ENV (sorted alphabetically):\\n"
	@${PRINTF} "\\t%s\\n" ${MAKE_ENV:O}
	@${PRINTF} "MAKE_PROGRAM:\\n\\t%s\\n" ${MAKE_PROGRAM:Q}
	@${PRINTF} "BUILD_MAKE_FLAGS (sorted alphabetically):\\n"
	@${PRINTF} "\\t%s\\n" ${BUILD_MAKE_FLAGS:O}

_show-dbginfo-install:
	@${PRINTF} "INSTALL_DIRS:\\n"
	@${PRINTF} "\\t%s\\n" ${INSTALL_DIRS}
	@${PRINTF} "INSTALL_MAKE_FLAGS (sorted alphabetically):\\n"
	@${PRINTF} "\\t%s\\n" ${INSTALL_MAKE_FLAGS:O}

_show-dbginfo-plist-subst:
	@${PRINTF} "PLIST_SUBST (sorted alphabetically):\\n"
	@${PRINTF} "\\t%s\\n" ${PLIST_SUBST:O}

#
# The build-env target.
#

.PHONY: build-env
build-env: configure
	@${STEP_MSG} "Entering the build environment for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH}
