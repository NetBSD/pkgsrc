# $NetBSD: bsd.buildlink2.mk,v 1.121 2004/03/29 05:42:58 jlam Exp $
#
# An example package buildlink2.mk file:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# BUILDLINK_PACKAGES+=		foo
# BUILDLINK_PKGBASE.foo=	foo-lib
# BUILDLINK_DEPENDS.foo?=	foo-lib>=1.0
# BUILDLINK_RECOMMENDED.foo?=	foo-lib>=1.0nb1
# BUILDLINK_PKGSRCDIR.foo?=	../../category/foo-lib
#
# EVAL_PREFIX+=			BUILDLINK_PREFIX.foo=foo-lib
# BUILDLINK_PREFIX.foo_DEFAULT=	${LOCALBASE}
# BUILDLINK_FILES.foo=		include/foo.h
# BUILDLINK_FILES.foo+=		include/bar.h
# BUILDLINK_FILES.foo+=		lib/libfoo.*
#
# # We want "-lbar" to eventually resolve to "-lfoo".
# BUILDLINK_TRANSFORM+=		l:bar:foo
#
# BUILDLINK_TARGETS+=		foo-buildlink
#
# foo-buildlink: _BUILDLINK_USE
# -------------8<-------------8<-------------8<-------------8<-------------
#
# Another example package buildlink2.mk file:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# BUILDLINK_PACKAGES+=		baz
# BUILDLINK_PKGBASE.baz=	baz-devel
# BUILDLINK_DEPENDS.baz?=	baz-devel>=1.0
# BUILDLINK_PKGSRCDIR.baz?=	../../category/baz-devel
#
# EVAL_PREFIX+=			BUILDLINK_PREFIX.foo=foo-lib
# BUILDLINK_PREFIX.baz_DEFAULT=	${LOCALBASE}
# BUILDLINK_FILES_CMD.baz= \
#	${BUILDLINK_PLIST_CMD.baz} | ${GREP} "^\(include\|lib\)"
#
# BUILDLINK_TARGETS+=		baz-buildlink
#
# baz-buildlink: _BUILDLINK_USE
# -------------8<-------------8<-------------8<-------------8<-------------
#
# The different variables that may be set in a buildlink2.mk file are
# described below.
#
# The variable name convention used in this Makefile are:
#
# BUILDLINK_*	public buildlink-related variables usable in other Makefiles
# _BLNK_*	private buildlink-related variables to this Makefile

ECHO_BUILDLINK_MSG?=	${TRUE}

BUILDLINK_DIR=		${WRKDIR}/.buildlink
BUILDLINK_X11_DIR=	${BUILDLINK_DIR:H}/.buildlink-x11
CONFIGURE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
MAKE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
CONFIGURE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"
MAKE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"
_BLNK_CPPFLAGS=		-I${LOCALBASE}/include
_BLNK_LDFLAGS=		-L${LOCALBASE}/lib
.if ${_USE_RPATH} == "yes"
_BLNK_LDFLAGS+=		-Wl,${_OPSYS_RPATH_NAME}${LOCALBASE}/lib
.endif
_BLNK_OPSYS=		${OPSYS}

BUILDLINK_SHELL?=	${SH}

# The configure process usually tests for outlandish or missing things
# that we don't want polluting the argument cache.
#
CONFIGURE_ENV+=		BUILDLINK_UPDATE_CACHE=no

# The caching code, which greatly speeds up the build process, doesn't
# work completely correctly on certain platforms.
#
_BLNK_PARTIAL_CACHE_ONLY=	Darwin-5.*-*

_BLNK_FULL_CACHING?=	YES
.for _pattern_ in ${_BLNK_PARTIAL_CACHE_ONLY}
.  if !empty(MACHINE_PLATFORM:M${_pattern_})
_BLNK_FULL_CACHING=	NO
.  endif
.endfor
.if !empty(_BLNK_FULL_CACHING:M[yY][eE][sS])
CONFIGURE_ENV+=		BUILDLINK_CACHE_ALL=yes
MAKE_ENV+=		BUILDLINK_CACHE_ALL=yes
.endif

.if defined(USE_X11)
USE_X11_LINKS?=		YES
.  if empty(USE_X11_LINKS:M[nN][oO])
BUILD_DEPENDS+=		x11-links>=0.23:../../pkgtools/x11-links
_BLNK_X11_DIR=		${LOCALBASE}/share/x11-links
.  endif
_BLNK_CPPFLAGS+=	-I${X11BASE}/include
_BLNK_LDFLAGS+=		-L${X11BASE}/lib
.if ${_USE_RPATH} == "yes"
_BLNK_LDFLAGS+=		-Wl,${_OPSYS_RPATH_NAME}${X11BASE}/lib
.endif
.endif

CONFIGURE_ENV+=		BUILDLINK_CPPFLAGS="${_BLNK_CPPFLAGS}"
MAKE_ENV+=		BUILDLINK_CPPFLAGS="${_BLNK_CPPFLAGS}"
CONFIGURE_ENV+=		BUILDLINK_LDFLAGS="${_BLNK_LDFLAGS}"
MAKE_ENV+=		BUILDLINK_LDFLAGS="${_BLNK_LDFLAGS}"

.for FLAG in ${_BLNK_CPPFLAGS}
.  if empty(CFLAGS:M${FLAG})
CFLAGS+=	${FLAG}
.  endif
.  if empty(CXXFLAGS:M${FLAG})
CXXFLAGS+=	${FLAG}
.  endif
.  if empty(CPPFLAGS:M${FLAG})
CPPFLAGS+=	${FLAG}
.  endif
.endfor
.for FLAG in ${_BLNK_LDFLAGS}
.  if empty(LDFLAGS:M${FLAG:C/:/\:/})
LDFLAGS+=	${FLAG}
.  endif
.endfor

# Prepend ${BUILDLINK_DIR}/bin to the PATH so that the wrappers are found
# first when searching for executables.
#
PREPEND_PATH+=	${BUILDLINK_DIR}/bin

_BLNK_PKGVAR?=		${PKGBASE:S/++$/xx/:S/+$//}

# Try to include buildlink2.mk files for any dependencies that are already
# installed on the system.  This tries to handle the situation where the
# installed package and the package as it exists in pkgsrc have differing
# lists of dependencies.  If the package directory has moved or been
# removed from pkgsrc, then set BUILDLINK_INSTALLED_PKGSRCDIR.<pkg> to the
# correct PKGPATH for that package or to the empty value if it has been
# removed.
#
.if !defined(_BLNK_INSTALLED_DEPDIRS.${_BLNK_PKGVAR})
_BLNK_INSTALLED_DEPS=	# empty
.  for _pkg_ in ${BUILDLINK_PACKAGES}
BUILDLINK_DEPMETHOD.${_pkg_}?=	full
.    if !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mfull)
BUILDLINK_PKGBASE.${_pkg_}?=	${_pkg_}
_BLNK_INSTALLED_DEPS.${_pkg_}!=						\
	pkg="${BUILDLINK_PKGBASE.${_pkg_}}-[0-9]*";			\
	found=`${PKG_BEST_EXISTS} "$$pkg"`;				\
	pkgdep=;							\
	if [ -n "$$found" ]; then					\
		pkgdep=`${PKG_INFO} -qf "$$found" | ${SED} -n "s/^@pkgdep[ 	]*//p"`; \
	fi;								\
	${ECHO} "$$pkgdep"
