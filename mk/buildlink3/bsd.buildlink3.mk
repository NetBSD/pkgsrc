# $NetBSD: bsd.buildlink3.mk,v 1.1.2.3 2003/08/16 10:15:39 jlam Exp $
#
# Assume PKG_INSTALLATION_TYPE == "pkgviews".

ECHO_BUILDLINK_MSG=	${TRUE}
BUILDLINK_DIR=		${WRKDIR}/.buildlink
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

.if defined(USE_X11)
BUILDLINK_DEPENDS+=		x11-links
BUILDLINK_DEPENDS.x11-links=	x11-links>=0.13
BUILDLINK_DEPMETHOD.x11-links=	build
BUILDLINK_PKGSRCDIR.x11-links=	../../pkgtools/x11-links

X11_LINKS_SUBDIR=		share/x11-links
BUILDLINK_X11_DIR!=							\
	if ${DEPOT_PKG_INFO} -qe "${BUILDLINK_DEPENDS.x11-links}"; then	\
		cd ${DEPOTBASE};					\
		${PKG_ADMIN_CMD} -s "" lsbest "${BUILDLINK_DEPENDS.x11-links}"; \
	else								\
		${ECHO} "${LOCALBASE}/${X11_LINKS_SUBDIR}";		\
	fi
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

# Generate default values for:
#
#	BUILDLINK_PKGBASE.<pkg>
#	BUILDLINK_DEPOT.<pkg>
#	BUILDLINK_INCDIRS.<pkg>
#	BUILDLINK_LIBDIRS.<pkg>
#
# BUILDLINK_PKGBASE.<pkg> is the package basename (without the version
# number).  BUILDLINK_DEPOT.<pkg> is the depot directory for <pkg>.
# BUILDLINK_INCDIRS.<pkg> and BUILDLINK_LIBDIRS.<pkg> are the
# sub-directories in the depot directory for <pkg> that should be added
# to the compiler/linker search paths.
#
.for _pkg_ in ${BUILDLINK_PACKAGES}
.  if !defined(BUILDLINK_PKGBASE.${_pkg_})
BUILDLINK_PKGBASE.${_pkg_}?=	${_pkg_}
.  endif
.  if !defined(BUILDLINK_DEPOT.${_pkg_})
BUILDLINK_DEPOT.${_pkg_}!=						\
	cd ${DEPOTBASE};						\
	${PKG_ADMIN_CMD} -s "" lsbest "${BUILDLINK_DEPENDS.${_pkg_}}"
.  endif
.  if !defined(BUILDLINK_INCDIRS.${_pkg_})
BUILDLINK_INCDIRS.${_pkg_}?=	include
.  endif
.  if !defined(BUILDLINK_LIBDIRS.${_pkg_})
BUILDLINK_LIBDIRS.${_pkg_}?=	lib
.  endif
.endfor

# BUILDLINK_CPPFLAGS and BUILDLINK_LDFLAGS contain the proper -I...
# and -L.../-Wl,-R... options to be passed to the compiler and linker
# to find the headers and libraries for the various packages at
# configure/build time.
#
BUILDLINK_CPPFLAGS=	# empty
BUILDLINK_LDFLAGS=	# empty

.for _pkg_ in ${BUILDLINK_PACKAGES}
.  for _dir_ in ${BUILDLINK_INCDIRS.${_pkg_}}
_dir_:=			${BUILDLINK_DEPOT.${_pkg_}}/${_dir_}
.    if exists(${_dir_})
.      if empty(BUILDLINK_CPPFLAGS:M-I${_dir_})
BUILDLINK_CPPFLAGS+=	-I${_dir_}
.      endif
.    endif
.  endfor
.  for _dir_ in ${BUILDLINK_LIBDIRS.${_pkg_}}
_dir_:=			${BUILDLINK_DEPOT.${_pkg_}}/${_dir_}
.    if exists(${_dir_})
.      if empty(BUILDLINK_LDFLAGS:M-L${_dir_})
BUILDLINK_LDFLAGS+=	-L${_dir_}
.      endif
.      if (${_USE_RPATH} == "yes") && !empty(_COMPILER_LD_FLAG) && \
	  empty(BUILDLINK_LDFLAGS:M${_COMPILER_LD_FLAG}${RPATH_FLAG}${_dir_})
BUILDLINK_LDFLAGS+=		${_COMPILER_LD_FLAG}${RPATH_FLAG}${_dir_}
.      endif
.    endif
.  endfor
.endfor
#
# Add the default view library directory to the runtime library search
# path so that wildcard dependencies on library packages can always be
# fulfilled through the default view.
#
.if (${_USE_RPATH} == "yes") && !empty(_COMPILER_LD_FLAG) && \
    empty(BUILDLINK_LDFLAGS:M${_COMPILER_LD_FLAG}${RPATH_FLAG}${LOCALBASE}/lib)
