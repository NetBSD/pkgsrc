# $NetBSD: bsd.buildlink3.mk,v 1.18 2003/09/28 10:38:03 jlam Exp $
#
# An example package buildlink3.mk file:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# .if !defined(FOO_BUILDLINK3_MK)
# FOO_BUILDLINK3_MK=	# defined
# BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+		# push
#
# .if !empty(BUILDLINK_DEPTH:M\+)
# BUILDLINK_DEPENDS+=	foo
# .endif
#
# BUILDLINK_PACKAGES+=		foo
# BUILDLINK_DEPENDS.foo?=	foo-lib>=1.0
# BUILDLINK_PKGSRCDIR.foo?=	../../category/foo-lib
#
# # We want "-lbar" to eventually resolve to "-lfoo".
# BUILDLINK_TRANSFORM+=		l:bar:foo
#
# .include "../../category/baz/buildlink3.mk"
#
# BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}	# pop
# .endif # FOO_BUILDLINK3_MK
# -------------8<-------------8<-------------8<-------------8<-------------
#
# Note that if a buildlink3.mk file is included, then the package Makefile
# has the expectation that it can use the value of BUILDLINK_PREFIX.<pkg>.
# If the buildlink3.mk tries to handle dependencies satisfied directly by
# the base system, then it should provide an appropriate value for
# BUILDLINK_PREFIX.<pkg> for that case.  The case where a dependency is
# satisfied by a pkgsrc-installed package is handled automatically by this
# file.
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
BUILDLINK_X11_DIR=	${BUILDLINK_DIR:H}/.x11-buildlink
BUILDLINK_SHELL?=	${SH}
BUILDLINK_OPSYS?=	${OPSYS}

# Prepend ${BUILDLINK_DIR}/bin to the PATH so that the wrappers are found
# first when searching for executables.
#
.if defined(_OPSYS_DEFAULT_PATH)
PATH:=		${BUILDLINK_DIR}/bin:${_OPSYS_DEFAULT_PATH}
.else
PATH:=		${BUILDLINK_DIR}/bin:${PATH}
.endif

# BUILDLINK_DEPENDS contains the list of packages for which we add
# dependencies.
#
BUILDLINK_DEPENDS?=	${BUILDLINK_PACKAGES}

X11_LINKS_SUBDIR=		share/x11-links
.if defined(USE_X11)
USE_X11_LINKS?=			YES
.  if empty(USE_X11_LINKS:M[nN][oO])
BUILDLINK_DEPENDS+=		x11-links
_BLNK_X11_LINKS_PACKAGE=	x11-links
.  else
_BLNK_X11_LINKS_PACKAGE=	# empty
.  endif
BUILDLINK_DEPENDS.x11-links=	x11-links>=0.12
BUILDLINK_DEPMETHOD.x11-links=	build
BUILDLINK_PKGSRCDIR.x11-links=	../../pkgtools/x11-links
_BLNK_X11_LINKS_DIR=	${BUILDLINK_PREFIX.x11-links}/${X11_LINKS_SUBDIR}
.else
_BLNK_X11_LINKS_PACKAGE=	# empty
.endif

.for _pkg_ in ${BUILDLINK_DEPENDS}
#
# Add the proper dependency on each package pulled in by buildlink3.mk
# files.  BUILDLINK_DEPMETHOD.<pkg> contains a list of either "full" or
# "build", and if any of that list if "full" then we use a full dependency
# on <pkg>, otherwise we use a build dependency on <pkg>.  By default,
# we use a full dependency.
#
.  if !defined(BUILDLINK_DEPMETHOD.${_pkg_})
BUILDLINK_DEPMETHOD.${_pkg_}=	full
.  endif
.  if !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mfull)
_BLNK_DEPMETHOD.${_pkg_}=	DEPENDS
.  elif !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mbuild)
_BLNK_DEPMETHOD.${_pkg_}=	BUILD_DEPENDS
.  endif
.  if defined(BUILDLINK_DEPENDS.${_pkg_}) && \
      defined(BUILDLINK_PKGSRCDIR.${_pkg_})
.    for _depends_ in ${BUILDLINK_DEPENDS.${_pkg_}}
${_BLNK_DEPMETHOD.${_pkg_}}+= \
	${_depends_}:${BUILDLINK_PKGSRCDIR.${_pkg_}}
.    endfor
.  endif
.endfor

# Generate default values for:
#
# _BLNK_PKG_DBDIR.<pkg>		contains all of the package metadata
#				files for <pkg>
#
# _BLNK_PKG_INFO.<pkg>		pkg_info(1) with correct dbdir to get
#				information for <pkg>
#
# BUILDLINK_PKGNAME.<pkg>	the name of the package
#
# BUILDLINK_PREFIX.<pkg>	contains all of the installed files
#				for <pkg>
#
# BUILDLINK_IS_DEPOT.<pkg>	"yes" or "no" for whether <pkg> is a
#				depoted package.
#
# BUILDLINK_IS_BUILTIN.<pkg>	"yes" or "no" for whether <pkg> is provided
#				in the base system.  This check is only
#				relevant for buildlink3.mk files that
#				provide a setting for this variable.  Where
#				this variable is set by a buildlink3.mk file,
#				you can typically force _only_ the check to
#				run by setting BUILDLINK_CHECK_BUILTIN.<pkg>
#				to "yes".
#
# BUILDLINK_CFLAGS.<pkg>,
# BUILDLINK_CPPFLAGS.<pkg>,
# BUILDLINK_LDFLAGS.<pkg>	contain extra compiler options, -D..., -I...
#				and -L.../-Wl,-R options to be passed to the
#				compiler/linker so that building against
#				<pkg> will work.
#
# BUILDLINK_INCDIRS.<pkg>,
# BUILDLINK_LIBDIRS.<pkg>	subdirectories of BUILDLINK_PREFIX.<pkg>
#				that should be added to the
#				compiler/linker search paths; these
#				directories are checked to see if they
#				exist before they're added to the search
#				paths.
#
.for _pkg_ in ${BUILDLINK_PACKAGES} ${_BLNK_X11_LINKS_PACKAGE}
.  if !defined(_BLNK_PKG_DBDIR.${_pkg_})
_BLNK_PKG_DBDIR.${_pkg_}!=	\
	dir="";								\
	if [ -d ${_PKG_DBDIR} ]; then					\
		dir=`cd ${_PKG_DBDIR}; ${PKG_ADMIN} -s "" lsbest "${BUILDLINK_DEPENDS.${_pkg_}}" || ${TRUE}`; \
	fi;								\
	case "$$dir" in							\
	"")	dir="not_found" ;;					\
	*)	if [ -f $$dir/+DEPOT ]; then				\
			dir=`${HEAD} -1 $$dir/+DEPOT`;			\
		fi ;;							\
	esac;								\
	${ECHO} $$dir
.    if empty(_BLNK_PKG_DBDIR.${_pkg_}:Mnot_found)
MAKEFLAGS+=	_BLNK_PKG_DBDIR.${_pkg_}=${_BLNK_PKG_DBDIR.${_pkg_}}
.    endif
.  endif
_BLNK_PKG_INFO.${_pkg_}=	\
	${PKG_INFO_CMD} -K ${_BLNK_PKG_DBDIR.${_pkg_}:H}

