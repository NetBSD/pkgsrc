# $NetBSD: bsd.buildlink2.mk,v 1.90.4.1 2003/07/16 09:33:48 jlam Exp $
#
# An example package buildlink2.mk file:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# BUILDLINK_PACKAGES+=		foo
# BUILDLINK_PKGBASE.foo=	foo-lib
# BUILDLINK_DEPENDS.foo?=	foo-lib>=1.0
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
_BLNK_OPSYS=		${OPSYS}

BUILDLINK_SHELL?=	${SH}

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

.for _pattern_ in ${_BLNK_CACHE_ALL}
.  if !empty(MACHINE_PLATFORM:M${_pattern_})
CONFIGURE_ENV+=		BUILDLINK_CACHE_ALL=yes
MAKE_ENV+=		BUILDLINK_CACHE_ALL=yes
.  endif
.endfor

# Prepend ${BUILDLINK_DIR}/bin to the PATH so that the wrappers are found
# first when searching for executables.
#
PATH:=			${BUILDLINK_DIR}/bin:${PATH}

# BUILDLINK_DEPENDS contains the list of packages for which we add
# dependencies.
#
BUILDLINK_DEPENDS=	${BUILDLINK_PACKAGES}

.for _pkg_ in ${BUILDLINK_DEPENDS}
#
# Add the proper dependency on each package pulled in by buildlink2.mk
# files.  BUILDLINK_DEPMETHOD.<pkg> contains a list of either "full" or
# "build", and if any of that list if "full" then we use a full dependency
# on <pkg>, otherwise we use a build dependency on <pkg>.  By default,
# we use a full dependency.
#
.  if !defined(BUILDLINK_DEPMETHOD.${_pkg_})
BUILDLINK_DEPMETHOD.${_pkg_}=	full
.  endif
.  if !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mfull)
_BUILDLINK_DEPMETHOD.${_pkg_}=	DEPENDS
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
.endfor

.for _pkg_ in ${BUILDLINK_PACKAGES}
#
# BUILDLINK_PLIST_CMD.<pkg> is a sequence of shell commands that extracts
# a list of all of the files installed by <pkg>.  This list is relative to
# ${BUILDLINK_PREFIX.<pkg>}.
#
BUILDLINK_PLIST_CMD.${_pkg_}= \
	${PKG_INFO} -f ${BUILDLINK_PKGBASE.${_pkg_}} |			\
		${SED} -n '/File:/s/^[ 	]*File:[ 	]*//p'
.endfor

# Pass the proper -I.../-L.../-Wl,-R... flags to the compiler and linker.

_BLNK_CPPFLAGS=		# empty
_BLNK_LDFLAGS=		# empty

.for _pkg_ in ${BUILDLINK_PACKAGES}
_BLNK_INCDIR.${_pkg_}=	${BUILDLINK_PREFIX.${_pkg_}}/include
_BLNK_LIBDIR.${_pkg_}=	${BUILDLINK_PREFIX.${_pkg_}}/lib

.  if exists(${_BLNK_INCDIR.${_pkg_}})
.    if empty(_BLNK_CPPFLAGS:M-I${_BLNK_INCDIR.${_pkg_}})
_BLNK_CPPFLAGS+=	-I${_BLNK_INCDIR.${_pkg_}}
.    endif
.  endif
.  if exists(${_BLNK_LIBDIR.${_pkg_}})
.    if empty(_BLNK_LDFLAGS:M-L${_BLNK_LIBDIR.${_pkg_}})
_BLNK_LDFLAGS+=		-L${_BLNK_LIBDIR.${_pkg_}}
.    endif
.    if empty(_BLNK_LDFLAGS:M-L${_BLNK_LIBDIR.${_pkg_}})
_BLNK_LDFLAGS+=		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.${_pkg_}}/lib
.    endif
.  endif
.endfor