BUILDLINK_LDFLAGS+=	${_COMPILER_LD_FLAG}${RPATH_FLAG}${LOCALBASE}/lib
.endif
#
# Add the X11 library directory to the runtime library search path if
# the package uses X11.
#
.if defined(USE_X11) && \
    (${_USE_RPATH} == "yes") && !empty(_COMPILER_LD_FLAG) && \
    empty(BUILDLINK_LDFLAGS:M${_COMPILER_LD_FLAG}${RPATH_FLAG}${X11BASE}/lib)
BUILDLINK_LDFLAGS+=	${_COMPILER_LD_FLAG}${RPATH_FLAG}${X11BASE}/lib
.endif

.for _flag_ in ${BUILDLINK_CPPFLAGS}
.  if empty(CFLAGS:M${_flag_})
CFLAGS+=	${_flag_}
.  endif
.  if empty(CXXFLAGS:M${_flag_})
CXXFLAGS+=	${_flag_}
.  endif
.  if empty(CPPFLAGS:M${_flag_})
CPPFLAGS+=	${_flag_}
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
do-buildlink: buildlink-directories
buildlink-directories:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/include
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/lib

# Create the buildlink wrappers before any of the other buildlink targets
# are run, as the wrappers may need to be used in some of those targets.
#
do-buildlink: buildlink-wrappers buildlink-${_BLNK_OPSYS}-wrappers

# If the package Makefile defines BUILDLINK_FILES.<pkg>, then symlink
# the named files into ${BUILDLINK_DIR}.
#
# BUILDLINK_FILES.<pkg>
#	shell glob pattern relative to ${BUILDLINK_DEPOT.<pkg>} to be
#	symlinked into ${BUILDLINK_DIR}, e.g. include/*.h
#
# BUILDLINK_TRANSFORM.<pkg>
#	sed arguments used to transform the name of the source filename
#	into a destination filename, e.g. -e "s|/curses.h|/ncurses.h|g"
#
.for _pkg_ in ${BUILDLINK_PACKAGES}
.  if defined(BUILDLINK_FILES.${_pkg_}) && !empty(BUILDLINK_FILES.${_pkg_})
BUILDLINK_TARGETS+=	${_pkg_}-buildlink
${_pkg_}-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.${_pkg_}_buildlink_done;		\
	if [ ! -f $$cookie ]; then					\
		${ECHO_BUILDLINK_MSG} "Linking ${_pkg_} files into ${BUILDLINK_DIR}."; \
		${MKDIR} ${BUILDLINK_DIR};				\
		cd ${BUILDLINK_DEPOT.${_pkg_}};				\
		for rel_file in ${BUILDLINK_FILES.${_pkg_}}; do		\
			src="${BUILDLINK_DEPOT.${_pkg_}}/$$rel_file";	\
			if [ ! -f $$src ]; then				\
				${ECHO} "$${file}: not found" >> $${cookie}; \
				continue;				\
			fi;						\
			msg="$$src";					\
			dest="${BUILDLINK_DIR}/$$rel_file";		\
			if [ -n "${BUILDLINK_TRANSFORM.${_pkg_}}" ]; then \
				dest=`${ECHO} $$dest | ${SED} ${BUILDLINK_TRANSFORM.${_pkg_}}`; \
				msg="$$src -> $$dest";			\
			fi;						\
			dir=`${DIRNAME} $$dest`;			\
			if [ ! -d $$dir ]; then				\
				${MKDIR} $$dir;				\
			fi;						\
			${LN} -sf $$src $$dest;				\
			${ECHO} "$$msg" >> $$cookie;			\
		done;							\
		${TOUCH} ${TOUCH_FLAGS} $$cookie;			\
	fi
.  endif
.endfor

# Add each of the targets in BUILDLINK_TARGETS as a prerequisite for the
# do-buildlink target.  This ensures that all the buildlink magic happens
# before any configure or build commands are called.
#
.for _target_ in ${BUILDLINK_TARGETS}
do-buildlink: ${_target_}
.endfor

# The configure process usually tests for outlandish or missing things
# that we don't want polluting the argument cache.
#
CONFIGURE_ENV+=		BUILDLINK_UPDATE_CACHE=no

# The caching code, which greatly speeds up the build process, works only
# on certain platforms.
#
_BLNK_SEED_CACHE?=	yes
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
_BLNK_ALLOWED_RPATHDIRS+=	${BUILDLINK_DEPOT.${_pkg_}}
.endfor
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