BUILDLINK_PKGNAME.${_pkg_}?=	${_BLNK_PKG_DBDIR.${_pkg_}:T}
.  if exists(${_BLNK_PKG_DBDIR.${_pkg_}}/+VIEWS)
BUILDLINK_IS_DEPOT.${_pkg_}?=	yes
.  else
BUILDLINK_IS_DEPOT.${_pkg_}?=	no
.  endif
.  if !defined(BUILDLINK_PREFIX.${_pkg_})
.    if !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
BUILDLINK_PREFIX.${_pkg_}?=	${_BLNK_PKG_DBDIR.${_pkg_}}
.    else
.      if empty(_BLNK_PKG_DBDIR.${_pkg_}:Mnot_found)
BUILDLINK_PREFIX.${_pkg_}!=	\
	${_BLNK_PKG_INFO.${_pkg_}} -qp ${BUILDLINK_PKGNAME.${_pkg_}} | ${SED}  -e "s,^[^/]*,,"
.      else
BUILDLINK_PREFIX.${_pkg_}?=	not_found
.      endif
.    endif
.    if empty(BUILDLINK_PREFIX.${_pkg_}:Mnot_found)
MAKEFLAGS+=	BUILDLINK_PREFIX.${_pkg_}=${BUILDLINK_PREFIX.${_pkg_}}
.    endif
.  endif
BUILDLINK_IS_BUILTIN.${_pkg_}?=	no
BUILDLINK_CPPFLAGS.${_pkg_}?=	# empty
BUILDLINK_LDFLAGS.${_pkg_}?=	# empty
BUILDLINK_INCDIRS.${_pkg_}?=	include
BUILDLINK_LIBDIRS.${_pkg_}?=	lib
.endfor

# BUILDLINK_CPPFLAGS and BUILDLINK_LDFLAGS contain the proper -I...
# and -L.../-Wl,-R... options to be passed to the compiler and linker
# to find the headers and libraries for the various packages at
# configure/build time.  BUILDLINK_CFLAGS contains any special compiler
# options needed when building against the various packages.
#
BUILDLINK_CPPFLAGS=	# empty
BUILDLINK_LDFLAGS=	# empty
BUILDLINK_CFLAGS=	# empty

.for _pkg_ in ${BUILDLINK_PACKAGES}
.  for _flag_ in ${BUILDLINK_CPPFLAGS.${_pkg_}}
.    if empty(BUILDLINK_CPPFLAGS:M${_flag_})
BUILDLINK_CPPFLAGS+=	${_flag_}
.    endif
.  endfor
.  for _flag_ in ${BUILDLINK_LDFLAGS.${_pkg_}}
.    if empty(BUILDLINK_LDFLAGS:M${_flag_})
BUILDLINK_LDFLAGS+=	${_flag_}
.    endif
.  endfor
.  for _flag_ in ${BUILDLINK_CFLAGS.${_pkg_}}
.    if empty(BUILDLINK_CFLAGS:M${_flag_})
BUILDLINK_CFLAGS+=	${_flag_}
.    endif
.  endfor
.  if !empty(BUILDLINK_INCDIRS.${_pkg_})
.    for _dir_ in ${BUILDLINK_INCDIRS.${_pkg_}:S/^/${BUILDLINK_PREFIX.${_pkg_}}\//}
.      if exists(${_dir_})
.        if empty(BUILDLINK_CPPFLAGS:M-I${_dir_})
BUILDLINK_CPPFLAGS+=	-I${_dir_}
.        endif
.      endif
.    endfor
.  endif
.  if !empty(BUILDLINK_LIBDIRS.${_pkg_})
.    for _dir_ in ${BUILDLINK_LIBDIRS.${_pkg_}:S/^/${BUILDLINK_PREFIX.${_pkg_}}\//}
.      if exists(${_dir_})
.        if empty(BUILDLINK_LDFLAGS:M-L${_dir_})
BUILDLINK_LDFLAGS+=	-L${_dir_}
.        endif
.        if (${_USE_RPATH} == "yes") && \
	    empty(BUILDLINK_LDFLAGS:M${_COMPILER_LD_FLAG}${RPATH_FLAG}${_dir_})
BUILDLINK_LDFLAGS+=		${_COMPILER_LD_FLAG}${RPATH_FLAG}${_dir_}
.        endif
.      endif
.    endfor
.  endif
.endfor
#
# Add the default view library directory to the runtime library search
# path so that wildcard dependencies on library packages can always be
# fulfilled through the default view.
#
.if (${_USE_RPATH} == "yes") && \
    empty(BUILDLINK_LDFLAGS:M${_COMPILER_LD_FLAG}${RPATH_FLAG}${LOCALBASE}/lib)
BUILDLINK_LDFLAGS+=	${_COMPILER_LD_FLAG}${RPATH_FLAG}${LOCALBASE}/lib
.endif
#
# Add the X11 library directory to the runtime library search path if
# the package uses X11.
#
.if defined(USE_X11) && \
    (${_USE_RPATH} == "yes") && \
    empty(BUILDLINK_LDFLAGS:M${_COMPILER_LD_FLAG}${RPATH_FLAG}${X11BASE}/lib)
BUILDLINK_LDFLAGS+=	${_COMPILER_LD_FLAG}${RPATH_FLAG}${X11BASE}/lib
.endif

.for _flag_ in ${BUILDLINK_CFLAGS}
.  if empty(CFLAGS:M${_flag_})
CFLAGS+=	${_flag_}
.  endif
.  if empty(CXXFLAGS:M${_flag_})
CXXFLAGS+=	${_flag_}
.  endif
.endfor
.for _flag_ in ${BUILDLINK_CPPFLAGS}
.  if empty(CPPFLAGS:M${_flag_})
CPPFLAGS+=	${_flag_}
.  endif
#
# We add BUILDLINK_CPPFLAGS to both CFLAGS and CXXFLAGS since much software
# ignores the value of CPPFLAGS that we set in the environment.
#
.  if empty(CFLAGS:M${_flag_})
CFLAGS+=	${_flag_}
.  endif
.  if empty(CXXFLAGS:M${_flag_})
CXXFLAGS+=	${_flag_}
.  endif
.endfor
.for _flag_ in ${BUILDLINK_LDFLAGS}
.  if empty(LDFLAGS:M${_flag_})
LDFLAGS+=	${_flag_}
.  endif
.endfor

# Create the buildlink include and lib directories so that the Darwin
# compiler/linker won't complain verbosely (on stdout, even!) when
# those directories are passed as sub-arguments of -I and -L.
#
.PHONY: buildlink-directories
do-buildlink: buildlink-directories
buildlink-directories:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}
.if defined(USE_X11)
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${BUILDLINK_X11_DIR}
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -sf ${BUILDLINK_DIR} ${BUILDLINK_X11_DIR}
.  if empty(USE_X11_LINKS:M[nN][oO])
.    if exists(${_BLNK_X11_LINKS_DIR})
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_BLNK_X11_LINKS_DIR} && ${PAX} -rw . ${BUILDLINK_X11_DIR}
.    else
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG} "x11-links doesn't seem to be installed."
	${_PKG_SILENT}${_PKG_DEBUG}${FALSE}
.    endif
.  endif
.endif
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/include
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/lib

# Create the buildlink wrappers before any of the other buildlink targets
# are run, as the wrappers may need to be used in some of those targets.
#
do-buildlink: buildlink-wrappers buildlink-${_BLNK_OPSYS}-wrappers