_BLNK_INSTALLED_DEPS+=	${_BLNK_INSTALLED_DEPS.${_pkg_}}
.    endif
.  endfor
_BLNK_INSTALLED_DEPPKGS=	# empty
.  for _dep_ in ${_BLNK_INSTALLED_DEPS}
_BLNK_TMP_PKGNAME!=	found=`${PKG_BEST_EXISTS} "${_dep_}"`; ${ECHO} "$$found"
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGNAME:C/-[^-]*$//}
#
# Map package names into buildlink package variable equivalents when it
# differs from the PKGBASE for that package.
#
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/++$/xx/:S/+$//}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/--$/mm/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/^PAM$/pam/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/^freetype-lib$/freetype/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/^gettext-lib$/gettext/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/^libaudiofile$/audiofile/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/^libgetopt$/getopt/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/^libiconv$/iconv/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:S/^libtool-base$/libtool/}
_BLNK_TMP_PKGVAR:=	${_BLNK_TMP_PKGVAR:C/^py[0-9][0-9][^-]*-/py-/}
_BLNK_INSTALLED_PKGNAME.${_BLNK_TMP_PKGVAR}:=	${_BLNK_TMP_PKGNAME}
_BLNK_INSTALLED_DEPPKGS:=						\
	${_BLNK_INSTALLED_DEPPKGS:N${_BLNK_TMP_PKGVAR}}			\
	${_BLNK_TMP_PKGVAR}
.    undef _BLNK_TMP
.    undef _BLNK_TMP_PKGVAR
.    undef _BLNK_TMP_PKGNAME
.  endfor
_BLNK_INSTALLED_DEPDIRS.${_BLNK_PKGVAR}=	# empty
.  for _pkg_ in ${_BLNK_INSTALLED_DEPPKGS}
#
# If BUILDLINK_PKGSRCDIR.<pkg> is already defined (by a previous inclusion
# of <pkg>'s buildlink2.mk file), then make that the default value for
# BUILDLINK_INSTALLED_PKGSRCDIR.<pkg>.  Otherwise, try to dig it out of
# the +BUILD_INFO file of the installed package.
#
.    if defined(BUILDLINK_PKGSRCDIR.${_pkg_})
BUILDLINK_INSTALLED_PKGSRCDIR.${_pkg_}?=	${BUILDLINK_PKGSRCDIR.${_pkg_}}
.    endif
.    if !defined(BUILDLINK_INSTALLED_PKGSRCDIR.${_pkg_})
BUILDLINK_INSTALLED_PKGSRCDIR.${_pkg_}!=				\
	dir=`${PKG_INFO} -qB "${_BLNK_INSTALLED_PKGNAME.${_pkg_}}" | ${SED} -n "s/^PKGPATH=//p"`; ${ECHO} "../../$$dir"
.    endif
.    if exists(${BUILDLINK_INSTALLED_PKGSRCDIR.${_pkg_}}/buildlink2.mk)
_BLNK_INSTALLED_DEPDIRS.${_BLNK_PKGVAR}+=				\
	${BUILDLINK_INSTALLED_PKGSRCDIR.${_pkg_}}
.    endif
.  endfor
.endif
.for _dir_ in ${_BLNK_INSTALLED_DEPDIRS.${_BLNK_PKGVAR}}
.  include "${_dir_}/buildlink2.mk"
.endfor