_BLNK_MANGLE=			_bUiLdLiNk_
.for _dir_ in ${_BLNK_MANGLE_DIRS}
_BLNK_MANGLE_DIR.${_dir_}=	${_BLNK_MANGLE}${_dir_:S/\//_/g}${_BLNK_MANGLE}
.endfor
_BLNK_MANGLE_SED_PATTERN=	${_BLNK_MANGLE}[^/ 	]*${_BLNK_MANGLE}

_BLNK_PROTECT_DIRS=	# empty
_BLNK_UNPROTECT_DIRS=	# empty
_BLNK_PROTECT=		# empty
_BLNK_UNPROTECT=	# empty

_BLNK_PROTECT_DIRS+=	${BUILDLINK_DIR}
_BLNK_PROTECT_DIRS+=	${BUILDLINK_X11_DIR}
_BLNK_PROTECT_DIRS+=	${WRKDIR}
.for _pkg_ in ${BUILDLINK_PACKAGES}
_BLNK_PROTECT_DIRS+=	${BUILDLINK_DEPOT.${_pkg_}}
_BLNK_UNPROTECT_DIRS+=	${BUILDLINK_DEPOT.${_pkg_}}
.endfor
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
# Protect some directories that we allow to be specified for the runtime
# library search path.
#
.for _dir_ in ${_BLNK_ALLOWED_RPATHDIRS}
_BLNK_TRANSFORM+=	rpath:${_dir_}:${_BLNK_MANGLE_DIR.${_dir_}}
.endfor
#
# Convert direct paths to shared libraries into "-Ldir -llib" equivalents.
#
_BLNK_TRANSFORM+=	p:${_BLNK_MANGLE_SED_PATTERN:Q}
_BLNK_TRANSFORM+=	p:
#
# Transform references into ${X11BASE} into ${BUILDLINK_X11_DIR} but if
# the package doesn't use X11, then just remove these references altogether.
#
.if defined(USE_X11)
_BLNK_TRANSFORM+=       I:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
_BLNK_TRANSFORM+=       L:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
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
# Undo the protection so the correct directory names are passed to the
# the wrappee.
#
.for _dir_ in ${_BLNK_UNPROTECT_DIRS}
_BLNK_TRANSFORM+=	mangle:${_BLNK_MANGLE_DIR.${_dir_}}:${_dir_}
.endfor

_BLNK_TRANSFORM_SED+=	-f ${_BLNK_TRANSFORM_SEDFILE}
_BLNK_UNTRANSFORM_SED+=	-f ${_BLNK_UNTRANSFORM_SEDFILE}

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
_BLNK_WRAPPER_SH.${_wrappee_}=	${.CURDIR}/../../mk/buildlink3/wrapper.sh
_BLNK_WRAP_SETENV.${_wrappee_}=	${_wrappee_}="${BUILDLINK_${_wrappee_}:T}"
_BLNK_WRAP_SANITIZE_PATH.${_wrappee_}=		${_BLNK_WRAP_SANITIZE_PATH}
_BLNK_WRAP_EXTRA_FLAGS.${_wrappee_}=		# empty
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
_BLNK_WRAPPER_SH.LIBTOOL=	${.CURDIR}/../../mk/buildlink3/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.LIBTOOL=	# empty
#
_BLNK_WRAP_SETENV.SHLIBTOOL=	# empty
_BLNK_WRAPPER_SH.SHLIBTOOL=	${.CURDIR}/../../mk/buildlink3/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.SHLIBTOOL=	# empty

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
# first.
#
_BLNK_CPPFLAGS=			-I${BUILDLINK_DIR}/include
_BLNK_LDFLAGS=			-L${BUILDLINK_DIR}/lib
_BLNK_WRAP_EXTRA_FLAGS.CC=	${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.CXX=	${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}}
_BLNK_WRAP_EXTRA_FLAGS.CPP=	${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.FC=	${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_BLNK_WRAP_EXTRA_FLAGS.LD=	${_BLNK_LDFLAGS}

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

# OS-specific overrides for buildlink3 wrappers
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

${_BLNK_EMPTY_FILE}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}

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
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
.  endif
.endfor

${_BLNK_WRAP_PRIVATE_POST_CACHE.LD}:					\
		${.CURDIR}/../../mk/buildlink3/ld-post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${_BLNK_WRAP_PRIVATE_POST_CACHE.LIBTOOL}:				\
		${.CURDIR}/../../mk/buildlink3/libtool-post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${_BLNK_WRAP_PRE_CACHE}: ${.CURDIR}/../../mk/buildlink3/pre-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${_BLNK_WRAP_CACHE_ADD}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}

${_BLNK_WRAP_CACHE}:							\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_CACHE_ADD}					\
		${_BLNK_WRAP_POST_CACHE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_CACHE_TRANSFORM}:						\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_CACHE_ADD_TRANSFORM}			\
		${_BLNK_WRAP_POST_CACHE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_POST_CACHE}: ${.CURDIR}/../../mk/buildlink3/post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${_BLNK_WRAP_LOGIC}: ${.CURDIR}/../../mk/buildlink3/logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e 's|@_BLNK_TRANSFORM_SED@||g'				\
		${.ALLSRC} | ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

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