# The following variables are all optionally defined and control which
# package files are symlinked into ${BUILDLINK_DIR} and how their names
# are transformed during the symlinking:
#
# BUILDLINK_FILES.<pkg>
#	shell glob pattern relative to ${BUILDLINK_PREFIX.<pkg>} to be
#	symlinked into ${BUILDLINK_DIR}, e.g. include/*.h
#
# BUILDLINK_FILES_CMD.<pkg>
#	shell pipeline that outputs to stdout a list of files relative
#	to ${BUILDLINK_PREFIX.<pkg>}; the shell variable $${pkg_prefix}
#	may be used and is the subdirectory (ending in /) of
#	${BUILDLINK_PREFIX.<pkg>} to which the +CONTENTS is relative,
#	e.g. if `pkg_info -qp kaffe' returns "/usr/pkg/java/kaffe",
#	then $${pkg_prefix} is "java/kaffe/".  The resulting files are
#	to be symlinked into ${BUILDLINK_DIR}.  By default for
#	overwrite packages, BUILDLINK_FILES_CMD.<pkg> outputs the
#	contents of the include and lib directories in the package
#	+CONTENTS, and for pkgviews packages, it outputs any libtool
#	archives in lib directories.
#
# BUILDLINK_TRANSFORM.<pkg>
#	sed arguments used to transform the name of the source filename
#	into a destination filename, e.g. -e "s|/curses.h|/ncurses.h|g"
#
.for _pkg_ in ${BUILDLINK_PACKAGES}
_BLNK_COOKIE.${_pkg_}=		${BUILDLINK_DIR}/.buildlink_${_pkg_}_done

_BLNK_TARGETS+=			buildlink-${_pkg_}
_BLNK_TARGETS.${_pkg_}=		buildlink-${_pkg_}-message
_BLNK_TARGETS.${_pkg_}+=	${_BLNK_COOKIE.${_pkg_}}
_BLNK_TARGETS.${_pkg_}+=	buildlink-${_pkg_}-cookie

.ORDER: ${_BLNK_TARGETS.${_pkg_}}

.PHONY: buildlink-${_pkg_}
buildlink-${_pkg_}: ${_BLNK_TARGETS.${_pkg_}}

.PHONY: buildlink-${_pkg_}-message
buildlink-${_pkg_}-message:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_BUILDLINK_MSG} "=> Linking ${_pkg_} files into ${BUILDLINK_DIR}."

.PHONY: buildlink-${_pkg_}-cookie
buildlink-${_pkg_}-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TOUCH} ${TOUCH_FLAGS} ${_BLNK_COOKIE.${_pkg_}}

.  if (${PKG_INSTALLATION_TYPE} == "pkgviews") &&			\
      !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
BUILDLINK_FILES_CMD.${_pkg_}?=						\
	${_BLNK_PKG_INFO.${_pkg_}} -f ${BUILDLINK_PKGNAME.${_pkg_}} |	\
	${SED} -n '/File:/s/^[ 	]*File:[ 	]*//p' |		\
	${GREP} 'lib.*/lib[^/]*\.la$$' |				\
	${SED} "s,^,$${pkg_prefix},"
.  else
BUILDLINK_FILES_CMD.${_pkg_}?=						\
	${_BLNK_PKG_INFO.${_pkg_}} -f ${BUILDLINK_PKGNAME.${_pkg_}} |	\
	${SED} -n '/File:/s/^[ 	]*File:[ 	]*//p' |		\
	${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |			\
	${SED} "s,^,$${pkg_prefix},"
.  endif

${_BLNK_COOKIE.${_pkg_}}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	case ${BUILDLINK_PREFIX.${_pkg_}} in				\
	${X11BASE})	buildlink_dir="${BUILDLINK_X11_DIR}" ;;		\
	*)		buildlink_dir="${BUILDLINK_DIR}" ;;		\
	esac;								\
	cd ${BUILDLINK_PREFIX.${_pkg_}};				\
	pkg_prefix=`							\
		${ECHO} ${BUILDLINK_PREFIX.${_pkg_}} |			\
		${SED}	-e "s,^${BUILDLINK_PREFIX.${_pkg_}},,"		\
			-e "s,^/,,"					\
	`;								\
	case "$$pkg_prefix" in						\
	"")	;;							\
	*)	pkg_prefix="$${pkg_prefix}/" ;;				\
	esac;								\
	files=`${BUILDLINK_FILES_CMD.${_pkg_}}`;			\
	files="$$files ${BUILDLINK_FILES.${_pkg_}}";			\
	case "$$files" in						\
	"")	;;							\
	*)	for file in $$files; do					\
			src="${BUILDLINK_PREFIX.${_pkg_}}/$$file";	\
			if [ ! -f $$src ]; then				\
				${ECHO} "$$src: not found" >> ${.TARGET}; \
				continue;				\
			fi;						\
			if [ -z "${BUILDLINK_TRANSFORM.${_pkg_}:Q}" ]; then \
				dest="$$buildlink_dir/$$file";		\
				msg="$$src";				\
			else						\
				dest="$$buildlink_dir/$$file";		\
				dest=`${ECHO} $$dest | ${SED} ${BUILDLINK_TRANSFORM.${_pkg_}}`; \
				msg="$$src -> $$dest";			\
			fi;						\
			dir=`${DIRNAME} $$dest`;			\
			if [ ! -d $$dir ]; then				\
				${MKDIR} $$dir;				\
			fi;						\
			${RM} -f $$dest;				\
			case $$src in					\
			*.la)						\
				${CAT} $$src |				\
				${_BLNK_LT_ARCHIVE_FILTER.${_pkg_}}	\
				> $$dest;				\
				;;					\
			*)						\
				${LN} -sf $$src $$dest;			\
				;;					\
			esac;						\
			${ECHO} "$$msg" >> ${.TARGET};			\
		done;							\
		;;							\
	esac

# _BLNK_LT_ARCHIVE_FILTER.${_pkg_} is a command-line filter used in
# the previous target for transforming libtool archives (*.la) to
# allow libtool to properly interact with # buildlink at link time by
# linking against the libraries pointed to by symlinks in
# ${BUILDLINK_DIR}.
#
_BLNK_LT_ARCHIVE_FILTER.${_pkg_}=	\
	${AWK} '${_BLNK_LT_ARCHIVE_FILTER_AWK_SCRIPT.${_pkg_}}'

_BLNK_LT_ARCHIVE_FILTER_AWK_SCRIPT.${_pkg_}=	# empty
#
#     -	Modify the dependency_libs line by changing all full paths to
#	other *.la files into the canonical ${BUILDLINK_DIR} path.
#
_BLNK_LT_ARCHIVE_FILTER_AWK_SCRIPT.${_pkg_}+=				\
	/^dependency_libs=/ {						\
		line = $$0;						\
		line = gensub("/usr(/lib/lib[^/ 	]*\.la)", "${BUILDLINK_DIR}\\1", "g", line); \
		line = gensub("${DEPOTBASE}/[^/ 	]*(/[^ 	]*/lib[^/ 	]*\.la)", "${BUILDLINK_DIR}\\1", "g", line); \
		line = gensub("${X11BASE}(/[^ 	]*/lib[^/ 	]*\.la)", "${BUILDLINK_X11_DIR}\\1", "g", line); \
		line = gensub("${LOCALBASE}(/[^ 	]*/lib[^/ 	]*\.la)", "${BUILDLINK_DIR}\\1", "g", line); \
		line = gensub("-L/usr/lib[^/ 	]*[ 	]*", "", "g", line); \
		line = gensub("-L${X11BASE}/[^ 	]*[ 	]*", "", "g", line); \
		line = gensub("-L${LOCALBASE}/[^ 	]*[ 	]*", "", "g", line); \
		print line;						\
		next;							\
	}
.  if (${PKG_INSTALLATION_TYPE} == "overwrite") ||			\
      empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
#
#     -	Modify the libdir line to point to within ${BUILDLINK_DIR}.
#	This prevents libtool from looking into the original directory
#	for other *.la files.
#
_BLNK_LT_ARCHIVE_FILTER_AWK_SCRIPT.${_pkg_}+=				\
	/^libdir=/ {							\
		line = $$0;						\
		line = gensub("/usr(/lib/[^ 	]*)", "${BUILDLINK_DIR}\\1", "g", line); \
		line = gensub("${DEPOTBASE}/[^/ 	]*(/[^ 	]*)", "${BUILDLINK_DIR}\\1", "g", line); \
		line = gensub("${X11BASE}(/[^ 	]*)", "${BUILDLINK_X11_DIR}\\1", "g", line); \
		line = gensub("${LOCALBASE}(/[^ 	]*)", "${BUILDLINK_DIR}\\1", "g", line); \
		print line;						\
		next;							\
	}
