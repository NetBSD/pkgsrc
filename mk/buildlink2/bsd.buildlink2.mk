# $NetBSD: bsd.buildlink2.mk,v 1.8 2002/09/01 18:38:15 jlam Exp $
#
# An example package buildlink2.mk file:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# BUILDLINK_PACKAGES+=		foo
# BUILDLINK_DEPENDS.foo?=	foo>=1.0
# BUILDLINK_PKGSRCDIR.foo?=	../../category/foo
#
# EVAL_PREFIX+=			BUILDLINK_PREFIX.foo=foo
# BUILDLINK_PREFIX.foo_DEFAULT=	${LOCALBASE}
# BUILDLINK_FILES.foo=		include/foo.h
# BUILDLINK_FILES.foo+=		include/bar.h
# BUILDLINK_FILES.foo+=		lib/libfoo.*
#
# # We need "libbar.*" to look like "libfoo.*".
# BUILDLINK_TRANSFORM+=		l:bar:foo
#
# BUILDLINK_TARGETS+=		foo-buildlink
#
# foo-buildlink: _BUILDLINK_USE
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
BUILDLINK_X11PKG_DIR=	${BUILDLINK_DIR:H}/.buildlink-x11pkg
CONFIGURE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
MAKE_ENV+=		BUILDLINK_DIR="${BUILDLINK_DIR}"
CONFIGURE_ENV+=		BUILDLINK_X11PKG_DIR="${BUILDLINK_X11PKG_DIR}"
MAKE_ENV+=		BUILDLINK_X11PKG_DIR="${BUILDLINK_X11PKG_DIR}"
_BLNK_CPPFLAGS=		-I${LOCALBASE}/include
_BLNK_LDFLAGS=		-L${LOCALBASE}/lib

# The configure process usually tests for outlandish or missing things
# that we don't want polluting the argument cache.
#
CONFIGURE_ENV+=		BUILDLINK_UPDATE_CACHE=no

.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
.  if !defined(_FOR_X11_LINKS_ONLY)
BUILD_DEPENDS+=		x11-links>=0.8:../../pkgtools/x11-links
.  endif
BUILDLINK_X11_DIR=	${LOCALBASE}/share/x11-links
CONFIGURE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"
MAKE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"
_BLNK_CPPFLAGS+=	-I${X11BASE}/include
_BLNK_LDFLAGS+=		-L${X11BASE}/lib
.endif

CFLAGS:=		${_BLNK_CPPFLAGS} ${CFLAGS}
CXXFLAGS:=		${_BLNK_CPPFLAGS} ${CXXFLAGS}
CPPFLAGS:=		${_BLNK_CPPFLAGS} ${CPPFLAGS}
LDFLAGS:=		${_BLNK_LDFLAGS} ${LDFLAGS}

# Prepend ${BUILDLINK_DIR}/bin to the PATH so that the wrappers are found
# first when searching for executables.
#
PATH:=			${BUILDLINK_DIR}/bin:${PATH}

# Add the proper dependency on each package pulled in by buildlink2.mk
# files.  BUILDLINK_DEPMETHOD.<pkg> is either "full" or "build" to represent
# either a full dependency or a build dependency on <pkg>.  By default,
# we use a full dependency.
#
.for _pkg_ in ${BUILDLINK_PACKAGES}
.  if !defined(BUILDLINK_DEPMETHOD.${_pkg_})
BUILDLINK_DEPMETHOD.${_pkg_}=	full
.  endif
.  if (${BUILDLINK_DEPMETHOD.${_pkg_}} == "full")
_BUILDLINK_DEPMETHOD.${_pkg_}=	DEPENDS
.  elif (${BUILDLINK_DEPMETHOD.${_pkg_}} == "build")
_BUILDLINK_DEPMETHOD.${_pkg_}=	BUILD_DEPENDS
.  endif
.  if defined(BUILDLINK_DEPENDS.${_pkg_}) && \
      defined(BUILDLINK_PKGSRCDIR.${_pkg_})