# Run through EVAL_PREFIX again in case we included any buildlink2.mk files
# above and need to set BUILDLINK_PREFIX.<pkg> appropriately.
#
.if defined(EVAL_PREFIX)
.  for def in ${EVAL_PREFIX}
.    if !defined(${def:C/=.*//}_DEFAULT)
${def:C/=.*//}_DEFAULT=	${X11PREFIX}
.    endif
.    if !defined(${def:C/=.*//})
_depend_${def:C/=.*//}!=						\
	${PKG_INFO} -e ${def:C/.*=//} 2>/dev/null; ${ECHO}
.      if empty(_depend_${def:C/=.*//})
${def:C/=.*//}=	${${def:C/=.*//}_DEFAULT}
.      else
_dir_${def:C/=.*//}!=							\
	(${PKG_INFO} -qp ${def:C/.*=//} 2>/dev/null) |			\
	${AWK} '{ print $$2; exit }'
${def:C/=.*//}=	${_dir_${def:C/=.*//}}
MAKEFLAGS+=	${def:C/=.*//}=${_dir_${def:C/=.*//}}
.      endif
.    endif
.  endfor
.endif

.for _pkg_ in ${BUILDLINK_PACKAGES}
#
# Add the proper dependency on each package pulled in by buildlink2.mk
# files.  BUILDLINK_DEPMETHOD.<pkg> contains a list of either "full" or
# "build", and if any of that list if "full" then we use a full dependency
# on <pkg>, otherwise we use a build dependency on <pkg>.  By default,
# we use a full dependency.
#
BUILDLINK_DEPMETHOD.${_pkg_}?=	full
.  if !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mfull)
_BUILDLINK_DEPMETHOD.${_pkg_}=	DEPENDS
_BUILDLINK_RECMETHOD.${_pkg_}=	RECOMMENDED
.  elif !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mbuild)
_BUILDLINK_DEPMETHOD.${_pkg_}=	BUILD_DEPENDS
.  endif
.  if defined(BUILDLINK_DEPENDS.${_pkg_}) && \
      defined(BUILDLINK_PKGSRCDIR.${_pkg_})
.    for _depends_ in ${BUILDLINK_DEPENDS.${_pkg_}}
${_BUILDLINK_DEPMETHOD.${_pkg_}}+= \
	${_depends_}:${BUILDLINK_PKGSRCDIR.${_pkg_}}
.    endfor
.  endif
.  if defined(BUILDLINK_RECOMMENDED.${_pkg_}) && \
      defined(_BUILDLINK_RECMETHOD.${_pkg_}) && \
      defined(BUILDLINK_PKGSRCDIR.${_pkg_})
.    for _rec_ in ${BUILDLINK_RECOMMENDED.${_pkg_}}
${_BUILDLINK_RECMETHOD.${_pkg_}}+= \
	${_rec_}:${BUILDLINK_PKGSRCDIR.${_pkg_}}
.    endfor
.  endif
#
# BUILDLINK_PLIST_CMD.<pkg> is a sequence of shell commands that extracts
# a list of all of the files installed by <pkg>.  This list is relative to
# ${BUILDLINK_PREFIX.<pkg>}.
#
BUILDLINK_PLIST_CMD.${_pkg_}= 						\
	${PKG_INFO} -f "${BUILDLINK_PKGBASE.${_pkg_}}-[0-9]*" |		\
		${SED} -n '/File:/s/^[ 	]*File:[ 	]*//p'
.endfor

# Create the buildlink include and lib directories so that the Darwin
# compiler/linker won't complain verbosely (on stdout, even!) when
# those directories are passed as sub-arguments of -I and -L.
#
do-buildlink: buildlink-directories
buildlink-directories:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}
.if defined(USE_X11)
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${BUILDLINK_X11_DIR}
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -sf ${BUILDLINK_DIR} ${BUILDLINK_X11_DIR}
.  if empty(USE_X11_LINKS:M[nN][oO])
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_BLNK_X11_DIR} && ${PAX} -rw . ${BUILDLINK_X11_DIR}
.  endif
.endif
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/include
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/lib

# Create the buildlink wrappers before any of the other buildlink targets
# are run, as the wrapper may need to be used in some of those targets.
#
do-buildlink: buildlink-wrappers buildlink-${_BLNK_OPSYS}-wrappers

# Add each of the *-buildlink targets as a prerequisite for the
# buildlink target.  This ensures that the symlinks are created
# before any configure scripts or build commands are called.
#
.for _target_ in ${BUILDLINK_PRE_TARGETS} ${BUILDLINK_TARGETS}
do-buildlink: ${_target_}
.endfor

# _LT_ARCHIVE_TRANSFORM creates $${dest} from $${file}, where $${file} is
# a libtool archive (*.la).  It allows libtool to properly interact with
# buildlink at link time by linking against the libraries pointed to by
# symlinks in ${BUILDLINK_DIR}.
#
_LT_ARCHIVE_TRANSFORM_SED=						\
	-e "s|$/usr\(/lib/[^ 	]*\.la\)|${BUILDLINK_DIR}\1|g"		\
	-e "s|${LOCALBASE}\(/lib/[^ 	]*\.la\)|${BUILDLINK_DIR}\1|g"	\
	-e "s|${X11BASE}\(/lib/[^ 	]*\.la\)|${BUILDLINK_DIR}\1|g"

_LT_ARCHIVE_TRANSFORM=							\
	${SED} ${_LT_ARCHIVE_TRANSFORM_SED} $${file} > $${dest}

# _BUILDLINK_USE is a macro target that symlinks package files into a new
# hierarchy under ${BUILDLINK_DIR}.
#
# The variables required to be defined to use this target are listed
# below.  <pkg> refers to the name of the package and should be used
# consistently.
#
# The target that uses this macro target should perform no other actions
# and be named "<pkg>-buildlink".
#
# BUILDLINK_PREFIX.<pkg>    installation prefix of the package:
#                           ${LOCALBASE} or ${X11PREFIX}
#
# BUILDLINK_FILES.<pkg>     files relative to ${BUILDLINK_PREFIX.<pkg>}
#                           to be symlinked into ${BUILDLINK_DIR}
#
# BUILDLINK_FILES_CMD.<pkg> shell pipeline that outputs to stdout a list
#                           of files relative to ${BUILDLINK_PREFIX.<pkg>};
#                           the shell variable $${pkg_prefix} may be used
#                           and is the subdirectory (ending in /) of
#                           ${BUILDLINK_PREFIX.<pkg>} to which the PLIST
#                           is relative, e.g. if `pkg_info -qp foo' returns
#                           "/usr/pkg/java/kaffe", then $${pkg_prefix} is
#                           "java/kaffe/".
#
# BUILDLINK_TARGETS         targets to be invoked during buildlink;
#                           the targets should be appended to this variable
#                           using +=
#
# The variables that may optionally be defined:
#
# BUILDLINK_TRANSFORM.<pkgname> sed arguments used to transform the name of
#                               the source filename into a destination
#                               filename
#
_BUILDLINK_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink//}_buildlink_done; \
	if [ ! -f $${cookie} ]; then					\
		${ECHO_BUILDLINK_MSG} "Linking ${.TARGET:S/-buildlink//} files into ${BUILDLINK_DIR}."; \
		${MKDIR} ${BUILDLINK_DIR};				\
		case "${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}" in	\
		${X11BASE})						\
			buildlink_dir="${BUILDLINK_X11_DIR}";		\
			;;						\
		*)							\
			buildlink_dir="${BUILDLINK_DIR}";		\
			;;						\
		esac;							\
		pkg_prefix=;						\
		if [ -n "${BUILDLINK_PKGBASE.${.TARGET:S/-buildlink//}}" ] && \
		   ${PKG_INFO} -qe "${BUILDLINK_PKGBASE.${.TARGET:S/-buildlink//}}-[0-9]*"; then \
			pkg_prefix=`${PKG_INFO} -qp "${BUILDLINK_PKGBASE.${.TARGET:S/-buildlink//}}-[0-9]*" | ${AWK} '{ sub("${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}", "", $$2); sub("/", "", $$2); print $$2; exit }'`/; \
		fi;							\
		rel_files_cmd=;						\
		if [ -n "${BUILDLINK_FILES_CMD.${.TARGET:S/-buildlink//}:Q}" ]; then \
			rel_files_cmd=`${BUILDLINK_FILES_CMD.${.TARGET:S/-buildlink//}}`; \
		fi;							\
		cd ${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}};	\
		rel_files="${BUILDLINK_FILES.${.TARGET:S/-buildlink//}}"; \
		for rel_file in $${rel_files_cmd} $${rel_files}; do	\
			file="${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}/$${rel_file}"; \
			if [ -z "${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}:Q}" ]; then \
				dest="$${buildlink_dir}/$${rel_file}";	\
			else						\
				dest=`${ECHO} $${buildlink_dir}/$${rel_file} | ${SED} ${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}}`; \
			fi;						\
			if [ -f $${file} ]; then			\
				dir=`${DIRNAME} $${dest}`;		\
				if [ ! -d $${dir} ]; then		\
					${MKDIR} $${dir};		\
				fi;					\
				${RM} -f $${dest};			\
				case $${file} in			\
				*.la)					\
					${_LT_ARCHIVE_TRANSFORM};	\
					;;				\
				*)					\
					${LN} -sf $${file} $${dest};	\
					;;				\
				esac;					\
				if [ -z "${BUILDLINK_TRANSFORM.${.TARGET:S/-buildlink//}:Q}" ]; then \
					${ECHO} $${file} >> $${cookie};	\
				else					\
					${ECHO} "$${file} -> $${dest}" >> $${cookie}; \
				fi;					\
			else						\
				${ECHO} "$${file}: not found" >> $${cookie}; \
			fi;						\
		done;							\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

# Create _BLNK_PROTECT and _BLNK_UNPROTECT variables to protect key
# directories from any argument filtering, as they may be subdirectories
# of ${LOCALBASE}, /usr/pkg, or /usr/local.
#
_BLNK_PROTECT=		# empty
_BLNK_UNPROTECT=	# empty
_BLNK_PROTECT_DIRS=	# empty
_BLNK_UNPROTECT_DIRS=	# empty

_BLNK_MANGLE_DIR.BUILDLINK_X11_DIR=	_bUiLdLiNk_x11_dIr_
_BLNK_MANGLE_DIR.BUILDLINK_DIR=		_bUiLdLiNk_dIr_
_BLNK_MANGLE_DIR.ZOULARISBASE=		_zOuLaRiSbAsE_
_BLNK_MANGLE_DIR.WRKDIR=		_wRkDiR_

_BLNK_PROTECT_DIRS+=	BUILDLINK_X11_DIR
_BLNK_PROTECT_DIRS+=	BUILDLINK_DIR
.if defined(ZOULARISBASE) && (${ZOULARISBASE} != ${LOCALBASE})
_BLNK_PROTECT_DIRS+=	ZOULARISBASE
.endif
_BLNK_PROTECT_DIRS+=	WRKDIR
_BLNK_UNPROTECT_DIRS+=	WRKDIR
.if defined(ZOULARISBASE) && (${ZOULARISBASE} != ${LOCALBASE})
_BLNK_UNPROTECT_DIRS+=	ZOULARISBASE
.endif
_BLNK_UNPROTECT_DIRS+=	BUILDLINK_DIR
_BLNK_UNPROTECT_DIRS+=	BUILDLINK_X11_DIR

.for _dir_ in ${_BLNK_PROTECT_DIRS}
_BLNK_PROTECT+=		s:${${_dir_}}:${_BLNK_MANGLE_DIR.${_dir_}}
.endfor
.for _dir_ in ${_BLNK_UNPROTECT_DIRS}
_BLNK_UNPROTECT+=	s:${_BLNK_MANGLE_DIR.${_dir_}}:${${_dir_}}
.endfor

_BLNK_TRANSFORM+=	${_BLNK_PROTECT}
#
# Change references to ${DEPOTBASE}/<pkg> into ${LOCALBASE} so that
# "overwrite" packages think headers and libraries for "pkgviews" packages
# are just found in the default view.
#
_BLNK_TRANSFORM+=	depot:${DEPOTBASE}:${LOCALBASE}
#
# Convert direct paths to shared libraries into "-Ldir -llib" equivalents.
#
_BLNK_TRANSFORM+=	p:${X11BASE}
_BLNK_TRANSFORM+=	p:${LOCALBASE}
_BLNK_TRANSFORM+=	p:/usr/lib
#
# Convert direct paths to static libraries in ${LOCALBASE} or ${X11BASE}
# into references into ${BUILDLINK_DIR}.
#
_BLNK_TRANSFORM+=	static:${X11BASE}:${_BLNK_MANGLE_DIR.BUILDLINK_X11_DIR}
_BLNK_TRANSFORM+=	static:${LOCALBASE}:${_BLNK_MANGLE_DIR.BUILDLINK_DIR}
#
# Transform references into ${X11BASE} into ${BUILDLINK_X11_DIR} but if
# the package doesn't use X11, then just remove these references altogether.
#
.if defined(USE_X11)
_BLNK_TRANSFORM+=	I:${X11BASE}:${_BLNK_MANGLE_DIR.BUILDLINK_X11_DIR}
_BLNK_TRANSFORM+=	L:${X11BASE}:${_BLNK_MANGLE_DIR.BUILDLINK_X11_DIR}
.else
_BLNK_TRANSFORM+=	r:${X11BASE}
.endif
#
# Transform references into ${LOCALBASE} into ${BUILDLINK_DIR}.
#
_BLNK_TRANSFORM+=	${BUILDLINK_TRANSFORM}
_BLNK_TRANSFORM+=	I:${LOCALBASE}:${_BLNK_MANGLE_DIR.BUILDLINK_DIR}
_BLNK_TRANSFORM+=	L:${LOCALBASE}:${_BLNK_MANGLE_DIR.BUILDLINK_DIR}
.for _localbase_ in /usr/pkg /usr/local
.  if ${LOCALBASE} != ${_localbase_}
_BLNK_TRANSFORM+=	r:${_localbase_}
.  endif
.endfor
#
# Explicitly remove "-I/usr/include" and "-L/usr/lib" as they're redundant.
#
_BLNK_TRANSFORM+=	S:-I/usr/include:
_BLNK_TRANSFORM+=	S:-L/usr/lib:
#
# Remove -Wl,-R* and *-rpath* if _USE_RPATH != "yes"
# Transform -Wl,-R* and *-rpath* if Sun compilers are used.
#
.if defined(_USE_RPATH) && empty(_USE_RPATH:M[yY][eE][sS])
_BLNK_TRANSFORM+=	no-rpath
.elif !empty(PKGSRC_COMPILER:Msunpro)
_BLNK_TRANSFORM+=	sanitize-rpath
.endif
_BLNK_TRANSFORM+=	${_BLNK_UNPROTECT}

_BLNK_TRANSFORM_SED+=	-f ${_BLNK_TRANSFORM_SEDFILE}
_BLNK_UNTRANSFORM_SED+=	-f ${_BLNK_UNTRANSFORM_SEDFILE}

REPLACE_BUILDLINK_PATTERNS?=	# empty
_REPLACE_BUILDLINK_PATTERNS=	${REPLACE_BUILDLINK_PATTERNS}
_REPLACE_BUILDLINK_PATTERNS+=	*-config
_REPLACE_BUILDLINK_PATTERNS+=	*Conf.sh
_REPLACE_BUILDLINK_PATTERNS+=	*.pc
_REPLACE_BUILDLINK_PATTERNS_FIND= \
	\( ${_REPLACE_BUILDLINK_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)

REPLACE_BUILDLINK?=		# empty
_REPLACE_BUILDLINK= \
	${REPLACE_BUILDLINK}						\
	`${FIND} . ${_REPLACE_BUILDLINK_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT} -u`

# When "unbuildlinkifying" a file, we must remove references to the
# buildlink directories and change any -llib to the proper replacement
# libraries (-lreadline -> -ledit, etc.).  Redundant -Idir and -Ldir
# options are removed to optimize the resulting file.  Also, prefer the
# .la files in ${LOCALBASE}/lib over the ones in ${DEPOTBASE}/*/lib when
# creating new .la files.  This makes "overwrite" packages look and feel
# more like they would without the pkgviews integration.
#
LIBTOOL_ARCHIVE_UNTRANSFORM_SED?=	# empty
_LIBTOOL_ARCHIVE_UNTRANSFORM_SED+=	${LIBTOOL_ARCHIVE_UNTRANSFORM_SED}
REPLACE_BUILDLINK_SED?=			# empty
_REPLACE_BUILDLINK_SED=			${REPLACE_BUILDLINK_SED}
_REPLACE_BUILDLINK_SED+=		${_LIBTOOL_ARCHIVE_UNTRANSFORM_SED}

SUBST_CLASSES+=			unbuildlink
SUBST_STAGE.unbuildlink=	post-build
SUBST_MESSAGE.unbuildlink=	\
	"Fixing buildlink references in files-to-be-installed."
SUBST_FILES.unbuildlink=	${_REPLACE_BUILDLINK}
SUBST_SED.unbuildlink=		${_REPLACE_BUILDLINK_SED}
SUBST_SED.unbuildlink+=		${_BLNK_UNTRANSFORM_SED}

.if !defined(USE_LIBTOOL)
BUILDLINK_FAKE_LA=	${TRUE}
.else
#
# Create a fake libtool archive $$lafile that uses the shared libraries
# named in $$libpattern.
#
BUILDLINK_FAKE_LA=							\
	if [ ! -f $$lafile ]; then					\
		case ${OBJECT_FMT} in					\
		Mach-O) _lib=`${LS} -1 $$libpattern 2>/dev/null | ${HEAD} -1` ;; \
		*)      _lib=`${LS} -1r $$libpattern 2>/dev/null | ${HEAD} -1` ;; \
		esac;							\
		if [ -n "$$_lib" ]; then				\
			${ECHO_BUILDLINK_MSG} "Creating libtool archive: $$lafile"; \
			${_BLNK_FAKE_LA} $$_lib > $$lafile;		\
		fi;							\
	fi
.endif

# Generate wrapper scripts for the compiler tools that sanitize the
# argument list by converting references to ${LOCALBASE} and ${X11BASE}
# into references to ${BUILDLINK_DIR} and ${BUILDLINK_X11_DIR}. These
# wrapper scripts are to be used instead of the actual compiler tools when
# building software.
#
# BUILDLINK_CC, BUILDLINK_LD, etc. are the full paths to the wrapper
#	scripts.
#
# ALIASES.CC, ALIASES.LD, etc. are the other names by which each wrapper
#	may be invoked.
#
_BLNK_WRAPPEES+=	AS
_BLNK_WRAPPEES+=	CC
_BLNK_WRAPPEES+=	CPP
_BLNK_WRAPPEES+=	CXX
_BLNK_WRAPPEES+=	LD
_BLNK_WRAPPEES+=	FC
_BLNK_WRAPPEES+=	LIBTOOL SHLIBTOOL
.if defined(USE_LIBTOOL)
_LIBTOOL=		${BUILDLINK_LIBTOOL}
_SHLIBTOOL=		${BUILDLINK_SHLIBTOOL}
.endif
.if defined(USE_X11)
IMAKE?=			${X11BASE}/bin/imake
_BLNK_WRAPPEES+=	IMAKE
.endif
_ALIASES.AS=		as
_ALIASES.CC=		cc gcc
_ALIASES.CXX=		c++ g++ CC
_ALIASES.CPP=		cpp
_ALIASES.FC=		f77 g77
_ALIASES.LD=		ld

# _BLNK_WRAP_*.<wrappee> variables represent "template methods" of the

# wrapper script that may be customized per wrapper:
#
# _BLNK_WRAP_{*CACHE*,*LOGIC*}.<wrappee> are parts of the wrapper script
#	system as described in pkgsrc/mk/buildlink2/README.  The files not
#	ending in "-trans" represent pieces of the wrapper script that may
#	be used to form a wrapper that doesn't translate its arguments,
#	and conversely for the files ending in "-trans".  By default, all
#	wrappers use the "-trans" scripts.
#
# _BLNK_WRAP_ENV.<wrappee> consists of shell commands to export a shell
#	environment for the wrappee.
#
# _BLNK_WRAP_SANITIZE_PATH.<wrappee> sets the PATH for calling executables
#	from within the wrapper.  By default, it removes the buildlink
#	directory from the PATH so that sub-invocations of compiler tools
#	will use the wrappees instead of the wrappers.
#
_BLNK_SANITIZED_PATH!=	${ECHO} ${PATH} | ${SED}			\
	-e "s|:${BUILDLINK_DIR}[^:]*||" -e "s|${BUILDLINK_DIR}[^:]*:||"
_BLNK_WRAP_SANITIZE_PATH=	PATH="${_BLNK_SANITIZED_PATH}"
_BLNK_EMPTY_FILE?=		${BUILDLINK_DIR}/bin/.empty
_BLNK_WRAP_ENV?=		${BUILDLINK_WRAPPER_ENV}
_BLNK_WRAP_PRIVATE_PRE_CACHE=	${BUILDLINK_DIR}/bin/.private-pre-cache
_BLNK_WRAP_PRE_CACHE=		${BUILDLINK_DIR}/bin/.pre-cache
_BLNK_WRAP_CACHE_ADD=		${BUILDLINK_DIR}/bin/.cache-add
_BLNK_WRAP_CACHE=		${BUILDLINK_DIR}/bin/.cache
_BLNK_WRAP_CACHE_ADD_TRANSFORM=	${BUILDLINK_DIR}/bin/.cache-add-trans
_BLNK_WRAP_CACHE_TRANSFORM=	${BUILDLINK_DIR}/bin/.cache-trans
_BLNK_WRAP_POST_CACHE=		${BUILDLINK_DIR}/bin/.post-cache
_BLNK_WRAP_LOGIC=		${BUILDLINK_DIR}/bin/.logic
_BLNK_WRAP_LOGIC_TRANSFORM=	${BUILDLINK_DIR}/bin/.logic-trans
_BLNK_WRAP_LOG=			${WRKLOG}
_BLNK_LIBTOOL_DO_INSTALL=	${BUILDLINK_DIR}/bin/.libtool-do-install
_BLNK_LIBTOOL_FIX_LA=		${BUILDLINK_DIR}/bin/.libtool-fix-la
_BLNK_FAKE_LA=			${BUILDLINK_DIR}/bin/.fake-la
_BLNK_GEN_TRANSFORM=		${BUILDLINK_DIR}/bin/.gen-transform
_BLNK_TRANSFORM_SEDFILE=	${BUILDLINK_DIR}/bin/.transform.sed
_BLNK_UNTRANSFORM_SEDFILE=	${BUILDLINK_DIR}/bin/.untransform.sed

.for _wrappee_ in ${_BLNK_WRAPPEES}
#
# _BLNK_WRAPPER_SH.<wrappee> points to the main wrapper script used to
#	generate the wrapper for the wrappee.
#
_BLNK_WRAPPER_SH.${_wrappee_}=	${.CURDIR}/../../mk/buildlink2/wrapper.sh
_BLNK_WRAP_SANITIZE_PATH.${_wrappee_}=		${_BLNK_WRAP_SANITIZE_PATH}
_BLNK_WRAP_ENV.${_wrappee_}=			${_BLNK_WRAP_ENV}
_BLNK_WRAP_PRIVATE_PRE_CACHE.${_wrappee_}=	${_BLNK_EMPTY_FILE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}=	${_BLNK_EMPTY_FILE}
_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}=		${_BLNK_EMPTY_FILE}
_BLNK_WRAP_PRIVATE_POST_CACHE.${_wrappee_}=	${_BLNK_EMPTY_FILE}
_BLNK_WRAP_CACHE_ADD.${_wrappee_}=		${_BLNK_WRAP_CACHE_ADD_TRANSFORM}
_BLNK_WRAP_CACHE.${_wrappee_}=			${_BLNK_WRAP_CACHE_TRANSFORM}
_BLNK_WRAP_LOGIC.${_wrappee_}=			${_BLNK_WRAP_LOGIC_TRANSFORM}
_BLNK_WRAP_POST_LOGIC.${_wrappee_}=		${_BLNK_EMPTY_FILE}
.endfor

# Don't sanitize the PATH because we want libtool to invoke the wrapper
# scripts, too.
#
_BLNK_WRAPPER_SH.LIBTOOL=	${.CURDIR}/../../mk/buildlink2/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.LIBTOOL=	# empty
#
_BLNK_WRAPPER_SH.SHLIBTOOL=	${.CURDIR}/../../mk/buildlink2/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.SHLIBTOOL=	# empty

# We need to "unbuildlinkify" any libtool archives.
_BLNK_WRAP_LT_UNTRANSFORM_SED=		${_REPLACE_BUILDLINK_SED}

_BLNK_WRAP_PRIVATE_PRE_CACHE.LD=	${_BLNK_WRAP_PRIVATE_PRE_CACHE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.LD=	${BUILDLINK_DIR}/bin/.ld-cache-add
_BLNK_WRAP_PRIVATE_CACHE.LD=		${BUILDLINK_DIR}/bin/.ld-cache
_BLNK_WRAP_PRIVATE_POST_CACHE.LD=	${BUILDLINK_DIR}/bin/.ld-post-cache
_BLNK_WRAP_POST_LOGIC.LD=		${BUILDLINK_DIR}/bin/.ld-logic

_BLNK_WRAP_PRIVATE_PRE_CACHE.LIBTOOL=	${_BLNK_WRAP_PRIVATE_PRE_CACHE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.LIBTOOL=	${BUILDLINK_DIR}/bin/.libtool-cache-add
_BLNK_WRAP_PRIVATE_CACHE.LIBTOOL=	${BUILDLINK_DIR}/bin/.libtool-cache
_BLNK_WRAP_PRIVATE_POST_CACHE.LIBTOOL=	${BUILDLINK_DIR}/bin/.libtool-post-cache
_BLNK_WRAP_POST_LOGIC.LIBTOOL=		${BUILDLINK_DIR}/bin/.libtool-logic

# shlibtool shares cache information with libtool.
_BLNK_WRAP_PRIVATE_PRE_CACHE.SHLIBTOOL=	${_BLNK_WRAP_PRIVATE_PRE_CACHE.LIBTOOL}
_BLNK_WRAP_PRIVATE_CACHE_ADD.SHLIBTOOL=	${_BLNK_WRAP_PRIVATE_CACHE_ADD.LIBTOOL}
_BLNK_WRAP_PRIVATE_CACHE.SHLIBTOOL=	${_BLNK_WRAP_PRIVATE_CACHE.LIBTOOL}
_BLNK_WRAP_PRIVATE_POST_CACHE.SHLIBTOOL= ${_BLNK_WRAP_PRIVATE_POST_CACHE.LIBTOOL}
_BLNK_WRAP_POST_LOGIC.SHLIBTOOL=	${_BLNK_WRAP_POST_LOGIC.LIBTOOL}

# Don't transform the arguments for imake, which uses the C preprocessor
# to generate Makefiles, so that imake will find its config files.
#
.if defined(USE_X11)
_BLNK_WRAP_CACHE_ADD.IMAKE=	${_BLNK_WRAP_CACHE_ADD}
_BLNK_WRAP_CACHE.IMAKE=		${_BLNK_WRAP_CACHE}
_BLNK_WRAP_LOGIC.IMAKE=		${_BLNK_WRAP_LOGIC}
.endif

buildlink-wrappers: ${_BLNK_LIBTOOL_DO_INSTALL}
buildlink-wrappers: ${_BLNK_LIBTOOL_FIX_LA}
buildlink-wrappers: ${_BLNK_FAKE_LA}

.for _wrappee_ in ${_BLNK_WRAPPEES}
.  if defined(PKG_${_wrappee_})
_BLNK_PKG_${_wrappee_}=	${PKG_${_wrappee_}}
.  else
_BLNK_PKG_${_wrappee_}=	${${_wrappee_}}
.  endif

BUILDLINK_${_wrappee_}=	\
	${BUILDLINK_DIR}/bin/${_BLNK_PKG_${_wrappee_}:T:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
${_wrappee_}:=	${BUILDLINK_${_wrappee_}:T}

_BLNK_WRAPPER_TRANSFORM_SED.${_wrappee_}=				\
	-e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"			\
	-e "s|@BUILDLINK_X11_DIR@|${BUILDLINK_X11_DIR}|g"		\
	-e "s|@BUILDLINK_SHELL@|${BUILDLINK_SHELL}|g"			\
	-e "s|@WRKDIR@|${WRKDIR}|g"					\
	-e "s|@WRKSRC@|${WRKSRC}|g"					\
	-e "s|@CAT@|${CAT:Q}|g"						\
	-e "s|@ECHO@|${ECHO:Q}|g"					\
	-e "s|@SED@|${SED:Q}|g"						\
	-e "s|@TEST@|${TEST:Q}|g"					\
	-e "s|@TOUCH@|${TOUCH:Q}|g"					\
	-e "s|@_BLNK_LIBTOOL_DO_INSTALL@|${_BLNK_LIBTOOL_DO_INSTALL:Q}|g" \
	-e "s|@_BLNK_LIBTOOL_FIX_LA@|${_BLNK_LIBTOOL_FIX_LA:Q}|g"	\
	-e "s|@_BLNK_WRAP_LOG@|${_BLNK_WRAP_LOG:Q}|g"			\
	-e "s|@_BLNK_WRAP_PRIVATE_PRE_CACHE@|${_BLNK_WRAP_PRIVATE_PRE_CACHE.${_wrappee_}:Q}|g" \
	-e "s|@_BLNK_WRAP_PRIVATE_CACHE_ADD@|${_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}:Q}|g" \
	-e "s|@_BLNK_WRAP_PRIVATE_CACHE@|${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}:Q}|g" \
	-e "s|@_BLNK_WRAP_PRIVATE_POST_CACHE@|${_BLNK_WRAP_PRIVATE_POST_CACHE.${_wrappee_}:Q}|g" \
	-e "s|@_BLNK_WRAP_PRE_CACHE@|${_BLNK_WRAP_PRE_CACHE:Q}|g"	\
	-e "s|@_BLNK_WRAP_CACHE_ADD@|${_BLNK_WRAP_CACHE_ADD.${_wrappee_}:Q}|g" \
	-e "s|@_BLNK_WRAP_CACHE@|${_BLNK_WRAP_CACHE.${_wrappee_}:Q}|g"	\
	-e "s|@_BLNK_WRAP_POST_CACHE@|${_BLNK_WRAP_POST_CACHE:Q}|g"	\
	-e "s|@_BLNK_WRAP_LOGIC@|${_BLNK_WRAP_LOGIC.${_wrappee_}:Q}|g"	\
	-e "s|@_BLNK_WRAP_POST_LOGIC@|${_BLNK_WRAP_POST_LOGIC.${_wrappee_}:Q}|g" \
	-e "s|@_BLNK_WRAP_ENV@|${_BLNK_WRAP_ENV.${_wrappee_}:Q}|g"	\
	-e "s|@_BLNK_WRAP_SANITIZE_PATH@|${_BLNK_WRAP_SANITIZE_PATH.${_wrappee_}:Q}|g"

_BLNK_WRAPPEE_COOKIE.${_wrappee_}=	\
	${BUILDLINK_DIR}/.buildlink_wrapper_${_wrappee_}_done

buildlink-wrappers: ${_BLNK_WRAPPEE_COOKIE.${_wrappee_}}
${_BLNK_WRAPPEE_COOKIE.${_wrappee_}}:					\
		${_BLNK_WRAPPER_SH.${_wrappee_}}			\
		${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}}		\
		${_BLNK_WRAP_CACHE.${_wrappee_}}			\
		${_BLNK_WRAP_LOGIC.${_wrappee_}}			\
		${_BLNK_WRAP_POST_LOGIC.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"Creating wrapper: ${BUILDLINK_${_wrappee_}}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	wrappee="${_BLNK_PKG_${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}"; \
	gen=yes;							\
	case $${wrappee} in						\
	/*)	absdir=;						\
		;;							\
	*)	OLDIFS="$$IFS";						\
		IFS=":";						\
		for dir in $${PATH}; do					\
			case $${dir} in					\
			*${BUILDLINK_DIR}*)				\
				;;					\
			*)	if [ -f $${dir}/$${wrappee} ] ||	\
				   [ -h $${dir}/$${wrappee} ] &&	\
				   [ -x $${dir}/$${wrappee} ]; then	\
					absdir=$${dir}/;		\
					wrappee=$${absdir}$${wrappee};	\
					break;				\
				fi;					\
				;;					\
			esac;						\
		done;							\
		IFS="$$OLDIFS";						\
		if [ ! -x "$${wrappee}" ]; then				\
			gen=no;						\
			${ECHO_BUILDLINK_MSG} "Warning: unable to create \"$${wrappee}\" wrapper script"; \
		fi;							\
		;;							\
	esac;								\
	case $$gen in							\
	yes)								\
		${MKDIR} ${BUILDLINK_${_wrappee_}:H};			\
		${CAT} ${_BLNK_WRAPPER_SH.${_wrappee_}}	|		\
		${SED}	${_BLNK_WRAPPER_TRANSFORM_SED.${_wrappee_}}	\
			-e "s|@WRAPPEE@|$${absdir}${_BLNK_PKG_${_wrappee_}:Q}|g" \
			> ${BUILDLINK_${_wrappee_}};			\
		${CHMOD} +x ${BUILDLINK_${_wrappee_}};			\
		;;							\
	esac
.  for _alias_ in ${_ALIASES.${_wrappee_}:S/^/${BUILDLINK_DIR}\/bin\//}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -x ${_alias_} -a -x ${BUILDLINK_${_wrappee_}} ]; then	\
		${ECHO_BUILDLINK_MSG} "Linking wrapper: ${_alias_}";	\
		${LN} -f ${BUILDLINK_${_wrappee_}} ${_alias_};		\
	fi
.  endfor
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.endfor   # _wrappee_

# Allow BUILDLINK_ENV to override shell environment settings in
# ${CONFIGURE_ENV} and in ${MAKE_ENV} for the configure and build processes,
# respectively.
#
CONFIGURE_ENV+=	${BUILDLINK_ENV}
MAKE_ENV+=	${BUILDLINK_ENV}

# OS-specific overrides for buildlink2 wrappers
#
.if !empty(PKGSRC_COMPILER:Msunpro)
_BLNK_WRAPPEES.SunOS?=	CC CXX
CC.SunOS?=		${CC}
CXX.SunOS?=		${CXX}
.endif

buildlink-${_BLNK_OPSYS}-wrappers: buildlink-wrappers
.for _wrappee_ in ${_BLNK_WRAPPEES.${_BLNK_OPSYS}}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -x "${${_wrappee_}.${_BLNK_OPSYS}}" ]; then		\
		wrapper="${BUILDLINK_DIR}/bin/${${_wrappee_}.${_BLNK_OPSYS}:T}"; \
		${ECHO_BUILDLINK_MSG}					\
			"Creating ${_BLNK_OPSYS} wrapper: $${wrapper}";	\
		${RM} -f $${wrapper};					\
		${CAT} ${_BLNK_WRAPPER_SH.${_wrappee_}} |		\
		${SED}	${_BLNK_WRAPPER_TRANSFORM_SED.${_wrappee_}}	\
			-e "s|@WRAPPEE@|${${_wrappee_}.${_BLNK_OPSYS}}|g" \
		> $${wrapper};						\
		${CHMOD} +x $${wrapper};				\
		for file in ${_ALIASES.${_wrappee_}:S/^/${BUILDLINK_DIR}\/bin\//}; do \
			if [ "$${file}" != "$${wrappee}" ]; then	\
				${TOUCH} $${file};			\
			fi;						\
		done;							\
	fi
.endfor

${_BLNK_EMPTY_FILE}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}

${_BLNK_WRAP_PRIVATE_PRE_CACHE}:					\
		${.CURDIR}/../../mk/buildlink2/private-pre-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

.for _wrappee_ in ${_BLNK_WRAPPEES}
.  if !target(${_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}})
${_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif
.  if !target(${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}})
${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}}:				\
		${_BLNK_WRAP_PRIVATE_PRE_CACHE.${_wrappee_}}		\
		${_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}}		\
		${_BLNK_WRAP_PRIVATE_POST_CACHE.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
.  endif
.endfor

${_BLNK_WRAP_PRIVATE_POST_CACHE.LD}:					\
		${.CURDIR}/../../mk/buildlink2/ld-post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

${_BLNK_WRAP_PRIVATE_POST_CACHE.LIBTOOL}:				\
		${.CURDIR}/../../mk/buildlink2/libtool-post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

${_BLNK_WRAP_PRE_CACHE}: ${.CURDIR}/../../mk/buildlink2/pre-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

${_BLNK_WRAP_CACHE_ADD}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}

${_BLNK_WRAP_CACHE}:							\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_CACHE_ADD}					\
		${_BLNK_WRAP_POST_CACHE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_CACHE_ADD_TRANSFORM}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}