.  endif
#
#     -	Leave all other lines alone.
#
_BLNK_LT_ARCHIVE_FILTER_AWK_SCRIPT.${_pkg_}+=	{ print }
.endfor

# Include any BUILDLINK_TARGETS provided in buildlink3.mk files in
# _BLNK_TARGETS.
#
_BLNK_TARGETS+=	${BUILDLINK_TARGETS}

# Add each of the targets in _BLNK_TARGETS as a prerequisite for the
# do-buildlink target.  This ensures that all the buildlink magic happens
# before any configure or build commands are called.
#
.for _target_ in ${_BLNK_TARGETS}
do-buildlink: ${_target_}
.endfor

# The configure process usually tests for outlandish or missing things
# that we don't want polluting the argument cache.
#
CONFIGURE_ENV+=		BUILDLINK_UPDATE_CACHE=no

# The caching code, which greatly speeds up the build process, works only
# on certain platforms.
#
_BLNK_CACHE_ALL=	# empty
_BLNK_CACHE_ALL+=	Darwin-6*-*
_BLNK_CACHE_ALL+=	IRIX-*-*
_BLNK_CACHE_ALL+=	NetBSD-1.[5-9]*-*
_BLNK_CACHE_ALL+=	SunOS-[25].[89]-*

# There are three different parts we can add to the common transforming
# cache to speed things up:
#
#	passthru	automatically accept certain options without
#			further checking
#
#	transform	change -[IL]{${X11BASE},${LOCALBASE},${DEPOTBASE}/*}
#			to the correct ${BUILDLINK_DIR} reference
#
#	block		block certain options without further checking
#
# Seeding the cache appropriately lets us handle large classes of options
# without having to go through the wrapper logic file, which generates
# a cache hit for every single option and bloats the cache quite bit more.
#
_BLNK_SEED_CACHE?=	passthru # transform block

.for _pattern_ in ${_BLNK_CACHE_ALL}
.  if !empty(MACHINE_PLATFORM:M${_pattern_})
CONFIGURE_ENV+=		BUILDLINK_CACHE_ALL=yes
MAKE_ENV+=		BUILDLINK_CACHE_ALL=yes
.  endif
.endfor

# _BLNK_ALLOWED_RPATHDIRS contains the list of directories for which we
# allow adding to the runtime library search path.  Package makefiles may
# add to its value through ${BUILDLINK_RPATHDIRS}.
#
_BLNK_ALLOWED_RPATHDIRS=	# empty
#
# Add all of the depot directories for packages whose headers and
# libraries we use.
#
.for _pkg_ in ${BUILDLINK_PACKAGES}
.  if !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
_BLNK_ALLOWED_RPATHDIRS+=	${BUILDLINK_PREFIX.${_pkg_}}
.  endif
.endfor
#
# Add the depot directory for the package we're building.
#
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
_BLNK_ALLOWED_RPATHDIRS+=	${PREFIX}
.endif
#
# Always add ${LOCALBASE}/lib to the runtime library search path so that
# wildcard dependencies work correctly when installing from binary
# packages.
#
_BLNK_ALLOWED_RPATHDIRS+=	${LOCALBASE}/lib
#
# Add ${X11BASE}/lib to the runtime library search path for USE_X11
# packages so that X11 libraries can be found.
#
.if defined(USE_X11)
_BLNK_ALLOWED_RPATHDIRS+=	${X11BASE}/lib
.endif
#
# Allow manually adding other directories to the runtime library search
# path, e.g. ${LOCALBASE}/qt3/lib.
#
.if defined(BUILDLINK_RPATHDIRS)
.  for _dir_ in ${BUILDLINK_RPATHDIRS}
_BLNK_ALLOWED_RPATHDIRS+=	${_dir_}
.  endfor
.endif

_BLNK_MANGLE_DIRS=	# empty
_BLNK_MANGLE_DIRS+=	${BUILDLINK_DIR}
_BLNK_MANGLE_DIRS+=	${BUILDLINK_X11_DIR}
_BLNK_MANGLE_DIRS+=	${WRKDIR}
_BLNK_MANGLE_DIRS+=	${_BLNK_ALLOWED_RPATHDIRS}

# We only want these for the untransform case, so don't add these
# directories to _BLNK_{,UN}PROTECT_DIRS below.
#
_BLNK_MANGLE_DIRS+=	${PREFIX}
_BLNK_MANGLE_DIRS+=	${X11BASE}

_BLNK_MANGLE_START=		_bUiLdLiNk_
_BLNK_MANGLE_END=		\#
.for _dir_ in ${_BLNK_MANGLE_DIRS}
_BLNK_MANGLE_DIR.${_dir_}=	\
	${_BLNK_MANGLE_START}${_dir_:S/\//_/g}${_BLNK_MANGLE_END}
.endfor
_BLNK_MANGLE_SED_PATTERN=	\
	${_BLNK_MANGLE_START}[^/ 	${_BLNK_MANGLE_END}]*${_BLNK_MANGLE_END}

_BLNK_PROTECT_DIRS=	# empty
_BLNK_UNPROTECT_DIRS=	# empty
_BLNK_PROTECT=		# empty
_BLNK_UNPROTECT=	# empty

_BLNK_PROTECT_DIRS+=	${BUILDLINK_DIR}
_BLNK_PROTECT_DIRS+=	${BUILDLINK_X11_DIR}
_BLNK_PROTECT_DIRS+=	${WRKDIR}
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
.  for _pkg_ in ${BUILDLINK_PACKAGES}
.    if !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
_BLNK_PROTECT_DIRS+=	${BUILDLINK_PREFIX.${_pkg_}}
_BLNK_UNPROTECT_DIRS+=	${BUILDLINK_PREFIX.${_pkg_}}
.    endif
.  endfor
.endif
_BLNK_UNPROTECT_DIRS+=	${WRKDIR}
_BLNK_UNPROTECT_DIRS+=	${BUILDLINK_X11_DIR}
_BLNK_UNPROTECT_DIRS+=	${BUILDLINK_DIR}

# Protect work directories and the dependency directories from all the
# transformations we're about to do.
#
.for _dir_ in ${_BLNK_PROTECT_DIRS}
_BLNK_TRANSFORM+=	mangle:${_dir_}:${_BLNK_MANGLE_DIR.${_dir_}}
.endfor
#
# Protect ${PREFIX} and ${X11BASE} from change when untransforming, e.g.
# when unbuildlinkifying files.
#
.for _dir_ in ${PREFIX} ${X11BASE}
_BLNK_TRANSFORM+=	untransform:mangle:${_dir_}:${_BLNK_MANGLE_DIR.${_dir_}}
.endfor
#
# Change any buildlink directories in runtime library search paths into
# the canonical actual installed paths.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
_BLNK_TRANSFORM+=	rpath:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}:${LOCALBASE}
.endif
#
# Protect some directories that we allow to be specified for the runtime
# library search path.
#
.for _dir_ in ${_BLNK_ALLOWED_RPATHDIRS}
_BLNK_TRANSFORM+=	rpath:${_dir_}:${_BLNK_MANGLE_DIR.${_dir_}}
.endfor
#
# Change references to ${DEPOTBASE}/<pkg> into ${LOCALBASE} so that
# "overwrite" packages think headers and libraries for "pkgviews" packages
# are just found in the default view.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
_BLNK_TRANSFORM+=       depot:${DEPOTBASE}:${LOCALBASE}
.endif
#
# Convert direct paths to shared libraries into "-Ldir -llib" equivalents.
#
_BLNK_TRANSFORM+=	p:${_BLNK_MANGLE_SED_PATTERN:Q}
_BLNK_TRANSFORM+=	p:
#
# Convert direct paths to static libraries and libtool archives in
# ${LOCALBASE} or ${X11BASE} into references into ${BUILDLINK_DIR}.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
.  if defined(USE_X11)
_BLNK_TRANSFORM+=	P:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
.  endif
_BLNK_TRANSFORM+=	P:${LOCALBASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}
.endif
#
# Transform references into ${X11BASE} into ${BUILDLINK_X11_DIR}.
#
.if defined(USE_X11)
_BLNK_TRANSFORM+=       I:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
_BLNK_TRANSFORM+=       L:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
.endif
#
# Transform references into ${LOCALBASE} into ${BUILDLINK_DIR}.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
_BLNK_TRANSFORM+=	I:${LOCALBASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}
_BLNK_TRANSFORM+=	L:${LOCALBASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}
.endif
#
# Add any package specified transformations (l:, etc.)
#
_BLNK_TRANSFORM+=	${BUILDLINK_TRANSFORM}
#
# Explicitly remove everything else that's an absolute path, since we've
# already protected the ones we care about.
#
_BLNK_TRANSFORM+=       r:
#
# Remove -Wl,-R* and *-rpath* if _USE_RPATH != "yes"
# Transform -Wl,-R* and *-rpath* if Sun compilers are used.
#
.if defined(_USE_RPATH) && empty(_USE_RPATH:M[yY][eE][sS])
_BLNK_TRANSFORM+=       no-rpath
.endif
#
# Undo the protection for the directories that we allow to be specified
# for the runtime library search path.
#
.for _dir_ in ${_BLNK_ALLOWED_RPATHDIRS}
_BLNK_TRANSFORM+=	rpath:${_BLNK_MANGLE_DIR.${_dir_}}:${_dir_}
.endfor
#
# Undo the protection for ${PREFIX} and ${X11BASE} so that the directory
# names are correct, e.g. when unbuildlinkifying files.
#
.for _dir_ in ${PREFIX} ${X11BASE}
_BLNK_TRANSFORM+=	untransform:mangle:${_BLNK_MANGLE_DIR.${_dir_}}:${_dir_}
.endfor
#
# Undo the protection so the correct directory names are passed to the
# the wrappee.
#
.for _dir_ in ${_BLNK_UNPROTECT_DIRS}
_BLNK_TRANSFORM+=	mangle:${_BLNK_MANGLE_DIR.${_dir_}}:${_dir_}
.endfor