${_BUILDLINK_DEPMETHOD.${_pkg_}}+= \
	${BUILDLINK_DEPENDS.${_pkg_}}:${BUILDLINK_PKGSRCDIR.${_pkg_}}
.  endif
.endfor

# Create the buildlink include and lib directories so that the Darwin
# compiler/linker won't complain verbosely (on stdout, even!) when
# those directories are passed as sub-arguments of -I and -L.
#
do-buildlink: buildlink-directories
buildlink-directories:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/include
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${BUILDLINK_DIR}/lib

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
	-e "s|${LOCALBASE}\(/lib/[^ 	]*\.la\)|${BUILDLINK_DIR}\1|g"	\
	-e "s|${X11BASE}\(/lib/[^ 	]*\.la\)|${BUILDLINK_DIR}\1|g"

_LT_ARCHIVE_TRANSFORM=							\
	${SED} ${_LT_ARCHIVE_TRANSFORM_SED} $${file} > $${dest}

# _BUILDLINK_USE is a macro target that symlinks package files into a new
# hierarchy under ${BUILDLINK_DIR}.
#
# The variables required to be defined to use this target are listed
# below.  <pkgname> refers to the name of the package and should be used
# consistently.
#
# The target that uses this macro target should perform no other actions
# and be named "<pkgname>-buildlink".
#
# BUILDLINK_PREFIX.<pkgname>    installation prefix of the package
#
# BUILDLINK_FILES.<pkgname>     files relative to ${BUILDLINK_PREFIX.<pkgname>}
#                               to be symlinked into ${BUILDLINK_DIR};
#                               libtool archive files are automatically
#                               filtered out and not linked
#
# BUILDLINK_TARGETS             targets to be invoked during buildlink;
#                               the targets should be appended to this variable
#                               using +=
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
			${RM} -f ${BUILDLINK_X11PKG_DIR} 2>/dev/null;	\
			${LN} -sf ${BUILDLINK_DIR} ${BUILDLINK_X11PKG_DIR}; \
			buildlink_dir="${BUILDLINK_X11PKG_DIR}";		\
			;;						\
		*)							\
			buildlink_dir="${BUILDLINK_DIR}";		\
			;;						\
		esac;							\
		files="${BUILDLINK_FILES.${.TARGET:S/-buildlink//}:S/^/${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}\//g}"; \
		for file in $${files}; do				\
			rel_file=`${ECHO} $${file} | ${SED} -e "s|${BUILDLINK_PREFIX.${.TARGET:S/-buildlink//}}/||"`; \
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

do-buildlink: buildlink-wrappers

# _BLNK_TRANSFORM mini language for translating wrapper arguments into
#	their buildlink equivalents:
#
#	I:src:dst		translates "-Isrc" into "-Idst"
#	II:src:dst1,dst2	translates "-Isrc" into "-Idst1 -Idst2"
#	L:src:dst		translates "-Lsrc" into "-Ldst"
#	LL:src:dst1,dst2	translates "-Lsrc" into "-Ldst1 -Ldst2"
#	l:foo:bar		translates "-lfoo" into "-lbar"
#	r:dir			removes "dir" and "dir/*"
#
_BLNK_TRANSFORM+=	I:${LOCALBASE}:${BUILDLINK_DIR}
_BLNK_TRANSFORM+=	L:${LOCALBASE}:${BUILDLINK_DIR}
_BLNK_TRANSFORM+=	${BUILDLINK_TRANSFORM}
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_BLNK_TRANSFORM+=	II:${X11BASE}:${BUILDLINK_X11PKG_DIR},${BUILDLINK_X11_DIR}
_BLNK_TRANSFORM+=	LL:${X11BASE}:${BUILDLINK_X11PKG_DIR},${BUILDLINK_X11_DIR}
.endif
.if ${LOCALBASE} != "/usr/pkg"
_BLNK_TRANSFORM+=	r:-I/usr/pkg
_BLNK_TRANSFORM+=	r:-L/usr/pkg
.endif
.if ${LOCALBASE} != "/usr/local"
_BLNK_TRANSFORM+=	r:-I/usr/local
_BLNK_TRANSFORM+=	r:-L/usr/local
.endif
#
# Create _BLNK_TRANSFORM_SED.{1,2,3} from _BLNK_TRANSFORM.  We must use
# separate variables instead of just one because the contents are too long
# for one variable when we substitute into a shell script later on.
#
# Change "/usr/pkg/lib/libfoo.so"   into "-L/usr/pkg/lib -lfoo" and
#        "/usr/X11R6/lib/libbar.so" into "-L/usr/X11R6/lib -lbar".
#
_BLNK_TRANSFORM_SED.1+= \
	-e "s|\(${LOCALBASE}/[^	 ]*\)/lib\([^	 ]*\)\.a|-L\1 -l\2|g"	\
	-e "s|\(${LOCALBASE}/[^	 ]*\)/lib\([^	 ]*\)\.so|-L\1 -l\2|g"