${_BLNK_WRAP_POST_LOGIC.LD}: ${.CURDIR}/../../mk/buildlink3/ld-post-logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${_BLNK_WRAP_POST_LOGIC.LIBTOOL}:					\
		${.CURDIR}/../../mk/buildlink3/libtool-post-logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${_BLNK_LIBTOOL_DO_INSTALL}: ${.CURDIR}/../../mk/buildlink3/libtool-do-install
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}

${_BLNK_LIBTOOL_FIX_LA}:						\
		${.CURDIR}/../../mk/buildlink3/libtool-fix-la		\
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
		-e 's|@_BLNK_UNTRANSFORM_SED@|${_BLNK_UNTRANSFORM_SED:Q}|g' \
		${.CURDIR}/../../mk/buildlink3/libtool-fix-la		\
		| ${_BLNK_SH_CRUNCH_FILTER} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

.if !empty(_BLNK_SEED_CACHE:M[yY][eE][sS])
#
# Seed the transforming cache with obvious values that greatly speed
# up the wrappers:
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
.  for _pkg_ in ${BUILDLINK_PACKAGES}
_BLNK_CACHE_PASSTHRU_GLOB+=	-[IL]${BUILDLINK_DEPOT.${_pkg_}}/*
.  endfor
#
_BLNK_RPATH_FLAGS=	${_COMPILER_LD_FLAG}-R
_BLNK_RPATH_FLAGS+=	${_COMPILER_LD_FLAG}-rpath,
_BLNK_RPATH_FLAGS+=	${_COMPILER_LD_FLAG}-rpath-link,
#
# Allow all subdirs of ${_BLNK_ALLOWED_RPATHDIRS} to be in the runtime
# library search path.
#
.  if ${_USE_RPATH} == "yes"
.    for _dir_ in ${_BLNK_ALLOWED_RPATHDIRS}
_BLNK_CACHE_PASSTHRU_GLOB+=	-R${_dir_}|-R${_dir_}/*
.      if !empty(_COMPILER_LD_FLAG)
.        for _R_ in ${_BLNK_RPATH_FLAGS}
_BLNK_CACHE_PASSTHRU_GLOB+=	${_R_}${_dir_}|${_R_}${_dir_}/*
.        endfor
.      endif	# _COMPILER_LD_FLAG
.    endfor
.  endif	# _USE_RPATH
#
# Block all other absolute paths (we handle the ${X11BASE} case below).
#
_BLNK_CACHE_BLOCK_GLOB=		-[IL]/*
.  if ${_USE_RPATH} == "yes"
_BLNK_CACHE_BLOCK_GLOB:=	${_BLNK_CACHE_BLOCK_GLOB}|-R/*
.    if !empty(_COMPILER_LD_FLAG)
.      for _R_ in ${_BLNK_RPATH_FLAGS}
_BLNK_CACHE_BLOCK_GLOB:=	${_BLNK_CACHE_BLOCK_GLOB}|${_R_}/*
.      endfor
.    endif	# _COMPILER_LD_FLAG
.  endif	# _USE_RPATH
.endif	# _BLNK_SEED_CACHE

${_BLNK_WRAP_CACHE_ADD_TRANSFORM}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${.TARGET}
.if !empty(_BLNK_SEED_CACHE:M[yY][eE][sS])
.  for _glob_ in ${_BLNK_CACHE_PASSTHRU_GLOB}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "${_glob_})";						\
	  ${ECHO} "	cachehit=yes";					\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
.  endfor
.  if defined(USE_X11)
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
.  endif
.  for _glob_ in ${_BLNK_CACHE_BLOCK_GLOB}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} "${_glob_})";						\
	  ${ECHO} "	arg=; cachehit=yes;";				\
	  ${ECHO} "	;;";						\
	) >> ${.TARGET}
.  endfor
.endif	# _BLNK_SEED_CACHE

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