${_BLNK_WRAP_CACHE_TRANSFORM}:						\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_CACHE_ADD_TRANSFORM}			\
		${_BLNK_WRAP_POST_CACHE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_POST_CACHE}: ${.CURDIR}/../../mk/buildlink2/post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

${_BLNK_WRAP_LOGIC}: ${.CURDIR}/../../mk/buildlink2/logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e 's|@_BLNK_TRANSFORM_SED@||g'				\
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_LOGIC_TRANSFORM}:						\
		${.CURDIR}/../../mk/buildlink2/logic			\
		${_BLNK_TRANSFORM_SEDFILE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e 's|@_BLNK_TRANSFORM_SED@|${_BLNK_TRANSFORM_SED:Q}|g'	\
		${.CURDIR}/../../mk/buildlink2/logic > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_POST_LOGIC.LD}: ${.CURDIR}/../../mk/buildlink2/ld-logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

${_BLNK_WRAP_POST_LOGIC.LIBTOOL}: ${.CURDIR}/../../mk/buildlink2/libtool-logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

${_BLNK_LIBTOOL_DO_INSTALL}: ${.CURDIR}/../../mk/buildlink2/libtool-do-install
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -f ${.ALLSRC} ${.TARGET}

${_BLNK_LIBTOOL_FIX_LA}:						\
		${.CURDIR}/../../mk/buildlink2/libtool-fix-la		\
		${_BLNK_UNTRANSFORM_SEDFILE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@WRKSRC@|${WRKSRC}|g"				\
		-e "s|@BASENAME@|${BASENAME:Q}|g"			\
		-e "s|@CP@|${CP:Q}|g"					\
		-e "s|@DIRNAME@|${DIRNAME:Q}|g"				\
		-e "s|@EGREP@|${EGREP:Q}|g"				\
		-e "s|@MV@|${MV:Q}|g"					\
		-e "s|@RM@|${RM:Q}|g"					\
		-e "s|@SED@|${SED:Q}|g"					\
		-e "s|@TOUCH@|${TOUCH:Q}|g"				\
		-e 's|@_BLNK_WRAP_LT_UNTRANSFORM_SED@|${_BLNK_WRAP_LT_UNTRANSFORM_SED:Q}|g' \
		-e 's|@_BLNK_UNTRANSFORM_SED@|${_BLNK_UNTRANSFORM_SED:Q}|g' \
		${.CURDIR}/../../mk/buildlink2/libtool-fix-la > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

.if ${OBJECT_FMT} == "a.out"
_RESET_LD_SO_CACHE?=	${LDCONFIG}
.else
_RESET_LD_SO_CACHE?=	${TRUE}
.endif

${_BLNK_FAKE_LA}: ${.CURDIR}/../../mk/buildlink2/fake-la
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"		\
		-e "s|@BUILDLINK_X11_DIR@|${BUILDLINK_X11_DIR}|g"	\
		-e "s|@BUILDLINK_SHELL@|${BUILDLINK_SHELL}|g"		\
		-e "s|@AR@|${AR:Q}|g"					\
		-e "s|@AWK@|${AWK:Q}|g"					\
		-e "s|@BASENAME@|${BASENAME:Q}|g"			\
		-e "s|@CC@|${BUILDLINK_CC:Q}|g"				\
		-e "s|@LDFLAGS@|${LDFLAGS:N-l*:Q}|g"			\
		-e "s|@CP@|${CP:Q}|g"					\
		-e "s|@DIRNAME@|${DIRNAME:Q}|g"				\
		-e "s|@ECHO@|${ECHO:Q}|g"				\
		-e "s|@EGREP@|${EGREP:Q}|g"				\
		-e "s|@RESET_LD_SO_CACHE@|${_RESET_LD_SO_CACHE:Q}|g"	\
		-e "s|@LIBTOOL@|${BUILDLINK_LIBTOOL:Q}|g"		\
		-e "s|@MKDIR@|${MKDIR:Q}|g"				\
		-e "s|@MV@|${MV:Q}|g"					\
		-e "s|@PATH@|${PATH:Q}|g"				\
		-e "s|@RM@|${RM:Q}|g"					\
		-e "s|@SED@|${SED:Q}|g"					\
		-e "s|@TEST@|${TEST:Q}|g"				\
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_GEN_TRANSFORM}: ${.CURDIR}/../../mk/buildlink2/gen-transform.sh
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@_BLNK_TRANSFORM_SEDFILE@|${_BLNK_TRANSFORM_SEDFILE:Q}|g" \
		-e "s|@_BLNK_UNTRANSFORM_SEDFILE@|${_BLNK_UNTRANSFORM_SEDFILE:Q}|g" \
		-e "s|@_COMPILER_LD_FLAG@|${_COMPILER_LD_FLAG:Q}|g"	\
		-e "s|@_OPSYS_RPATH_NAME@|${_OPSYS_RPATH_NAME:Q}|g"	\
		-e "s|@BUILDLINK_SHELL@|${BUILDLINK_SHELL:Q}|g"		\
		-e "s|@CAT@|${CAT:Q}|g"					\
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_TRANSFORM_SEDFILE} ${_BLNK_UNTRANSFORM_SEDFILE}: ${_BLNK_GEN_TRANSFORM}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${_BLNK_GEN_TRANSFORM}		\
		${_BLNK_TRANSFORM}

_BLNK_CHECK_PATTERNS+=	-e "-I${LOCALBASE}/[a-rt-z]"
_BLNK_CHECK_PATTERNS+=	-e "-L${LOCALBASE}/[a-rt-z]"
_BLNK_CHECK_PATTERNS+=	-e "-I${X11BASE}/"
_BLNK_CHECK_PATTERNS+=	-e "-L${X11BASE}/"

buildlink-check:
	@if [ -f ${_BLNK_WRAP_LOG} ]; then				\
		${GREP} ${_BLNK_CHECK_PATTERNS} ${_BLNK_WRAP_LOG} || ${TRUE}; \
	fi