_BLNK_TRANSFORM_SED.1+= \
	-e "s|\(${X11BASE}/[^	 ]*\)/lib\([^	 ]*\)\.a|-L\1 -l\2|g"	\
	-e "s|\(${X11BASE}/[^	 ]*\)/lib\([^	 ]*\)\.so|-L\1 -l\2|g"
#
# Transform "I:/usr/pkg:/buildlink" into:
#	-e "s|-I/usr/pkg |-I/buildlink |g"
#	-e "s|-I/usr/pkg$|-I/buildlink|g"
#	-e "s|-I/usr/pkg/\([^	 ]*\)|-I/buildlink/\1|g"
#
.for _transform_ in ${_BLNK_TRANSFORM:MI\:*\:*}
_BLNK_TRANSFORM_SED.2+= \
	-e "s|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\1/} |-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\2/} |g" \
	-e "s|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\1/}$$|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\2/}|g" \
	-e "s|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\1/}/\([^	 ]*\)|-I${_transform_:C/^I\:([^\:]*)\:([^\:]*)$/\2/}/\1|g"
.endfor
#
# Transform "II:/usr/X11R6:/buildlink,/x11-links" into:
#	-e "s|-I/usr/X11R6 |-I/buildlink -I/x11-links |g"
#	-e "s|-I/usr/X11R6$|-I/buildlink -I/x11-links|g"
#	-e "s|-I/usr/X11R6/\([^	 ]*\)|-I/buildlink/\1 -I/x11-links/\1|g"
#
.for _transform_ in ${_BLNK_TRANSFORM:MII\:*\:*,*}
_BLNK_TRANSFORM_SED.2+= \
	-e "s|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/} |g" \
	-e "s|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}$$|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}|g" \
	-e "s|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\([^	 ]*\)|-I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}/\1 -I${_transform_:C/^II\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}/\1|g"
.endfor
#
# Transform "L:/usr/pkg:/buildlink" into:
#	-e "s|-L/usr/pkg |-L/buildlink |g"
#	-e "s|-L/usr/pkg$|-L/buildlink|g"
#	-e "s|-L/usr/pkg/\([^	 ]*\)|-L/buildlink/\1|g"
#
.for _transform_ in ${_BLNK_TRANSFORM:ML\:*\:*}
_BLNK_TRANSFORM_SED.2+= \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/} |-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/} |g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}$$|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}|g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}/\([^	 ]*\)|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}/\1|g"
_BLNK_UNTRANSFORM_SED.2+= \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/} |-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/} |g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}$$|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}|g" \
	-e "s|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\2/}/\([^	 ]*\)|-L${_transform_:C/^L\:([^\:]*)\:([^\:]*)$/\1/}/\1|g"
.endfor
#
# Transform "LL:/usr/X11R6:/buildlink,/x11-links" into:
#	-e "s|-L/usr/X11R6 |-L/buildlink -L/x11-links |g"
#	-e "s|-L/usr/X11R6$|-L/buildlink -L/x11-links|g"
#	-e "s|-L/usr/X11R6/\([^  ]*\)|-L/buildlink/\1 -L/x11-links/\1|g"
#
.for _transform_ in ${_BLNK_TRANSFORM:MLL\:*\:*,*}
_BLNK_TRANSFORM_SED.2+= \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/} |g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}$$|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} -L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\([^	 ]*\)|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}/\1 -L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}/\1|g"
_BLNK_UNTRANSFORM_SED.2+= \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/} |-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/} |-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/} |g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}$$|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}$$|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\2/}/\([^	 ]*\)|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\1|g" \
	-e "s|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\3/}/\([^	 ]*\)|-L${_transform_:C/^LL\:([^\:]*)\:([^\:]*),([^\:]*)$/\1/}/\1|g"