_BLNK_TRANSFORM_SED+=	-f ${_BLNK_TRANSFORM_SEDFILE}
_BLNK_UNTRANSFORM_SED+=	-f ${_BLNK_UNTRANSFORM_SEDFILE}

# UNBUILDLINK_PATTERNS and UNBUILDLINK_FILES list shell globs and files
# relative to ${WRKSRC} that need to have reference to ${BUILDLINK_DIR}
# stripped out of them.
#
UNBUILDLINK_PATTERNS?=		# empty
_UNBUILDLINK_PATTERNS=		${UNBUILDLINK_PATTERNS}
_UNBUILDLINK_PATTERNS+=		*-config
_UNBUILDLINK_PATTERNS+=		*Conf.sh
_UNBUILDLINK_PATTERNS+=		*.pc
_UNBUILDLINK_PATTERNS_FIND=	\
	\( ${_UNBUILDLINK_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)
UNBUILDLINK_FILES?=		# empty
_UNBUILDLINK_FILES=		\
	${UNBUILDLINK_FILES}	\
	`${FIND} . ${_UNBUILDLINK_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT} -u`
#
# When "unbuildlinkifying" a file, we must remove references to the
# buildlink directories and change any -llib to the proper replacement
# libraries (-lreadline -> -ledit, etc.).  Redundant -Idir and -Ldir
# options are removed to optimize the resulting file.  Also, prefer the
# .la files in ${LOCALBASE}/lib over the ones in ${DEPOTBASE}/*/lib when
# creating new .la files.  This makes "overwrite" packages look and feel
# more like they would without the pkgviews integration.
#
UNBUILDLINK_SED?=		# empty
_UNBUILDLINK_SED=		${UNBUILDLINK_SED}
_UNBUILDLINK_SED+=		${_BLNK_UNTRANSFORM_SED}

SUBST_CLASSES+=			unbuildlink
SUBST_STAGE.unbuildlink=	post-build
SUBST_MESSAGE.unbuildlink=	\
	"Fixing buildlink references in files-to-be-installed."
SUBST_FILES.unbuildlink=	${_UNBUILDLINK_FILES}
SUBST_SED.unbuildlink=		${_UNBUILDLINK_SED}

# Generate wrapper scripts for the compiler tools that sanitize the
# argument list by converting references to ${LOCALBASE} and ${X11BASE}
# into references to ${BUILDLINK_DIR} and ${BUILDLINK_X11_DIR}. These
# wrapper scripts are to be used instead of the actual compiler tools when
# building software.
#
# BUILDLINK_CC, BUILDLINK_LD, etc. are the full paths to the wrapper
#       scripts.
#
# ALIASES.CC, ALIASES.LD, etc. are the other names by which each wrapper
#       may be invoked.
#
_BLNK_WRAPPEES=		AS CC CXX CPP LD
.if defined(USE_FORTRAN)
_BLNK_WRAPPEES+=	FC
.endif
.if defined(USE_LIBTOOL)
PKGLIBTOOL=		${BUILDLINK_LIBTOOL}
PKGSHLIBTOOL=		${BUILDLINK_SHLIBTOOL}
.endif
_BLNK_WRAPPEES+=	LIBTOOL SHLIBTOOL
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
# _BLNK_WRAP_SETENV.<wrappee> resets the value of CC, CPP, etc. in the
#	configure and make environments (CONFIGURE_ENV, MAKE_ENV) so that
#	they point to the wrappers.
#
# _BLNK_WRAP_{*CACHE*,*LOGIC*}.<wrappee> are parts of the wrapper script
#	system as described in pkgsrc/mk/buildlink3/README.  The files not
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
_BLNK_WRAP_MARSHALL=		${BUILDLINK_DIR}/bin/.marshall
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
_BLNK_WRAPPER_SH.${_wrappee_}=	${.CURDIR}/../../mk/buildlink3/wrapper.sh
_BLNK_WRAP_SETENV.${_wrappee_}=	${_wrappee_}="${BUILDLINK_${_wrappee_}:T}"
_BLNK_WRAP_SANITIZE_PATH.${_wrappee_}=		${_BLNK_WRAP_SANITIZE_PATH}
_BLNK_WRAP_EXTRA_FLAGS.${_wrappee_}=		# empty
_BLNK_WRAP_ENV.${_wrappee_}=			${_BLNK_WRAP_ENV}
_BLNK_WRAP_MARSHALL.${_wrappee_}=		${_BLNK_WRAP_MARSHALL}
_BLNK_WRAP_PRIVATE_PRE_CACHE.${_wrappee_}=	${_BLNK_EMPTY_FILE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}=	${_BLNK_EMPTY_FILE}
_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}=		${_BLNK_EMPTY_FILE}
_BLNK_WRAP_PRIVATE_POST_CACHE.${_wrappee_}=	${_BLNK_EMPTY_FILE}
_BLNK_WRAP_CACHE_ADD.${_wrappee_}=		${_BLNK_WRAP_CACHE_ADD_TRANSFORM}
_BLNK_WRAP_CACHE.${_wrappee_}=			${_BLNK_WRAP_CACHE_TRANSFORM}
_BLNK_WRAP_LOGIC.${_wrappee_}=			${_BLNK_WRAP_LOGIC_TRANSFORM}
_BLNK_WRAP_POST_LOGIC.${_wrappee_}=		${_BLNK_EMPTY_FILE}
.endfor