.if ${PKG_INSTALLATION_TYPE} == "overwrite"
.  if empty(_BLNK_CPPFLAGS:M-I${LOCALBASE}/include)
_BLNK_CPPFLAGS+=	-I${LOCALBASE}/include
.  endif
.  if empty(_BLNK_LDFLAGS:M-L${LOCALBASE}/lib)
_BLNK_LDFLAGS+=		-L${LOCALBASE}/lib
.  endif
.endif
.if empty(_BLNK_LDFLAGS:M-Wl,${RPATH_FLAG}${LOCALBASE}/lib)
_BLNK_LDFLAGS+=		-Wl,${RPATH_FLAG}${LOCALBASE}/lib
.endif

.if defined(USE_X11)
USE_X11_LINKS?=		YES
.  if !empty(USE_X11_LINKS:M[nN][oO])
.    include "../../mk/x11.buildlink2.mk"
.  else
BUILD_DEPENDS+=		x11-links>=0.12:../../pkgtools/x11-links
_BLNK_X11_DIR=		${LOCALBASE}/share/x11-links
.  endif
.  if ${PKG_INSTALLATION_TYPE} == "overwrite"
.    if empty(_BLNK_CPPFLAGS:M-I${X11BASE}/include)
_BLNK_CPPFLAGS+=	-I${X11BASE}/include
.    endif
.    if empty(_BLNK_LDFLAGS:M-L${X11BASE}/lib)
_BLNK_LDFLAGS+=		-L${X11BASE}/lib
.    endif
.  endif
.  if empty(_BLNK_LDFLAGS:M-Wl,${RPATH_FLAG}${X11BASE}/lib)
_BLNK_LDFLAGS+=		-Wl,${RPATH_FLAG}${X11BASE}/lib
.  endif
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
.  if empty(LDFLAGS:M${FLAG})
LDFLAGS+=	${FLAG}
.  endif
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
	${_PKG_SILENT}${_PKG_DEBUG}${CP} -R ${_BLNK_X11_DIR}/* ${BUILDLINK_X11_DIR}
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
.for _target_ in ${BUILDLINK_TARGETS}
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
		if [ -n "${BUILDLINK_PKGBASE.${.TARGET:S/-buildlink//}}" ]; then \
			pkg_prefix=`${PKG_INFO} -qp ${BUILDLINK_PKGBASE.${.TARGET:S/-buildlink//}} | ${AWK} '{ sub("${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}", "", $$2); sub("/", "", $$2); print $$2; exit }'`/; \
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
.elif defined(USE_SUNPRO)
_BLNK_TRANSFORM+=	sanitize-rpath
.endif
_BLNK_TRANSFORM+=	${_BLNK_UNPROTECT}

_BLNK_TRANSFORM_SED+=	-f ${_BLNK_TRANSFORM_SEDFILE}
_BLNK_UNTRANSFORM_SED+=	-f ${_BLNK_UNTRANSFORM_SEDFILE}

_BLNK_CHECK_IS_TEXT_FILE?= \
	${FILE_CMD} $${file} | ${EGREP} "(shell script|text)" >/dev/null 2>&1

# _BUILDLINK_SUBST_USE is a make macro that executes code to do general text
# replacement in files in ${WRKSRC}.  The following variables are used:
#
# BUILDLINK_SUBST_MESSAGE.<package>	message to display, noting what is
#					being substituted
#                                      
# BUILDLINK_SUBST_FILES.<package>	files on which to run the substitution;
#					these are relative to ${WRKSRC}
#
# BUILDLINK_SUBST_SED.<package>		sed(1) substitution expression to run
#					on the specified files.
#
# The _BUILDLINK_SUBST_USE macro code will try to verify that a file is a text
# file before attempting any substitutions.
#
_BUILDLINK_SUBST_USE: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${.TARGET:S/-buildlink-subst//:S/-/_/g}_buildlink_subst_done; \
	if [ ! -f $${cookie} ]; then					\
		${MKDIR} ${BUILDLINK_DIR};				\
		if [ -n "${BUILDLINK_SUBST_SED.${.TARGET:S/-buildlink-subst//}:C/[ 	]//g:Q}" ]; then \
			cd ${WRKSRC};					\
			files="${BUILDLINK_SUBST_FILES.${.TARGET:S/-buildlink-subst//}}"; \
			if [ -n "$${files}" ]; then			\
				${ECHO_BUILDLINK_MSG} ${BUILDLINK_SUBST_MESSAGE.${.TARGET:S/-buildlink-subst//}}; \
				cd ${WRKSRC};				\
				for file in $${files}; do		\
					if ${_BLNK_CHECK_IS_TEXT_FILE}; then \
						${MV} -f $${file} $${file}.blsav; \
						${SED}  ${BUILDLINK_SUBST_SED.${.TARGET:S/-buildlink-subst//}} \
							$${file}.blsav > $${file}; \
						if [ -x $${file}.blsav ]; then \
							${CHMOD} +x $${file}; \
						fi;			\
						if ${CMP} -s $${file}.blsav $${file}; then \
							${MV} -f $${file}.blsav $${file}; \
						else			\
							${ECHO} $${file} >> $${cookie}; \
						fi;			\
					fi;				\
				done;					\
			fi;						\
		fi;							\
	fi

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
# options are removed to optimize the resulting file.
#
REPLACE_BUILDLINK_SED?=		# empty
_REPLACE_BUILDLINK_SED=		${REPLACE_BUILDLINK_SED}
_REPLACE_BUILDLINK_SED+=	${LIBTOOL_ARCHIVE_UNTRANSFORM_SED}

BUILDLINK_SUBST_MESSAGE.unbuildlink= \
	"Fixing buildlink references in files-to-be-installed."
BUILDLINK_SUBST_FILES.unbuildlink=	${_REPLACE_BUILDLINK}
BUILDLINK_SUBST_SED.unbuildlink=	${_REPLACE_BUILDLINK_SED}
BUILDLINK_SUBST_SED.unbuildlink+=	${_BLNK_UNTRANSFORM_SED}

post-build: unbuildlink-buildlink-subst
unbuildlink-buildlink-subst: _BUILDLINK_SUBST_USE

# Fix locale directory references.
#
USE_PKGLOCALEDIR?=		no
_PKGLOCALEDIR=			${PREFIX}/${PKGLOCALEDIR}/locale
REPLACE_LOCALEDIR_PATTERNS?=	# empty
_REPLACE_LOCALEDIR_PATTERNS=	${REPLACE_LOCALEDIR_PATTERNS}
.if defined(HAS_CONFIGURE) || defined(GNU_CONFIGURE)
_REPLACE_LOCALEDIR_PATTERNS+=	Makefile.in*
.else
_REPLACE_LOCALEDIR_PATTERNS+=	Makefile*
.endif
_REPLACE_LOCALEDIR_PATTERNS_FIND= \
	\( ${_REPLACE_LOCALEDIR_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)

REPLACE_LOCALEDIR?=		# empty
_REPLACE_LOCALEDIR= \
	${REPLACE_LOCALEDIR}						\
	`${FIND} . ${_REPLACE_LOCALEDIR_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${GREP} -v '\.orig' | ${SORT} -u`

BUILDLINK_SUBST_MESSAGE.pkglocaledir= \
	"Fixing locale directory references."
BUILDLINK_SUBST_FILES.pkglocaledir= \
	${_REPLACE_LOCALEDIR}
BUILDLINK_SUBST_SED.pkglocaledir= \
	-e 's|^\(localedir[ 	:]*=\).*|\1 ${_PKGLOCALEDIR}|' \
	-e 's|^\(gnulocaledir[ 	:]*=\).*|\1 ${_PKGLOCALEDIR}|' \
	-e 's|\(-DLOCALEDIR[ 	]*=\)[^ 	]*\(.*\)|\1"\\"${_PKGLOCALEDIR}\\""\2|'

.if empty(USE_PKGLOCALEDIR:M[nN][oO])
pre-configure: pkglocaledir-buildlink-subst
.endif
pkglocaledir-buildlink-subst: _BUILDLINK_SUBST_USE

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
_BLNK_WRAP_LOG=			${BUILDLINK_DIR}/.wrapper.log
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
_BLNK_WRAP_SETENV.${_wrappee_}=	${_wrappee_}="${BUILDLINK_${_wrappee_}:T}"
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
_BLNK_WRAPPER_SH.LIBTOOL=	${.CURDIR}/../../mk/buildlink2/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.LIBTOOL=	# empty
#
_BLNK_WRAP_SETENV.SHLIBTOOL=	# empty
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

buildlink-wrappers: ${_BLNK_LIBTOOL_DO_INSTALL}
buildlink-wrappers: ${_BLNK_LIBTOOL_FIX_LA}
buildlink-wrappers: ${_BLNK_FAKE_LA}

.for _wrappee_ in ${_BLNK_WRAPPEES}
CONFIGURE_ENV+=	${_BLNK_WRAP_SETENV.${_wrappee_}}
MAKE_ENV+=	${_BLNK_WRAP_SETENV.${_wrappee_}}

BUILDLINK_${_wrappee_}=	\
	${BUILDLINK_DIR}/bin/${${_wrappee_}:T:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}

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

buildlink-wrappers: ${BUILDLINK_${_wrappee_}}
.if !target(${BUILDLINK_${_wrappee_}})
${BUILDLINK_${_wrappee_}}:						\
		${_BLNK_WRAPPER_SH.${_wrappee_}}			\
		${_BLNK_WRAP_PRIVATE_CACHE.${_wrappee_}}		\
		${_BLNK_WRAP_CACHE.${_wrappee_}}			\
		${_BLNK_WRAP_LOGIC.${_wrappee_}}			\
		${_BLNK_WRAP_POST_LOGIC.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"Creating wrapper: ${.TARGET}"
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
		-e "s|@WRAPPEE@|$${absdir}${${_wrappee_}:Q}|g"		\
		> ${.TARGET};						\
	${CHMOD} +x ${.TARGET}
.endif

.  for _alias_ in ${_ALIASES.${_wrappee_}:S/^/${BUILDLINK_DIR}\/bin\//}
.    if !target(${_alias_})
buildlink-wrappers: ${_alias_}
${_alias_}: ${BUILDLINK_${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG}		\
		"Linking wrapper: ${.TARGET}"
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

# OS-specific overrides for buildlink2 wrappers
#
.if defined(USE_SUNPRO)
_BLNK_WRAPPEES.SunOS?=	CC CXX
SUNWSPROBASE?=		/opt/SUNWspro
CC.SunOS?=		${SUNWSPROBASE}/bin/cc
CXX.SunOS?=		${SUNWSPROBASE}/bin/CC
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
		-e "s|@AWK@|${AWK:Q}|g"					\
		-e "s|@BASENAME@|${BASENAME:Q}|g"			\
		-e "s|@CC@|${BUILDLINK_CC:Q}|g"				\
		-e "s|@CP@|${CP:Q}|g"					\
		-e "s|@DIRNAME@|${DIRNAME:Q}|g"				\
		-e "s|@ECHO@|${ECHO:Q}|g"				\
		-e "s|@EGREP@|${EGREP:Q}|g"				\
		-e "s|@RESET_LD_SO_CACHE@|${_RESET_LD_SO_CACHE:Q}|g"	\
		-e "s|@LIBTOOL@|${BUILDLINK_LIBTOOL:Q}|g"		\
		-e "s|@MKDIR@|${MKDIR:Q}|g"				\
		-e "s|@MV@|${MV:Q}|g"					\
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

# Create shell scripts in ${BUILDLINK_DIR} that simply return an error
# status for each of the GNU auto* tools, which should cause GNU configure
# scripts to think that they can't be found.
#
AUTOMAKE_OVERRIDE?=	yes
_GNU_MISSING=		${.CURDIR}/../../mk/gnu-config/missing
_HIDE_PROGS.autoconf=	bin/autoconf	bin/autoconf-2.13		\
			bin/autoheader	bin/autoheader-2.13		\
			bin/autom4te					\
			bin/autoreconf	bin/autoreconf-2.13		\
			bin/autoscan	bin/autoscan-2.13		\
			bin/autoupdate	bin/autoupdate-2.13		\
			bin/ifnames	bin/ifnames-2.13
_HIDE_PROGS.automake=	bin/aclocal	bin/aclocal-1.4			\
					bin/aclocal-1.5			\
					bin/aclocal-1.6			\
					bin/aclocal-1.7			\
			bin/automake	bin/automake-1.4		\
					bin/automake-1.5		\
					bin/automake-1.6		\
					bin/automake-1.7

.if empty(AUTOMAKE_OVERRIDE:M[nN][oO])
do-buildlink: hide-autotools
.endif

hide-autotools:	# empty

.for _autotool_ in autoconf automake
hide-autotools: hide-${_autotool_}
.  for _prog_ in ${_HIDE_PROGS.${_autotool_}}
hide-${_autotool_}: ${BUILDLINK_DIR}/${_prog_}
${BUILDLINK_DIR}/${_prog_}: ${_GNU_MISSING}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "#!${BUILDLINK_SHELL}" > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "exec ${_GNU_MISSING} ${_prog_:T:C/-[0-9].*$//}" >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  endfor
.endfor

.if defined(USE_NEW_TEXINFO)
# install-info and makeinfo handling.
#
.if defined(INFO_FILES)
# Create an install-info script that is a "no operation" command
# as registration of info files is handled by the INSTALL script.
CONFIGURE_ENV+=	INSTALL_INFO="${BUILDLINK_DIR}/bin/install-info"
MAKE_ENV+=	INSTALL_INFO="${BUILDLINK_DIR}/bin/install-info"

do-buildlink: hide-install-info

hide-install-info: ${BUILDLINK_DIR}/bin/install-info
${BUILDLINK_DIR}/bin/install-info:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "#!${BUILDLINK_SHELL}" > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} '${ECHO} "==> Noop install-info $$*" >> ${_BLNK_WRAP_LOG}' >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}

# Create a makeinfo script that will invoke the right makeinfo
# command if USE_MAKEINFO is 'yes' or invoke the GNU missing script if not.
CONFIGURE_ENV+=	MAKEINFO="${BUILDLINK_DIR}/bin/makeinfo"
MAKE_ENV+=	MAKEINFO="${BUILDLINK_DIR}/bin/makeinfo"

.  if empty(USE_MAKEINFO:M[nN][oO])
do-buildlink: makeinfo-wrapper
makeinfo-wrapper: ${BUILDLINK_DIR}/bin/makeinfo
${BUILDLINK_DIR}/bin/makeinfo:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "#!${BUILDLINK_SHELL}" > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} 'echo "${MAKEINFO} $$*" >> ${_BLNK_WRAP_LOG}' >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} 'exec ${MAKEINFO} "$$@"' >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  else # !USE_MAKEINFO
do-buildlink: hide-makeinfo
hide-makeinfo: ${BUILDLINK_DIR}/bin/makeinfo
${BUILDLINK_DIR}/bin/makeinfo: ${_GNU_MISSING}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "#!${BUILDLINK_SHELL}" > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} '${ECHO} "==> [buildlink2] Error: makeinfo $$*" >> ${_BLNK_WRAP_LOG}' >> ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} 'exit 1' >>  ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  endif # USE_MAKEINFO
.endif # INFO_FILES
.endif # USE_NEW_TEXINFO