.endfor
#
# Transform "l:foo:bar" into:
#	-e "s|-lfoo |-lbar |g"
#	-e "s|-lfoo$|-lbar|g"
#
.for _transform_ in ${_BLNK_TRANSFORM:Ml\:*}
_BLNK_TRANSFORM_SED.2+= \
	-e "s|-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\1/} |-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\2/} |g" \
	-e "s|-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\1/}$$|-l${_transform_:C/^l\:([^\:]*)\:([^\:]*)$/\2/}|g"
.endfor
#
# Fix up references to the x11-links directory.
#
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_BLNK_TRANSFORM_SED.3+= \
	-e "s|${BUILDLINK_DIR}/\(${BUILDLINK_X11_DIR:S/^${LOCALBASE}\///}\)|${LOCALBASE}/\1|g"
.endif
#
# Transform "r:-I/usr/local" into:
#	-e "s|-I/usr/local ||g"
#	-e "s|-I/usr/local$||g"
#	-e "s|-I/usr/local/\([^	 ]*\)||g"
#
.for _transform_ in ${_BLNK_TRANSFORM:Mr\:*}
_BLNK_TRANSFORM_SED.3+= \
	-e "s|${_transform_:S/^r://} ||g"				\
	-e "s|${_transform_:S/^r://}$$||g"				\
	-e "s|${_transform_:S/^r://}/[^	 ]*||g"
.endfor
#
# Explicitly remove "-I/usr/include" and "-L/usr/lib" as they're redundant.
#
_BLNK_TRANSFORM_SED.3+= \
	-e "s|-I/usr/include ||g"					\
	-e "s|-I/usr/include$$||g"					\
	-e "s|-L/usr/lib ||g"						\
	-e "s|-L/usr/lib$$||g"

# Generate wrapper scripts for the compiler tools that sanitize the
# argument list by converting references to ${LOCALBASE} and ${X11BASE}
# into references to ${BUILDLINK_DIR}, ${BUILDLINK_X11PKG_DIR}, and
# ${BUILDLINK_X11_DIR}.  These wrapper scripts are to be used instead of
# the actual compiler tools when building software.
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
.endif
_BLNK_WRAPPEES+=	LIBTOOL
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
IMAKE?=			${X11BASE}/bin/imake
_BLNK_WRAPPEES+=	IMAKE
.endif
_ALIASES.AS=		as
_ALIASES.CC=		cc gcc
_ALIASES.CXX=		c++ g++
_ALIASES.CPP=		cpp
_ALIASES.FC=		f77 g77
_ALIASES.LD=		ld

# On Darwin, protect against using /bin/sh if it's zsh.
.if ${OPSYS} == "Darwin"
.  if exists(/bin/bash)
BUILDLINK_SHELL?=	/bin/bash
.  else
BUILD_DEPENDS+=		bash-[0-9]*:../../shells/bash2
BUILDLINK_SHELL?=	${LOCALBASE}/bin/bash
.  endif
.else
BUILDLINK_SHELL?=	${SH}
.endif

# _BLNK_WRAP_*.<wrappee> variables represent "template methods" of the

# wrapper script that may be customized per wrapper:
#
# _BLNK_WRAP_ENV.<wrappee> resets the value of CC, CPP, etc. in the
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
# _BLNK_WRAP_SANITIZE_PATH.<wrappee> sets the PATH for calling executables
#	from within the wrapper.  By default, it removes the buildlink
#	directory from the PATH so that sub-invocations of compiler tools
#	will use the wrappees instead of the wrappers.
#
_BLNK_SANITIZED_PATH!=	${ECHO} ${PATH} | ${SED}			\
	-e "s|:${BUILDLINK_DIR}[^:]*||" -e "s|${BUILDLINK_DIR}[^:]*:||"