# Don't bother adding AS, CPP to the configure or make environments as
# adding them seems to break some GNU configure scripts.
#
_BLNK_WRAP_SETENV.AS=		# empty
_BLNK_WRAP_SETENV.CPP=		# empty

# Also override any F77 value in the environment when compiling Fortran
# code.
#
_BLNK_WRAP_SETENV.FC+=		F77="${BUILDLINK_FC:T}"

# Don't override the default LIBTOOL and SHLIBTOOL settings in the
# environment, as they already correctly point to the correct values, and
# don't sanitize the PATH because we want libtool to invoke the wrapper
# scripts, too.
#
_BLNK_WRAP_SETENV.LIBTOOL=	# empty
_BLNK_WRAPPER_SH.LIBTOOL=	${.CURDIR}/../../mk/buildlink3/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.LIBTOOL=	# empty
#
_BLNK_WRAP_SETENV.SHLIBTOOL=	# empty
_BLNK_WRAPPER_SH.SHLIBTOOL=	${.CURDIR}/../../mk/buildlink3/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.SHLIBTOOL=	# empty

# We need to "unbuildlinkify" any libtool archives.
_BLNK_WRAP_LT_UNTRANSFORM_SED=		${_UNBUILDLINK_SED}

.if defined(USE_SUNPRO)
_BLNK_WRAP_PRIVATE_PRE_CACHE.CC=	${_BLNK_WRAP_PRE_CACHE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.CC=	${BUILDLINK_DIR}/bin/.sunpro-cc-cache-add
_BLNK_WRAP_PRIVATE_CACHE.CC=		${BUILDLINK_DIR}/bin/.sunpro-cc-cache
_BLNK_WRAP_PRIVATE_POST_CACHE.CC=	${BUILDLINK_DIR}/bin/.sunpro-cc-post-cache
_BLNK_WRAP_POST_LOGIC.CC=		${BUILDLINK_DIR}/bin/.sunpro-cc-post-logic
#
# The SunPro C++ compiler wrapper shares cache information with the C
# compiler.
#
_BLNK_WRAP_PRIVATE_PRE_CACHE.CXX=	${_BLNK_WRAP_PRE_CACHE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.CXX=	${BUILDLINK_DIR}/bin/.sunpro-cc-cache-add
_BLNK_WRAP_PRIVATE_CACHE.CXX=		${BUILDLINK_DIR}/bin/.sunpro-cc-cache
_BLNK_WRAP_PRIVATE_POST_CACHE.CXX=	${BUILDLINK_DIR}/bin/.sunpro-cc-post-cache
_BLNK_WRAP_POST_LOGIC.CXX=		${BUILDLINK_DIR}/bin/.sunpro-cc-post-logic
.endif	# USE_SUNPRO

_BLNK_WRAP_PRIVATE_PRE_CACHE.LD=	${_BLNK_WRAP_PRE_CACHE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.LD=	${BUILDLINK_DIR}/bin/.ld-cache-add
_BLNK_WRAP_PRIVATE_CACHE.LD=		${BUILDLINK_DIR}/bin/.ld-cache
_BLNK_WRAP_PRIVATE_POST_CACHE.LD=	${BUILDLINK_DIR}/bin/.ld-post-cache
_BLNK_WRAP_POST_LOGIC.LD=		${BUILDLINK_DIR}/bin/.ld-post-logic

_BLNK_WRAP_PRIVATE_PRE_CACHE.LIBTOOL=	${_BLNK_WRAP_PRE_CACHE}
_BLNK_WRAP_PRIVATE_CACHE_ADD.LIBTOOL=	${BUILDLINK_DIR}/bin/.libtool-cache-add
_BLNK_WRAP_PRIVATE_CACHE.LIBTOOL=	${BUILDLINK_DIR}/bin/.libtool-cache
_BLNK_WRAP_PRIVATE_POST_CACHE.LIBTOOL=	${BUILDLINK_DIR}/bin/.libtool-post-cache
_BLNK_WRAP_POST_LOGIC.LIBTOOL=		${BUILDLINK_DIR}/bin/.libtool-post-logic

# shlibtool shares cache information with libtool.
_BLNK_WRAP_PRIVATE_PRE_CACHE.SHLIBTOOL=	${_BLNK_WRAP_PRIVATE_PRE_CACHE.LIBTOOL}
_BLNK_WRAP_PRIVATE_CACHE_ADD.SHLIBTOOL=	${_BLNK_WRAP_PRIVATE_CACHE_ADD.LIBTOOL}
_BLNK_WRAP_PRIVATE_CACHE.SHLIBTOOL=	${_BLNK_WRAP_PRIVATE_CACHE.LIBTOOL}
_BLNK_WRAP_PRIVATE_POST_CACHE.SHLIBTOOL= ${_BLNK_WRAP_PRIVATE_POST_CACHE.LIBTOOL}
_BLNK_WRAP_POST_LOGIC.SHLIBTOOL=	${_BLNK_WRAP_POST_LOGIC.LIBTOOL}

# Allow BUILDLINK_SETENV.<wrappee> to override _BLNK_WRAP_SETENV.<wrappee>.
.for _wrappee_ in ${_BLNK_WRAPPEES}
.  if defined(BUILDLINK_SETENV.${_wrappee_})
_BLNK_WRAP_SETENV.${_wrappee_}=	${BUILDLINK_SETENV.${_wrappee_}}
.  endif
.endfor

# Don't transform the arguments for imake, which uses the C preprocessor
# to generate Makefiles, so that imake will find its config files.
#
.if defined(USE_X11)
_BLNK_WRAP_CACHE_ADD.IMAKE=	${_BLNK_WRAP_CACHE_ADD}
_BLNK_WRAP_CACHE.IMAKE=		${_BLNK_WRAP_CACHE}
_BLNK_WRAP_LOGIC.IMAKE=		${_BLNK_WRAP_LOGIC}
.endif

# Silently pass the appropriate flags to the compiler/linker commands so
# that headers and libraries in ${BUILDLINK_DIR}/{include,lib} are found
# before the system headers and libraries.
#
_BLNK_CPPFLAGS=			-I${BUILDLINK_DIR}/include
_BLNK_LDFLAGS=			-L${BUILDLINK_DIR}/lib
_BLNK_WRAP_EXTRA_FLAGS.CC=	${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.CXX=	${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.CPP=	${_BLNK_CPPFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.FC=	${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.LD=	${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.LIBTOOL=		${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.SHLIBTOOL=	${_BLNK_WRAP_EXTRA_FLAGS.LIBTOOL}

.PHONY: buildlink-wrappers

buildlink-wrappers: ${_BLNK_LIBTOOL_DO_INSTALL}
buildlink-wrappers: ${_BLNK_LIBTOOL_FIX_LA}

.for _wrappee_ in ${_BLNK_WRAPPEES}
CONFIGURE_ENV+=	${_BLNK_WRAP_SETENV.${_wrappee_}}
MAKE_ENV+=	${_BLNK_WRAP_SETENV.${_wrappee_}}

BUILDLINK_${_wrappee_}=	\
	${BUILDLINK_DIR}/bin/${${_wrappee_}:T:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}

# Filter to scrunch shell scripts by removing comments and empty lines.
_BLNK_SH_CRUNCH_FILTER= \
	${GREP} -v "^\#[^!]" | ${GREP} -v "^[ 	][ 	]*\#" |		\
	${GREP} -v "^\#$$" | ${GREP} -v "^[ 	]*$$"

_BLNK_WRAPPER_TRANSFORM_SED.${_wrappee_}=				\
	-e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"			\
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
	-e "s|@_BLNK_WRAP_EXTRA_FLAGS@|${_BLNK_WRAP_EXTRA_FLAGS.${_wrappee_}:Q}|g" \
	-e "s|@_BLNK_WRAP_MARSHALL@|${_BLNK_WRAP_MARSHALL.${_wrappee_}:Q}|g" \
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

buildlink-wrappers: ${BUILDLINK_${_wrappee_}}
.if !target(${BUILDLINK_${_wrappee_}})
${BUILDLINK_${_wrappee_}}:						\
		${_BLNK_WRAPPER_SH.${_wrappee_}}			\
		${_BLNK_WRAP_MARSHALL.${_wrappee_}}			\
		${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}}		\
		${_BLNK_WRAP_CACHE.${_wrappee_}}			\
		${_BLNK_WRAP_LOGIC.${_wrappee_}}			\
		${_BLNK_WRAP_POST_LOGIC.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"=> Creating wrapper: ${.TARGET}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	wrappee="${${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}";	\
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
			${ECHO_MSG} "Unable to create \"$${wrappee}\" wrapper script: no such file"; \
			exit 1;						\
		fi;							\
		;;							\
	esac;								\
	${MKDIR} ${.TARGET:H};						\
	${CAT} ${_BLNK_WRAPPER_SH.${_wrappee_}}	|			\
	${SED}	${_BLNK_WRAPPER_TRANSFORM_SED.${_wrappee_}}		\
		-e "s|@WRAPPEE@|$${absdir}${${_wrappee_}:Q}|g" |	\
	${_BLNK_SH_CRUNCH_FILTER}					\
	> ${.TARGET};							\
	${CHMOD} +x ${.TARGET}
.endif

.  for _alias_ in ${_ALIASES.${_wrappee_}:S/^/${BUILDLINK_DIR}\/bin\//}
.    if !target(${_alias_})
buildlink-wrappers: ${_alias_}
${_alias_}: ${BUILDLINK_${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"=> Linking wrapper: ${.TARGET}"
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -f ${BUILDLINK_${_wrappee_}} ${.TARGET}
.    endif
.  endfor # _alias_
.endfor   # _wrappee_

# Allow BUILDLINK_ENV to override shell environment settings in
# ${CONFIGURE_ENV} and in ${MAKE_ENV} for the configure and build processes,
# respectively.
#
CONFIGURE_ENV+=	${BUILDLINK_ENV}
MAKE_ENV+=	${BUILDLINK_ENV}

# OS-specific overrides for buildlink3 wrappers
#
.if defined(USE_SUNPRO)
_BLNK_WRAPPEES.SunOS?=	CC CXX
SUNWSPROBASE?=		/opt/SUNWspro
CC.SunOS?=		${SUNWSPROBASE}/bin/cc
CXX.SunOS?=		${SUNWSPROBASE}/bin/CC
.endif

.PHONY: buildlink-${_BLNK_OPSYS}-wrappers
buildlink-${_BLNK_OPSYS}-wrappers: buildlink-wrappers
.for _wrappee_ in ${_BLNK_WRAPPEES.${_BLNK_OPSYS}}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -x "${${_wrappee_}.${_BLNK_OPSYS}}" ]; then		\
		wrapper="${BUILDLINK_DIR}/bin/${${_wrappee_}.${_BLNK_OPSYS}:T}"; \
		${ECHO_BUILDLINK_MSG}					\
			"=> Creating ${_BLNK_OPSYS} wrapper: $${wrapper}"; \
		${RM} -f $${wrapper};					\
		${CAT} ${_BLNK_WRAPPER_SH.${_wrappee_}} |		\
		${SED}	${_BLNK_WRAPPER_TRANSFORM_SED.${_wrappee_}}	\
			-e "s|@WRAPPEE@|${${_wrappee_}.${_BLNK_OPSYS}}|g" | \
		${_BLNK_SH_CRUNCH_FILTER}				\
		> $${wrapper};						\
		${CHMOD} +x $${wrapper};				\
		for file in ${_ALIASES.${_wrappee_}:S/^/${BUILDLINK_DIR}\/bin\//}; do \
			if [ "$${file}" != "$${wrappee}" ]; then	\
				${TOUCH} $${file};			\
			fi;						\
		done;							\
	fi
.endfor

.if !target(${_BLNK_EMPTY_FILE})
${_BLNK_EMPTY_FILE}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.endif

.if !target(${_BLNK_WRAP_MARSHALL})
${_BLNK_WRAP_MARSHALL}: ${.CURDIR}/../../mk/buildlink3/marshall
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}
.endif

.if !target(${_BLNK_WRAP_PRE_CACHE})
${_BLNK_WRAP_PRE_CACHE}: ${.CURDIR}/../../mk/buildlink3/pre-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}
.endif

.if !target(${_BLNK_WRAP_CACHE_ADD})
${_BLNK_WRAP_CACHE_ADD}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.endif

.if !target(${_BLNK_WRAP_CACHE})
${_BLNK_WRAP_CACHE}:							\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_CACHE_ADD}					\
		${_BLNK_WRAP_POST_CACHE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
.endif

.if !target(${_BLNK_WRAP_CACHE_TRANSFORM})
${_BLNK_WRAP_CACHE_TRANSFORM}:						\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_CACHE_ADD_TRANSFORM}			\
		${_BLNK_WRAP_POST_CACHE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
.endif

.if !target(${_BLNK_WRAP_POST_CACHE})
${_BLNK_WRAP_POST_CACHE}: ${.CURDIR}/../../mk/buildlink3/post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}
.endif

${BUILDLINK_DIR}/bin/.sunpro-cc-post-cache:				\
		${.CURDIR}/../../mk/buildlink3/sunpro-cc-post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${BUILDLINK_DIR}/bin/.ld-post-cache:					\
		${.CURDIR}/../../mk/buildlink3/ld-post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${BUILDLINK_DIR}/bin/.libtool-post-cache:				\
		${.CURDIR}/../../mk/buildlink3/libtool-post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

.for _wrappee_ in ${_BLNK_WRAPPEES}
.  if !target(${_BLNK_WRAP_PRIVATE_PRE_CACHE.${_wrappee_}})
${_BLNK_WRAP_PRIVATE_PRE_CACHE.${_wrappee_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif
.  if !target(${_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}})
${_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif
.  if !target(${_BLNK_WRAP_PRIVATE_POST_CACHE.${_wrappee_}})
${_BLNK_WRAP_PRIVATE_POST_CACHE.${_wrappee_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif
.  if !target(${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}})
${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}}:				\
		${_BLNK_WRAP_PRIVATE_PRE_CACHE.${_wrappee_}}		\
		${_BLNK_WRAP_PRIVATE_CACHE_ADD.${_wrappee_}}		\
		${_BLNK_WRAP_PRIVATE_POST_CACHE.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
.  endif
.endfor

.if !target(${_BLNK_WRAP_LOGIC})
${_BLNK_WRAP_LOGIC}: ${.CURDIR}/../../mk/buildlink3/logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e 's|@_BLNK_TRANSFORM_SED@||g'				\
		${.ALLSRC} | ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
.endif

.if !target(${_BLNK_WRAP_LOGIC_TRANSFORM})
${_BLNK_WRAP_LOGIC_TRANSFORM}:						\
		${.CURDIR}/../../mk/buildlink3/logic			\
		${_BLNK_TRANSFORM_SEDFILE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e 's|@_BLNK_TRANSFORM_SED@|${_BLNK_TRANSFORM_SED:Q}|g'	\
		${.CURDIR}/../../mk/buildlink3/logic			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
.endif

${BUILDLINK_DIR}/bin/.sunpro-cc-post-logic:				\
		${.CURDIR}/../../mk/buildlink3/sunpro-cc-post-logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${BUILDLINK_DIR}/bin/.ld-post-logic:					\
		${.CURDIR}/../../mk/buildlink3/ld-post-logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${BUILDLINK_DIR}/bin/.libtool-post-logic:				\
		${.CURDIR}/../../mk/buildlink3/libtool-post-logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

.for _wrappee_ in ${_BLNK_WRAPPEES}
.  if !target(${_BLNK_WRAP_PRIVATE_POST_LOGIC.${_wrappee_}})
${_BLNK_WRAP_PRIVATE_POST_LOGIC.${_wrappee_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif
.endfor

${BUILDLINK_DIR}/bin/.libtool-do-install:				\
		${.CURDIR}/../../mk/buildlink3/libtool-do-install
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${BUILDLINK_DIR}/bin/.libtool-fix-la:					\
		${.CURDIR}/../../mk/buildlink3/libtool-fix-la		\
		${_BLNK_UNTRANSFORM_SEDFILE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@DEPOTBASE@|${DEPOTBASE}|g"			\
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
		${.CURDIR}/../../mk/buildlink3/libtool-fix-la		\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

# Seed the common transforming cache with obvious values that greatly
# speed up the wrappers.
#
_BLNK_RPATH_FLAGS=	${RPATH_FLAG}
_BLNK_RPATH_FLAGS+=	-Wl,${RPATH_FLAG}
.for _rflag_ in \
	-Wl,-R -Wl,-rpath, -Wl,--rpath, -Wl,-rpath-link, -Wl,--rpath-link
.  if empty(_BLNK_RPATH_FLAGS:M${_rflag_})
_BLNK_RPATH_FLAGS+=	${_rflag_}
.  endif
.endfor
#
.if !empty(_BLNK_SEED_CACHE:Mpassthru)
#
# Pass through all single letter options, because we don't touch those.
#
_BLNK_CACHE_PASSTHRU_GLOB=	-?
#
# Directories in the ${WRKDIR} should all be allowed in -[IL]<dir>
_BLNK_CACHE_PASSTHRU_GLOB+=	-[IL]${WRKDIR}*|-[IL]${BUILDLINK_DIR}*
#
# Directories relative to the srcdir should be allowed in -[IL]<dir>
_BLNK_CACHE_PASSTHRU_GLOB+=	-[IL].|-[IL]./*|-[IL]..*|-[IL][!/]*
#
# Allow the depot directories for packages for which we need to find
# headers and libraries for both -[IL]<dir>.
#
.  if ${PKG_INSTALLATION_TYPE} == "pkgviews"
.    for _pkg_ in ${BUILDLINK_PACKAGES}
.      if !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
_BLNK_CACHE_PASSTHRU_GLOB+=	-[IL]${BUILDLINK_PREFIX.${_pkg_}}/*
.      endif
.    endfor
.  endif
#
# Allow all subdirs of ${_BLNK_ALLOWED_RPATHDIRS} to be in the runtime
# library search path.
#
.  if ${_USE_RPATH} == "yes"
.    for _dir_ in ${_BLNK_ALLOWED_RPATHDIRS}
.      for _R_ in ${_BLNK_RPATH_FLAGS}
_BLNK_CACHE_PASSTHRU_GLOB+=	${_R_}${_dir_}|${_R_}${_dir_}/*
.      endfor
.    endfor
.  endif
.endif # _BLNK_SEED_CACHE has "passthru"

.if !empty(_BLNK_SEED_CACHE:Mblock)
#
# Block all other absolute paths (we handle the ${X11BASE} case below).
#
_BLNK_CACHE_BLOCK_GLOB=		-[IL]/*
.  if ${_USE_RPATH} == "yes"
.    for _R_ in ${_BLNK_RPATH_FLAGS}
_BLNK_CACHE_BLOCK_GLOB:=	${_BLNK_CACHE_BLOCK_GLOB}|${_R_}/*
.    endfor
.  endif
.endif # _BLNK_SEED_CACHE has "block"

${_BLNK_WRAP_CACHE_ADD_TRANSFORM}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${.TARGET}
.if !empty(_BLNK_SEED_CACHE)
.  if !empty(_BLNK_SEED_CACHE:Mpassthru)
.    for _glob_ in ${_BLNK_CACHE_PASSTHRU_GLOB}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "${_glob_})";						\
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
.    endfor
.  endif # _BLNK_SEED_CACHE has "passthru"
.  if !empty(_BLNK_SEED_CACHE:Mtransform)
.    if ${PKG_INSTALLATION_TYPE} == "overwrite"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "-I${DEPOTBASE}/*)";					\
	  ${ECHO} "	arg=\"-I${BUILDLINK_DIR}/\$${arg#-I${DEPOTBASE}/[!/]*/}\""; \
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "-L${DEPOTBASE}/*)";					\
	  ${ECHO} "	arg=\"-L${BUILDLINK_DIR}/\$${arg#-I${DEPOTBASE}/[!/]*/}\""; \
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "-I${LOCALBASE}/*)";					\
	  ${ECHO} "	arg=\"-I${BUILDLINK_DIR}/\$${arg#-I${LOCALBASE}/}\""; \
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "-L${LOCALBASE}/*)";					\
	  ${ECHO} "	arg=\"-L${BUILDLINK_DIR}/\$${arg#-L${LOCALBASE}/}\""; \
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
.    endif
.    if defined(USE_X11)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "-I${X11BASE}/*)";					\
	  ${ECHO} "	arg=\"-I${BUILDLINK_X11_DIR}/\$${arg#-I${X11BASE}/}\""; \
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "-L${X11BASE}/*)";					\
	  ${ECHO} "	arg=\"-L${BUILDLINK_X11_DIR}/\$${arg#-L${X11BASE}/}\""; \
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
.    endif
.  endif # _BLNK_SEED_CACHE has "transform"
.  if !empty(_BLNK_SEED_CACHE:Mblock)
.    for _glob_ in ${_BLNK_CACHE_BLOCK_GLOB}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "${_glob_})";						\
	  ${ECHO} "	arg=; cachehit=yes;";				\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
.    endfor
.  endif # _BLNK_SEED_CACHE has "block"
.endif	 # _BLNK_SEED_CACHE

${_BLNK_GEN_TRANSFORM}: ${.CURDIR}/../../mk/buildlink3/gen-transform.sh
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@_BLNK_TRANSFORM_SEDFILE@|${_BLNK_TRANSFORM_SEDFILE:Q}|g" \
		-e "s|@_BLNK_UNTRANSFORM_SEDFILE@|${_BLNK_UNTRANSFORM_SEDFILE:Q}|g" \
		-e "s|@_COMPILER_LD_FLAG@|${_COMPILER_LD_FLAG:Q}|g"     \
		-e "s|@_OPSYS_RPATH_NAME@|${_OPSYS_RPATH_NAME:Q}|g"     \
		-e "s|@BUILDLINK_SHELL@|${BUILDLINK_SHELL:Q}|g"         \
		-e "s|@CAT@|${CAT:Q}|g"                                 \
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_TRANSFORM_SEDFILE} ${_BLNK_UNTRANSFORM_SEDFILE}: ${_BLNK_GEN_TRANSFORM}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${_BLNK_GEN_TRANSFORM}		\
		${_BLNK_TRANSFORM}