_BLNK_WRAP_SANITIZE_PATH=		PATH="${_BLNK_SANITIZED_PATH}"
_BLNK_WRAP_PRE_CACHE=			${BUILDLINK_DIR}/bin/.pre-cache
_BLNK_WRAP_POST_CACHE=			${BUILDLINK_DIR}/bin/.post-cache
_BLNK_WRAP_CACHE=			${BUILDLINK_DIR}/bin/.cache
_BLNK_WRAP_LOGIC=			${BUILDLINK_DIR}/bin/.logic
_BLNK_WRAP_POST_CACHE_TRANSFORM=	${BUILDLINK_DIR}/bin/.post-cache-trans
_BLNK_WRAP_CACHE_TRANSFORM=		${BUILDLINK_DIR}/bin/.cache-trans
_BLNK_WRAP_LOGIC_TRANSFORM=		${BUILDLINK_DIR}/bin/.logic-trans
_BLNK_WRAP_LOG=				${BUILDLINK_DIR}/.wrapper.log
_BLNK_LIBTOOL_FIX_LA=			${BUILDLINK_DIR}/bin/.libtool-fix-la

.for _wrappee_ in ${_BLNK_WRAPPEES}
#
# _BLNK_WRAPPER_SH.<wrappee> points to the main wrapper script used to
#	generate the wrapper for the wrappee.
#
_BLNK_WRAPPER_SH.${_wrappee_}=	${.CURDIR}/../../mk/buildlink2/wrapper.sh
_BLNK_WRAP_ENV.${_wrappee_}=	${_wrappee_}="${BUILDLINK_${_wrappee_}:T}"
_BLNK_WRAP_SANITIZE_PATH.${_wrappee_}=	${_BLNK_WRAP_SANITIZE_PATH}
_BLNK_WRAP_PRE_CACHE.${_wrappee_}=	${_BLNK_WRAP_PRE_CACHE}
_BLNK_WRAP_POST_CACHE.${_wrappee_}=	${_BLNK_WRAP_POST_CACHE_TRANSFORM}
_BLNK_WRAP_CACHE.${_wrappee_}=		${_BLNK_WRAP_CACHE_TRANSFORM}
_BLNK_WRAP_LOGIC.${_wrappee_}=		${_BLNK_WRAP_LOGIC_TRANSFORM}
.endfor

# Don't bother adding AS, CPP to the configure or make environments as
# adding them seems to break some GNU configure scripts.
#
_BLNK_WRAP_ENV.AS=		# empty
_BLNK_WRAP_ENV.CPP=		# empty

# Also override any F77 value in the environment when compiling Fortran
# code.
#
_BLNK_WRAP_ENV.FC+=		F77="${BUILDLINK_FC:T}"

# Don't override the default LIBTOOL setting in the environment, as
# it already correctly points to ${PKGLIBTOOL}, and don't sanitize the PATH
# because we want libtool to invoke the wrapper scripts, too.
#
_BLNK_WRAP_ENV.LIBTOOL=		# empty
_BLNK_WRAPPER_SH.LIBTOOL=	${.CURDIR}/../../mk/buildlink2/libtool.sh
_BLNK_WRAP_SANITIZE_PATH.LIBTOOL=	# empty

# In the libtool archives, we must remove references to the buildlink
# directories and change any -llib to the proper replacement libraries
# (-lreadline -> -ledit, etc.).  Redundant -Ldir options are removed to
# optimize the resulting libtool archives.
#
_BLNK_WRAP_LT_UNTRANSFORM_SED=	${LIBTOOL_ARCHIVE_UNTRANSFORM_SED}
_BLNK_WRAP_LT_UNTRANSFORM_SED+=	${_BLNK_UNTRANSFORM_SED.1}
_BLNK_WRAP_LT_UNTRANSFORM_SED+=	${_BLNK_UNTRANSFORM_SED.2}
_BLNK_WRAP_LT_UNTRANSFORM_SED+=	${_BLNK_UNTRANSFORM_SED.3}
_BLNK_WRAP_LT_UNTRANSFORM_SED+=	-e "s|-L/usr/lib ||g"
_BLNK_WRAP_LT_UNTRANSFORM_SED+=	-e "s|-L/usr/lib$$||g"

# Don't transform the arguments for imake, which uses the C preprocessor
# to generate Makefiles, so that imake will find its config files.
#
.if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_BLNK_WRAP_PRE_CACHE.IMAKE=	${_BLNK_WRAP_PRE_CACHE}
_BLNK_WRAP_POST_CACHE.IMAKE=	${_BLNK_WRAP_POST_CACHE}
_BLNK_WRAP_CACHE.IMAKE=		${_BLNK_WRAP_CACHE}
_BLNK_WRAP_LOGIC.IMAKE=		${_BLNK_WRAP_LOGIC}
.endif

buildlink-wrappers: ${_BLNK_WRAP_CACHE}
buildlink-wrappers: ${_BLNK_WRAP_CACHE_TRANSFORM}
buildlink-wrappers: ${_BLNK_WRAP_LOGIC}
buildlink-wrappers: ${_BLNK_WRAP_LOGIC_TRANSFORM}
buildlink-wrappers: ${_BLNK_LIBTOOL_FIX_LA}

.for _wrappee_ in ${_BLNK_WRAPPEES}
CONFIGURE_ENV+=	${_BLNK_WRAP_ENV.${_wrappee_}}
MAKE_ENV+=	${_BLNK_WRAP_ENV.${_wrappee_}}

BUILDLINK_${_wrappee_}=	\
	${BUILDLINK_DIR}/bin/${${_wrappee_}:T:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}

buildlink-wrappers: ${BUILDLINK_${_wrappee_}}
.if !target(${BUILDLINK_${_wrappee_}})
${BUILDLINK_${_wrappee_}}:						\
		${_BLNK_WRAPPER_SH.${_wrappee_}}			\
		${_BLNK_WRAP_PRE_CACHE.${_wrappee_}}			\
		${_BLNK_WRAP_POST_CACHE.${_wrappee_}}
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
			*)	if [ -x $${dir}/$${wrappee} ]; then	\
					absdir=$${dir}/;		\
					wrappee=$${absdir}$${wrappee};	\
					break;				\
				fi;					\
				;;					\
			esac;						\
		done;							\
		IFS="$$OLDIFS";						\
		if [ ! -x "$${wrappee}" ]; then				\
			${ECHO_BUILDLINK_MSG} "$${wrappee}: No such file";	\
			exit 1;						\
		fi;							\
		;;							\
	esac;								\
	${MKDIR} ${.TARGET:H};						\
	${CAT} ${_BLNK_WRAPPER_SH.${_wrappee_}}	|			\
		${SED}	-e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"	\
			-e "s|@BUILDLINK_SHELL@|${BUILDLINK_SHELL}|g"	\
			-e "s|@CAT@|${CAT:Q}|g"				\
			-e "s|@ECHO@|${ECHO:Q}|g"			\
			-e "s|@SED@|${SED:Q}|g"				\
			-e "s|@TOUCH@|${TOUCH:Q}|g"			\
			-e "s|@WRAPPEE@|$${absdir}${${_wrappee_}:Q}|g"	\
			-e "s|@_BLNK_LIBTOOL_FIX_LA@|${_BLNK_LIBTOOL_FIX_LA:Q}|g" \
			-e "s|@_BLNK_WRAP_LOG@|${_BLNK_WRAP_LOG:Q}|g"	\
			-e "s|@_BLNK_WRAP_PRE_CACHE@|${_BLNK_WRAP_PRE_CACHE.${_wrappee_}:Q}|g" \
			-e "s|@_BLNK_WRAP_POST_CACHE@|${_BLNK_WRAP_POST_CACHE.${_wrappee_}:Q}|g" \
			-e "s|@_BLNK_WRAP_CACHE@|${_BLNK_WRAP_CACHE.${_wrappee_}:Q}|g" \
			-e "s|@_BLNK_WRAP_LOGIC@|${_BLNK_WRAP_LOGIC.${_wrappee_}:Q}|g" \
			-e "s|@_BLNK_WRAP_SANITIZE_PATH@|${_BLNK_WRAP_SANITIZE_PATH.${_wrappee_}:Q}|g" \
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

${_BLNK_WRAP_PRE_CACHE}: ${.CURDIR}/../../mk/buildlink2/pre-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@WRKDIR@|${WRKDIR}|g"				\
		-e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"		\
		-e "s|@BUILDLINK_X11_DIR@|${BUILDLINK_X11_DIR}|g"	\
		-e "s|@BUILDLINK_X11PKG_DIR@|${BUILDLINK_X11PKG_DIR}|g"		\
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_POST_CACHE}: ${.CURDIR}/../../mk/buildlink2/post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e 's|@ECHO@|${ECHO}|g'					\
		-e 's|@_BLNK_TRANSFORM_SED.1@||g'			\
		-e 's|@_BLNK_TRANSFORM_SED.2@||g'			\
		-e 's|@_BLNK_TRANSFORM_SED.3@||g'			\
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_POST_CACHE_TRANSFORM}: ${.CURDIR}/../../mk/buildlink2/post-cache
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e 's|@ECHO@|${ECHO}|g'					\
		-e 's|@_BLNK_TRANSFORM_SED.1@|${_BLNK_TRANSFORM_SED.1:Q}|g' \
		-e 's|@_BLNK_TRANSFORM_SED.2@|${_BLNK_TRANSFORM_SED.2:Q}|g' \
		-e 's|@_BLNK_TRANSFORM_SED.3@|${_BLNK_TRANSFORM_SED.3:Q}|g' \
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

${_BLNK_WRAP_CACHE}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}

${_BLNK_WRAP_CACHE_TRANSFORM}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}

${_BLNK_WRAP_LOGIC}:							\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_POST_CACHE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} > ${.TARGET}

${_BLNK_WRAP_LOGIC_TRANSFORM}:						\
		${_BLNK_WRAP_PRE_CACHE}					\
		${_BLNK_WRAP_POST_CACHE_TRANSFORM}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC} > ${.TARGET}

${_BLNK_LIBTOOL_FIX_LA}: ${.CURDIR}/../../mk/buildlink2/libtool-fix-la
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${SED}				\
		-e "s|@BASENAME@|${BASENAME:Q}|g"			\
		-e "s|@CAT@|${CAT:Q}|g"					\
		-e "s|@CP@|${CP:Q}|g"					\
		-e "s|@DIRNAME@|${DIRNAME:Q}|g"				\
		-e "s|@ECHO@|${ECHO:Q}|g"				\
		-e "s|@MV@|${MV:Q}|g"					\
		-e "s|@RM@|${RM:Q}|g"					\
		-e "s|@SED@|${SED:Q}|g"					\
		-e "s|@TOUCH@|${TOUCH:Q}|g"				\
		-e 's|@_BLNK_WRAP_LT_UNTRANSFORM_SED@|${_BLNK_WRAP_LT_UNTRANSFORM_SED:Q}|g' \
		${.ALLSRC} > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}

clear-buildlink-cache: remove-buildlink-cache buildlink-wrappers

remove-buildlink-cache:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${_BLNK_WRAP_CACHE_TRANSFORM}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${_BLNK_WRAP_LOGIC_TRANSFORM}

_BLNK_CHECK_PATTERNS+=	-e "-I${LOCALBASE}/[a-rt-z]"
_BLNK_CHECK_PATTERNS+=	-e "-L${LOCALBASE}/[a-rt-z]"
_BLNK_CHECK_PATTERNS+=	-e "-I${X11BASE}/"
_BLNK_CHECK_PATTERNS+=	-e "-L${X11BASE}/"

buildlink-check:
	@if [ -f ${_BLNK_WRAP_LOG} ]; then				\
		${GREP} ${_BLNK_CHECK_PATTERNS} ${_BLNK_WRAP_LOG} || ${TRUE}; \
	fi
