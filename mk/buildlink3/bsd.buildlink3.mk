# $NetBSD: bsd.buildlink3.mk,v 1.215 2012/09/16 07:37:10 sbd Exp $
#
# Copyright (c) 2004 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

# An example package buildlink3.mk file:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# BUILDLINK_TREE+=	foo
#
# .if !defined(FOO_BUILDLINK3_MK)
# FOO_BUILDLINK3_MK:=
#
# BUILDLINK_API_DEPENDS.foo+=	foo-lib>=1.0
# BUILDLINK_ABI_DEPENDS.foo?=	foo-lib>=1.0nb1
# BUILDLINK_PKGSRCDIR.foo?=	../../category/foo-lib
#
# # We want "-lbar" to eventually resolve to "-lfoo".
# BUILDLINK_TRANSFORM+=		l:bar:foo
#
# .include "../../category/baz/buildlink3.mk"
# .endif  # FOO_BUILDLINK3_MK
#
# BUILDLINK_TREE+=	-foo
# -------------8<-------------8<-------------8<-------------8<-------------
#
# Most of the buildlink3.mk file is protected against multiple inclusion,
# except for the parts related to manipulating BUILDLINK_TREE.
#
# Note that if a buildlink3.mk file is included, then the package Makefile
# has the expectation that it can use the value of BUILDLINK_PREFIX.<pkg>.
# If the buildlink3.mk tries to handle dependencies satisfied directly by
# the base system, then it should provide an appropriate value for
# BUILDLINK_PREFIX.<pkg> for that case.  The case where a dependency is
# satisfied by a pkgsrc-installed package is handled automatically by this
# file.
#
# The different variables that may be set in a buildlink3.mk file are
# described below.
#
# The variable name convention used in this Makefile are:
#
# BUILDLINK_*	public buildlink-related variables usable in other Makefiles
# _BLNK_*	private buildlink-related variables to this Makefile

.if ${PKG_DEBUG_LEVEL} > 0
ECHO_BUILDLINK_MSG?=	${ECHO}
.else
ECHO_BUILDLINK_MSG?=	${ECHO_WRAPPER_MSG}
.endif
BUILDLINK_DIR=		${WRKDIR}/.buildlink
BUILDLINK_BINDIR=	${BUILDLINK_DIR}/bin
BUILDLINK_SRCDIR=	${.CURDIR}/../../mk/buildlink3
.if ${X11_TYPE} == "modular"
BUILDLINK_X11_DIR=	${BUILDLINK_DIR}
.else
BUILDLINK_X11_DIR=	${BUILDLINK_DIR:H}/.x11-buildlink
.endif

.PHONY: do-buildlink

# Prepend ${BUILDLINK_BINDIR} to the PATH.
PREPEND_PATH+=	${BUILDLINK_BINDIR}

# _BUILDLINK_DEPENDS contains the list of packages for which we add
# dependencies.  This is only done for direct dependencies.
#
_BUILDLINK_DEPENDS:=
_BUILDLINK_DEPTH:=
.for _pkg_ in ${BUILDLINK_TREE}
_BUILDLINK_pkg:=	${_pkg_:N-*}
.  if empty(_BUILDLINK_pkg)
_BUILDLINK_DEPTH:=	${_BUILDLINK_DEPTH:S/+$//}
.  else
.    if empty(_BUILDLINK_DEPTH)
_BUILDLINK_DEPENDS+=	${_pkg_}
.    endif
_BUILDLINK_DEPTH:=	${_BUILDLINK_DEPTH}+
.  endif
.endfor

# For each package we use, check whether we are using the built-in
# version of the package or if we are using the pkgsrc version.
#
.for _pkg_ in ${BUILDLINK_TREE:N-*}
.if !defined(_BUILDLINK_BUILTIN_MK_INCLUDED.${_pkg_})
_BUILDLINK_BUILTIN_MK_INCLUDED.${_pkg_}=
BUILDLINK_BUILTIN_MK.${_pkg_}?=	${BUILDLINK_PKGSRCDIR.${_pkg_}}/builtin.mk
.  sinclude "${BUILDLINK_BUILTIN_MK.${_pkg_}}"
.endif
.endfor

# Sorted and unified version of BUILDLINK_TREE without recursion
# data.
_BUILDLINK_TREE:=	${BUILDLINK_TREE:N-*:O:u}

# Set IGNORE_PKG.<pkg> if <pkg> is the current package we're building.
# We can then check for this value to avoid build loops.
#
.for _pkg_ in ${_BUILDLINK_TREE}
.  if defined(BUILDLINK_PKGSRCDIR.${_pkg_})
.    if !defined(IGNORE_PKG.${_pkg_}) && \
        (${BUILDLINK_PKGSRCDIR.${_pkg_}:C|.*/([^/]*/[^/]*)$|\1|} == ${PKGPATH})
IGNORE_PKG.${_pkg_}=	yes
MAKEFLAGS+=		IGNORE_PKG.${_pkg_}=${IGNORE_PKG.${_pkg_}}
.    endif
.  endif
.endfor

# _BLNK_PACKAGES contains all of the unique elements of BUILDLINK_TREE
# that shouldn't be skipped.
#
# This does not use _BUILDLINK_TREE as the order matters.  x11-links is
# sorted first to allow other packages to override the content.
#
_BLNK_PACKAGES=		# empty
.for _pkg_ in ${BUILDLINK_TREE:N-*:Mx11-links} ${BUILDLINK_TREE:N-*:Nx11-links}
.  if empty(_BLNK_PACKAGES:M${_pkg_}) && !defined(IGNORE_PKG.${_pkg_})
_BLNK_PACKAGES+=	${_pkg_}
.  endif
.endfor

_VARGROUPS+=		bl3
.for v in BINDIR CFLAGS CPPFLAGS DEPENDS LDFLAGS LIBS
_SYS_VARS.bl3+=		BUILDLINK_${v}
.endfor
.for p in ${_BUILDLINK_TREE}
.  for v in AUTO_VARS BUILTIN_MK CONTENTS_FILTER CPPFLAGS DEPMETHOD FILES_CMD INCDIRS IS_DEPOT LDFLAGS LIBDIRS PKGNAME PREFIX RPATHDIRS
_SYS_VARS.bl3+=		BUILDLINK_${v}.${p}
.  endfor
.  for v in IGNORE_PKG USE_BUILTIN
_SYS_VARS.bl3+=		${v}.${p}
.  endfor
.endfor

# By default, every package receives a full dependency.
.for _pkg_ in ${_BLNK_PACKAGES}
BUILDLINK_DEPMETHOD.${_pkg_}?=	full
.endfor

# _BLNK_DEPENDS contains all of the elements of _BLNK_PACKAGES for which
# we must add a dependency.  We add a dependency if we aren't using the
# built-in version of the package, and the package was either explicitly
# requested as a dependency (_BUILDLINK_DEPENDS) or is a build dependency
# somewhere in the chain.
#
_BLNK_DEPENDS=	# empty
.for _pkg_ in ${_BLNK_PACKAGES}
USE_BUILTIN.${_pkg_}?=	no
.  if empty(_BLNK_DEPENDS:M${_pkg_}) && !defined(IGNORE_PKG.${_pkg_}) && \
      !empty(USE_BUILTIN.${_pkg_}:M[nN][oO]) && \
      (!empty(_BUILDLINK_DEPENDS:M${_pkg_}) || \
       !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mbuild))
_BLNK_DEPENDS+=	${_pkg_}
.  endif
.endfor

# Add the proper dependency on each package pulled in by buildlink3.mk
# files.  BUILDLINK_DEPMETHOD.<pkg> contains a list of either "full" or
# "build", and if any of that list is "full" then we use a full dependency
# on <pkg>, otherwise we use a build dependency on <pkg>.
#
_BLNK_ADD_TO.DEPENDS=		# empty
_BLNK_ADD_TO.BUILD_DEPENDS=	# empty
_BLNK_ADD_TO.ABI_DEPENDS=	# empty
_BLNK_ADD_TO.BUILD_ABI_DEPENDS=	# empty
.for _pkg_ in ${_BLNK_DEPENDS}
.  if !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mfull)
_BLNK_DEPMETHOD.${_pkg_}=	_BLNK_ADD_TO.DEPENDS
_BLNK_ABIMETHOD.${_pkg_}=	_BLNK_ADD_TO.ABI_DEPENDS
.  elif !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mbuild)
_BLNK_DEPMETHOD.${_pkg_}=	_BLNK_ADD_TO.BUILD_DEPENDS
_BLNK_ABIMETHOD.${_pkg_}=	_BLNK_ADD_TO.BUILD_ABI_DEPENDS
.  endif
.  if defined(BUILDLINK_API_DEPENDS.${_pkg_}) && \
      defined(BUILDLINK_PKGSRCDIR.${_pkg_})
.    for _depend_ in ${BUILDLINK_API_DEPENDS.${_pkg_}}
.      if empty(${_BLNK_DEPMETHOD.${_pkg_}}:M${_depend_}\:*)
${_BLNK_DEPMETHOD.${_pkg_}}+=	${_depend_}:${BUILDLINK_PKGSRCDIR.${_pkg_}}
.      endif
.    endfor
.  endif
.  if defined(BUILDLINK_ABI_DEPENDS.${_pkg_}) && \
      defined(BUILDLINK_PKGSRCDIR.${_pkg_})
.    for _abi_ in ${BUILDLINK_ABI_DEPENDS.${_pkg_}}
.      if empty(${_BLNK_ABIMETHOD.${_pkg_}}:M${_abi_}\:*)
${_BLNK_ABIMETHOD.${_pkg_}}+=	${_abi_}:${BUILDLINK_PKGSRCDIR.${_pkg_}}
.      endif
.    endfor
.  endif
.endfor
.for _depmethod_ in DEPENDS BUILD_DEPENDS ABI_DEPENDS BUILD_ABI_DEPENDS
.  if !empty(_BLNK_ADD_TO.${_depmethod_})
${_depmethod_}+=	${_BLNK_ADD_TO.${_depmethod_}}
.  endif
.endfor	# _BLNK_DEPENDS

###
### BEGIN: after the barrier
###
.if defined(_PKGSRC_BARRIER)

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
# BUILDLINK_IS_DEPOT.<pkg>	"yes" or "no" for whether <pkg> is a
#				depoted package.
#
# BUILDLINK_PREFIX.<pkg>	contains all of the installed files
#				for <pkg>
#
# BUILDLINK_CFLAGS.<pkg>,
# BUILDLINK_CPPFLAGS.<pkg>,
# BUILDLINK_LDFLAGS.<pkg>	contain extra compiler options, -D..., -I...
#				and -L.../-Wl,-R options to be passed to the
#				compiler/linker so that building against
#				<pkg> will work.
#
# BUILDLINK_LIBS.<pkg>		contain -l... (library) options that can be
#				automatically appended to the LIBS
#				variable when building against <pkg>.
#
# BUILDLINK_AUTO_VARS.<pkg>	"yes" or "no" for whether BUILDLINK_{CFLAGS,
#				CPPFLAGS,LDFLAGS,LIBS}.<pkg> should
#				automatically be appended their respective
#				variables.  Defaults to "yes".
#
# BUILDLINK_INCDIRS.<pkg>,
# BUILDLINK_LIBDIRS.<pkg>,
# BUILDLINK_RPATHDIRS.<pkg>	subdirectories of BUILDLINK_PREFIX.<pkg>
#				that should be added to the
#				compiler/linker search paths; these
#				directories are checked to see if they
#				exist before they're added to the search
#				paths.
#
.for _pkg_ in ${_BLNK_PACKAGES}
#
# If we're using the built-in package, then provide sensible defaults.
#
USE_BUILTIN.${_pkg_}?=		no
.  if !empty(USE_BUILTIN.${_pkg_}:M[yY][eE][sS])
_BLNK_PKG_DBDIR.${_pkg_}?=	_BLNK_PKG_DBDIR.${_pkg_}_not_found
_BLNK_PKG_INFO.${_pkg_}?=	${TRUE}
BUILDLINK_PKGNAME.${_pkg_}?=	${_pkg_}
BUILDLINK_IS_DEPOT.${_pkg_}?=	no
# Usual systems has builtin packages in /usr
.    if exists(/usr)
BUILDLINK_PREFIX.${_pkg_}?=	/usr
# Haiku OS has posix packages in /boot/common
.    elif exists(/boot/common)
BUILDLINK_PREFIX.${_pkg_}?=	/boot/common
.    else
# XXX: elsewhere?
BUILDLINK_PREFIX.${_pkg_}?=	/
.    endif
.    if !empty(LIBABISUFFIX)
BUILDLINK_LIBDIRS.${_pkg_}?=	lib${LIBABISUFFIX}
.    endif
.  endif
#
# Set a default for _BLNK_PKG_DBDIR.<pkg>, which is the directory
# containing the package metadata.
#
.  if !defined(_BLNK_PKG_DBDIR.${_pkg_})
_BLNK_PKG_DBDIR.${_pkg_}?=	# empty
.    for _depend_ in ${BUILDLINK_API_DEPENDS.${_pkg_}}
.      if empty(_BLNK_PKG_DBDIR.${_pkg_}:M*not_found)
_BLNK_PKG_DBDIR.${_pkg_}!=	\
	pkg=`${PKG_INFO} -E "${_depend_}" || ${TRUE}`;			\
	case "$$pkg" in							\
	"")	dir="_BLNK_PKG_DBDIR.${_pkg_}_not_found" ;;		\
	*)	dir="${_PKG_DBDIR}/$$pkg";				\
		if [ -f $$dir/+DEPOT ]; then				\
			dir=`${HEAD} -1 $$dir/+DEPOT`;			\
		fi ;;							\
	esac;								\
	${ECHO} $$dir
.      endif
.    endfor
.  endif
.  if empty(_BLNK_PKG_DBDIR.${_pkg_}:M*not_found)
MAKEVARS+=	_BLNK_PKG_DBDIR.${_pkg_}
.  endif

.  if empty(_BLNK_PKG_DBDIR.${_pkg_}:M*not_found)
_BLNK_PKG_INFO.${_pkg_}?=	${PKG_INFO_CMD} -K ${_BLNK_PKG_DBDIR.${_pkg_}:H}
.  else
_BLNK_PKG_INFO.${_pkg_}?=	${PKG_INFO_CMD} -K ${_PKG_DBDIR}
.  endif

BUILDLINK_PKGNAME.${_pkg_}?=	${_BLNK_PKG_DBDIR.${_pkg_}:T}
.  if exists(${_BLNK_PKG_DBDIR.${_pkg_}}/+VIEWS)
BUILDLINK_IS_DEPOT.${_pkg_}?=	yes
.  else
BUILDLINK_IS_DEPOT.${_pkg_}?=	no
.  endif
#
# Set BUILDLINK_PREFIX.<pkg> to the "PREFIX" value for the package.
#
.  if !defined(BUILDLINK_PREFIX.${_pkg_})
.    if !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
BUILDLINK_PREFIX.${_pkg_}=	${_BLNK_PKG_DBDIR.${_pkg_}}
.    else
.      if empty(BUILDLINK_PKGNAME.${_pkg_}:M*not_found)
BUILDLINK_PREFIX.${_pkg_}!=						\
	${TRUE} Computing BUILDLINK_PREFIX.${_pkg_:Q};			\
	${_BLNK_PKG_INFO.${_pkg_}} -qp ${BUILDLINK_PKGNAME.${_pkg_}} |	\
	${SED}  -e "s,^[^/]*,,;q"
.      else
BUILDLINK_PREFIX.${_pkg_}=	BUILDLINK_PREFIX.${_pkg_}_not_found
.      endif
.    endif
.  endif
.  if empty(BUILDLINK_PREFIX.${_pkg_}:M*not_found)
MAKEVARS+=	BUILDLINK_PREFIX.${_pkg_}
.  endif

.  if empty(BUILDLINK_PREFIX.${_pkg_}:N/usr:N/boot/common:N/)
BUILDLINK_DIR.${_pkg_}=	${BUILDLINK_PREFIX.${_pkg_}}
.  else
BUILDLINK_DIR.${_pkg_}= ${BUILDLINK_DIR}
.  endif

BUILDLINK_AUTO_VARS.${_pkg_}?=	yes
BUILDLINK_CPPFLAGS.${_pkg_}?=	# empty
BUILDLINK_LDFLAGS.${_pkg_}?=	# empty
BUILDLINK_LIBS.${_pkg_}?=	# empty
BUILDLINK_INCDIRS.${_pkg_}?=	include
BUILDLINK_LIBDIRS.${_pkg_}?=	lib
.  if !empty(BUILDLINK_DEPMETHOD.${_pkg_}:Mfull)
BUILDLINK_RPATHDIRS.${_pkg_}?=	${BUILDLINK_LIBDIRS.${_pkg_}}
.  else
BUILDLINK_RPATHDIRS.${_pkg_}?=	# empty
.  endif
.endfor

# BUILDLINK_CPPFLAGS, BUILDLINK_LDFLAGS, and BUILDLINK_LIBS contain the
# proper -I..., -L.../-Wl,-R..., and -l... options to be passed to the
# compiler and linker to find the headers and libraries for the various
# packages at configure/build time.  BUILDLINK_CFLAGS contains any special
# compiler options needed when building against the various packages.
#
BUILDLINK_CPPFLAGS=	# empty
BUILDLINK_LDFLAGS=	# empty
BUILDLINK_LIBS=		# empty
BUILDLINK_CFLAGS=	# empty

.for _pkg_ in ${_BLNK_PACKAGES}
.  if defined(BUILDLINK_AUTO_VARS.${_pkg_}) && \
      !empty(BUILDLINK_AUTO_VARS.${_pkg_}:M[yY][eE][sS])
.    for _flag_ in ${BUILDLINK_CPPFLAGS.${_pkg_}}
.      if empty(BUILDLINK_CPPFLAGS:M${_flag_:S/:/\\:/g})
BUILDLINK_CPPFLAGS+=	${_flag_}
.      endif
.    endfor
.    for _flag_ in ${BUILDLINK_LDFLAGS.${_pkg_}}
.      if empty(BUILDLINK_LDFLAGS:M${_flag_:S/:/\\:/g})
BUILDLINK_LDFLAGS+=	${_flag_}
.      endif
.    endfor
.    for _flag_ in ${BUILDLINK_CFLAGS.${_pkg_}}
.      if empty(BUILDLINK_CFLAGS:M${_flag_:S/:/\\:/g})
BUILDLINK_CFLAGS+=	${_flag_}
.      endif
.    endfor
.    for _flag_ in ${BUILDLINK_LIBS.${_pkg_}}
.      if empty(BUILDLINK_LIBS:M${_flag_:S/:/\\:/g})
BUILDLINK_LIBS+=	${_flag_}
.      endif
.    endfor
.  endif
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
.      endif
.    endfor
.  endif
.  if !empty(BUILDLINK_RPATHDIRS.${_pkg_})
.    for _dir_ in ${BUILDLINK_RPATHDIRS.${_pkg_}:S/^/${BUILDLINK_PREFIX.${_pkg_}}\//}
.      if exists(${_dir_})
.        if empty(BUILDLINK_LDFLAGS:M${COMPILER_RPATH_FLAG}${_dir_})
BUILDLINK_LDFLAGS+=	${COMPILER_RPATH_FLAG}${_dir_}
.        endif
.      endif
.    endfor
.  endif
.endfor
#
# Add the depot directory library directory for this package to the
# runtime library search path.
#
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
.  if empty(BUILDLINK_LDFLAGS:M${COMPILER_RPATH_FLAG}${PREFIX}/lib)
BUILDLINK_LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib
.  endif
.endif
#
# Add the default view library directories to the runtime library search
# path so that wildcard dependencies on library packages can always be
# fulfilled through the default view.
#
.for _pkg_ in ${_BLNK_PACKAGES}
.  if !empty(BUILDLINK_RPATHDIRS.${_pkg_})
.    for _dir_ in ${BUILDLINK_RPATHDIRS.${_pkg_}:S/^/${LOCALBASE}\//}
.      if exists(${_dir_})
.        if empty(BUILDLINK_LDFLAGS:M${COMPILER_RPATH_FLAG}${_dir_})
BUILDLINK_LDFLAGS+=	${COMPILER_RPATH_FLAG}${_dir_}
.        endif
.      endif
.    endfor
.  endif
.endfor
#
# Ensure that ${LOCALBASE}/lib is in the runtime library search path.
#
.if empty(BUILDLINK_LDFLAGS:M${COMPILER_RPATH_FLAG}${LOCALBASE}/lib)
BUILDLINK_LDFLAGS+=	${COMPILER_RPATH_FLAG}${LOCALBASE}/lib
.endif
#
# Add the X11 library directory to the library search paths if the package
# uses X11 and we are not using modular Xorg.
#
.if defined(USE_X11) && ${X11_TYPE} != "modular"
.  if empty(BUILDLINK_LDFLAGS:M-L${X11BASE}/lib${LIBABISUFFIX})
BUILDLINK_LDFLAGS+=	-L${X11BASE}/lib${LIBABISUFFIX}
.  endif
.  if empty(BUILDLINK_LDFLAGS:M${COMPILER_RPATH_FLAG}${X11BASE}/lib${LIBABISUFFIX})
BUILDLINK_LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib${LIBABISUFFIX}
.  endif
.endif

CFLAGS?=	# empty
CPPFLAGS?=	# empty
CXXFLAGS?=	# empty
LDFLAGS?=	# empty
LIBS?=		# empty

.for _flag_ in ${BUILDLINK_CFLAGS}
.  if empty(CFLAGS:M${_flag_:S/:/\\:/g})
CFLAGS+=	${_flag_}
.  endif
.  if empty(CXXFLAGS:M${_flag_:S/:/\\:/g})
CXXFLAGS+=	${_flag_}
.  endif
.endfor
#
# We add BUILDLINK_CPPFLAGS to both CFLAGS and CXXFLAGS since much software
# ignores the value of CPPFLAGS that we set in the environment.
#
.for _flag_ in ${BUILDLINK_CPPFLAGS}
.  if empty(CPPFLAGS:M${_flag_:S/:/\\:/g})
CPPFLAGS+=	${_flag_}
.  endif
.  if empty(CFLAGS:M${_flag_:S/:/\\:/g})
CFLAGS+=	${_flag_}
.  endif
.  if empty(CXXFLAGS:M${_flag_:S/:/\\:/g})
CXXFLAGS+=	${_flag_}
.  endif
.endfor
.for _flag_ in ${BUILDLINK_LDFLAGS}
.  if empty(LDFLAGS:M${_flag_:S/:/\\:/g})
LDFLAGS+=	${_flag_}
.  endif
.endfor
.for _flag_ in ${BUILDLINK_LIBS}
.  if empty(LIBS:M${_flag_:S/:/\\:/g})
LIBS+=		${_flag_}
.  endif
.endfor

# Create the buildlink include and lib directories so that the Darwin
# compiler/linker won't complain verbosely (on stdout, even!) when
# those directories are passed as sub-arguments of -I and -L.  Also,
# create the buildlink bin directory for use by packages that need to
# drop off a buildlink wrapper for an installed binary or script.
#
.PHONY: buildlink-directories
do-buildlink: buildlink-directories
buildlink-directories:
	${RUN}${MKDIR} ${BUILDLINK_DIR}
	${RUN}${MKDIR} ${BUILDLINK_BINDIR}
.if defined(USE_X11) && ${X11_TYPE} != "modular"
	${RUN}${RM} -f ${BUILDLINK_X11_DIR}
	${RUN}${LN} -sf ${BUILDLINK_DIR} ${BUILDLINK_X11_DIR}
.endif
	${RUN}${MKDIR} ${BUILDLINK_DIR}/include
	${RUN}${MKDIR} ${BUILDLINK_DIR}/lib

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
#	to ${BUILDLINK_PREFIX.<pkg>}.  The resulting files are to be
#	symlinked into ${BUILDLINK_DIR}.  By default, this takes the
#	+CONTENTS of a <pkg> and filters it through
#	${BUILDLINK_CONTENTS_FILTER.<pkg>}.
#
# BUILDLINK_CONTENTS_FILTER.<pkg>
#	filter command that filters +CONTENTS input into a list of files
#	relative to ${BUILDLINK_PREFIX.<pkg>} on stdout.  By default for
#	overwrite packages, BUILDLINK_CONTENTS_FILTER.<pkg> outputs the
#	contents of the include and lib directories in the package
#	+CONTENTS, and for pkgviews packages, it outputs any libtool
#	archives in lib directories.
#
# BUILDLINK_FNAME_TRANSFORM.<pkg>
#	sed arguments used to transform the name of the source filename
#	into a destination filename, e.g. -e "s|/curses.h|/ncurses.h|g"
#
.for _pkg_ in ${_BLNK_PACKAGES}
_BLNK_COOKIE.${_pkg_}=		${BUILDLINK_DIR}/.buildlink_${_pkg_}_done

_BLNK_TARGETS+=			buildlink-${_pkg_}
_BLNK_TARGETS.${_pkg_}=		buildlink-${_pkg_}-message
_BLNK_TARGETS.${_pkg_}+=	${_BLNK_COOKIE.${_pkg_}}
_BLNK_TARGETS.${_pkg_}+=	buildlink-${_pkg_}-cookie

.PHONY: buildlink-${_pkg_}
buildlink-${_pkg_}: ${_BLNK_TARGETS.${_pkg_}}

.PHONY: buildlink-${_pkg_}-message
buildlink-${_pkg_}-message:
	${RUN}					\
	${ECHO_BUILDLINK_MSG} "=> Linking ${_pkg_} files into ${BUILDLINK_DIR}."

.PHONY: buildlink-${_pkg_}-cookie
buildlink-${_pkg_}-cookie:
	${RUN}					\
	${TOUCH} ${TOUCH_FLAGS} ${_BLNK_COOKIE.${_pkg_}}

.  if (${PKG_INSTALLATION_TYPE} == "pkgviews") &&			\
      !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
BUILDLINK_CONTENTS_FILTER.${_pkg_}?=					\
	${EGREP} 'lib(/pkgconfig/.*\.pc$$|.*/lib[^/]*\.la$$)'
.  else
BUILDLINK_CONTENTS_FILTER.${_pkg_}?=					\
	${EGREP} '(include.*/|\.h$$|\.idl$$|\.pc$$|/lib[^/]*\.[^/]*$$)'
.  endif
# XXX: Why not pkg_info -qL?
BUILDLINK_FILES_CMD.${_pkg_}?=						\
	${_BLNK_PKG_INFO.${_pkg_}} -f ${BUILDLINK_PKGNAME.${_pkg_}} |	\
	${SED} -n '/File:/s/^[ 	]*File:[ 	]*//p' |		\
	${BUILDLINK_CONTENTS_FILTER.${_pkg_}} | ${CAT}

# _BLNK_FILES_CMD.<pkg> combines BUILDLINK_FILES_CMD.<pkg> and
# BUILDLINK_FILES.<pkg> into one command that outputs all of the files
# for <pkg> relative to ${BUILDLINK_PREFIX.<pkg>}.
#
_BLNK_FILES_CMD.${_pkg_}=	(
_BLNK_FILES_CMD.${_pkg_}+=	${BUILDLINK_FILES_CMD.${_pkg_}};
.for _filepattern_ in ${BUILDLINK_FILES.${_pkg_}}
_BLNK_FILES_CMD.${_pkg_}+=	${LS} -1 ${_filepattern_} 2>/dev/null || ${TRUE};
.endfor
_BLNK_FILES_CMD.${_pkg_}+=	)
_BLNK_FILES_CMD.${_pkg_}+=	| ${SORT} -u

${_BLNK_COOKIE.${_pkg_}}:
	${RUN}					\
	case ${BUILDLINK_PREFIX.${_pkg_}} in				\
	*not_found)							\
		${ERROR_MSG} "${BUILDLINK_API_DEPENDS.${_pkg_}} is not installed; can't buildlink files."; \
		exit 1;							\
		;;							\
	esac
	${RUN} [ ${X11BASE:Q}"" ] || {					\
		${ERROR_MSG} "[bsd.buildlink3.mk] X11BASE is not set correctly."; \
		exit 1;							\
	}
	${RUN}								\
	case ${BUILDLINK_PREFIX.${_pkg_}} in				\
	${LOCALBASE})   buildlink_dir="${BUILDLINK_DIR}" ;;		\
	${X11BASE})     buildlink_dir="${BUILDLINK_X11_DIR}" ;;		\
	*)              buildlink_dir="${BUILDLINK_DIR}" ;;		\
	esac;								\
	cd ${BUILDLINK_PREFIX.${_pkg_}};				\
	${_BLNK_FILES_CMD.${_pkg_}} |					\
	while read file; do						\
		src="${_CROSS_DESTDIR}${BUILDLINK_PREFIX.${_pkg_}}/$$file";		\
		if [ ! -f "$$src" ]; then					\
			msg="$$src: not found";				\
		else							\
			if [ -z "${BUILDLINK_FNAME_TRANSFORM.${_pkg_}:Q}" ]; then \
				dest="$$buildlink_dir/$$file";		\
				msg="$$src";				\
			else						\
				dest="$$buildlink_dir/$$file";		\
				dest=`${ECHO} $$dest | ${SED} ${BUILDLINK_FNAME_TRANSFORM.${_pkg_}}`; \
				msg="$$src -> $$dest";			\
			fi;						\
			dir=`${DIRNAME} "$$dest"`;			\
			if [ ! -d "$$dir" ]; then				\
				${MKDIR} "$$dir";				\
			fi;						\
			${RM} -f "$$dest";				\
			case "$$src" in					\
			*.la)						\
				${CAT} "$$src" |			\
				${_BLNK_LT_ARCHIVE_FILTER.${_pkg_}}	\
					> "$$dest";			\
				msg="$$msg (created)";			\
				;;					\
			*)						\
				${LN} -sf "$$src" "$$dest";		\
				;;					\
			esac;						\
		fi;							\
		${ECHO} "$$msg" >> ${.TARGET};				\
	done

# _BLNK_LT_ARCHIVE_FILTER.${_pkg_} is a command-line filter used in
# the previous target for transforming libtool archives (*.la) to
# allow libtool to properly interact with buildlink at link time by
# linking against the libraries pointed to by symlinks in ${BUILDLINK_DIR}.
#
_BLNK_LT_ARCHIVE_FILTER.${_pkg_}=	\
	${SED} ${_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}}

_BLNK_SEP=	\ \`\"':;,
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}=	# empty
#
# Modify the dependency_libs line by changing all full paths to other *.la
# files into the canonical ${BUILDLINK_DIR} path.
#
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)/usr\(/lib/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)/usr\(/lib/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)${DEPOTBASE}/[^/${_BLNK_SEP}]*\(/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)${DEPOTBASE}/[^/${_BLNK_SEP}]*\(/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}\\2,g"

.if ${X11_TYPE} != "modular"
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)${X11BASE}\(/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)${X11BASE}\(/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}\\2,g"
.endif

_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)${LOCALBASE}\(/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)${LOCALBASE}\(/[^${_BLNK_SEP}]*lib[^/${_BLNK_SEP}]*\.la[${_BLNK_SEP}]\),\\1${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}\\2,g"

#
# Modify the dependency_libs line by removing -L/usr/lib, which is implied.
#
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L/usr/lib\([${_BLNK_SEP}]\),\\1\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L/usr/lib\([${_BLNK_SEP}]\),\\1\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L/usr/lib/\.\([${_BLNK_SEP}]\),\\1\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L/usr/lib/\.\([${_BLNK_SEP}]\),\\1\\2,g"
#
# Modify the dependency_libs line by removing -L${LOCALBASE}/* and
# -L${X11BASE}/*, since those are automatically added by the buildlink3.mk
# files.
#
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L${X11BASE}/[^${_BLNK_SEP}]*\([${_BLNK_SEP}]\),\\1\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L${X11BASE}/[^${_BLNK_SEP}]*\([${_BLNK_SEP}]\),\\1\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L${LOCALBASE}/[^${_BLNK_SEP}]*\([${_BLNK_SEP}]\),\\1\\2,g" \
	-e "/^dependency_libs=/s,\([${_BLNK_SEP}]\)-L${LOCALBASE}/[^${_BLNK_SEP}]*\([${_BLNK_SEP}]\),\\1\\2,g"
#
# Unmangle.
#
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}},${BUILDLINK_DIR},g"

.if ${X11_TYPE} != "modular"
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}},${BUILDLINK_X11_DIR},g"
.endif
#
# Modify the dependency_libs line by cleaning up any leading and trailing
# whitespace.
#
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^dependency_libs=/s,^\(dependency_libs='\) *,\\1,g"	\
	-e "/^dependency_libs=/s, *'$$,',g"
#
# Modify the libdir line to point to within ${BUILDLINK_DIR}.
# This prevents libtool from looking into the original directory
# for other *.la files.
#
.  if (${PKG_INSTALLATION_TYPE} == "overwrite") ||			\
      !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[nN][oO])
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^libdir=/s,/usr\(/lib/[^${_BLNK_SEP}]*\),${BUILDLINK_DIR}\\1,g" \
	-e "/^libdir=/s,${DEPOTBASE}/[^/${_BLNK_SEP}]*\(/[^${_BLNK_SEP}]*\),${BUILDLINK_DIR}\\1,g"

.    if ${X11_TYPE} != "modular"
_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^libdir=/s,${X11BASE}\(/[^${_BLNK_SEP}]*\),${BUILDLINK_X11_DIR}\\1,g"
.    endif

_BLNK_LT_ARCHIVE_FILTER_SED_SCRIPT.${_pkg_}+=				\
	-e "/^libdir=/s,${LOCALBASE}\(/[^${_BLNK_SEP}]*\),${BUILDLINK_DIR}\\1,g"
.  endif
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

# _BLNK_PASSTHRU_DIRS contains the list of directories which we allow in
#	preprocessor's header, linker's library, or the runtime library
#	search paths.  The values of this list represent entire directory
#	trees under each named directory.  Package makefiles may add to
#	its value through ${BUILDLINK_PASSTHRU_DIRS}.
#
# _BLNK_PASSTHRU_RPATHDIRS contains an extra list of directories which we
#	allow in the runtime library search paths.  Package makefiles may
#	add to its value through ${BUILDLINK_PASSTHRU_RPATHDIRS}.
#
_BLNK_PASSTHRU_DIRS=		# empty
_BLNK_PASSTHRU_RPATHDIRS=	# empty
#
# Allow all of the depot directories for packages whose headers and
# libraries we use.
#
.for _pkg_ in ${_BLNK_PACKAGES}
.  if !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[yY][eE][sS])
_BLNK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.${_pkg_}}
.  endif
.endfor
#
# Allow the depot directory for the package we're building.
#
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
_BLNK_PASSTHRU_DIRS+=	${PREFIX}
.endif
#
# Allow any directories specified by the package or user.
#
_BLNK_PASSTHRU_DIRS+=	${BUILDLINK_PASSTHRU_DIRS}
#
# Strip out /usr, /usr/include, and /usr/lib as they're always
# automatically added to all of the search paths.  Also strip out
# ${LOCALBASE} and ${X11BASE} to prevent silly mistakes.
#
_BLNK_PASSTHRU_DIRS:=	${_BLNK_PASSTHRU_DIRS:N/usr:N/usr/lib:N/usr/include:N${LOCALBASE}:N${X11BASE}}
#
# Allow all directories in the library subdirectories listed for each
# package to be in the runtime library search path.
#
.for _pkg_ in ${_BLNK_PACKAGES}
.  if !empty(BUILDLINK_IS_DEPOT.${_pkg_}:M[nN][oO])
.    if !empty(BUILDLINK_LIBDIRS.${_pkg_})
.      for _dir_ in ${BUILDLINK_LIBDIRS.${_pkg_}}
.        if exists(${BUILDLINK_PREFIX.${_pkg_}}/${_dir_})
_BLNK_PASSTHRU_RPATHDIRS+=	${BUILDLINK_PREFIX.${_pkg_}}/${_dir_}
.        endif
.      endfor
.    endif
.  endif
.endfor
#
# Always allow ${LOCALBASE}/lib in the runtime library search path so
# that wildcard dependencies work correctly when installing from binary
# packages.
#
_BLNK_PASSTHRU_RPATHDIRS+=	${LOCALBASE}/lib
#
# Allow ${X11BASE}/lib in the runtime library search path for USE_X11
# packages so that X11 libraries can be found.
#
.if defined(USE_X11) && ${X11_TYPE} != "modular"
_BLNK_PASSTHRU_RPATHDIRS+=	${X11BASE}/lib
.endif
#
# Allow any directories specified by the package or user.
#
_BLNK_PASSTHRU_RPATHDIRS+=	${BUILDLINK_PASSTHRU_RPATHDIRS}
#
# Strip out /usr/lib (and /usr/lib${LIBABISUFFIX}}) as it's always 
# automatically in the runtime library search path.
#
_BLNK_PASSTHRU_RPATHDIRS:=	${_BLNK_PASSTHRU_RPATHDIRS:N/usr/lib:N/usr/lib${LIBABISUFFIX}}

_BLNK_MANGLE_DIRS=	# empty
_BLNK_MANGLE_DIRS+=	${BUILDLINK_DIR}
.if ${X11_TYPE} != "modular"
_BLNK_MANGLE_DIRS+=	${BUILDLINK_X11_DIR}
.endif
_BLNK_MANGLE_DIRS+=	${WRKDIR}
_BLNK_MANGLE_DIRS+=	${_BLNK_PASSTHRU_DIRS}
_BLNK_MANGLE_DIRS+=	${_BLNK_PASSTHRU_RPATHDIRS}
_BLNK_MANGLE_DIRS+=	/usr/include
_BLNK_MANGLE_DIRS+=	/usr/lib
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
_BLNK_MANGLE_DIRS+=	${PREFIX}
.endif
_BLNK_MANGLE_DIRS+=	${LOCALBASE}
.if defined(USE_X11) && ${X11_TYPE} != "modular"
_BLNK_MANGLE_DIRS+=	${X11BASE}
.endif

_BLNK_MANGLE_START=	_bUiLdLiNk_
_BLNK_MANGLE_END=	\#
.for _dir_ in ${_BLNK_MANGLE_DIRS}
_BLNK_MANGLE_DIR.${_dir_}=	\
	${_BLNK_MANGLE_START}${_dir_:S/\//_/g}${_BLNK_MANGLE_END}
.endfor
_BLNK_MANGLE_SED_PATTERN=	\
	${_BLNK_MANGLE_START}[^/ 	${_BLNK_MANGLE_END}]*${_BLNK_MANGLE_END}

_BLNK_PROTECT_DIRS=	# empty
_BLNK_UNPROTECT_DIRS=	# empty

_BLNK_PROTECT_DIRS+=	${BUILDLINK_DIR}
.if ${X11_TYPE} != "modular"
_BLNK_PROTECT_DIRS+=	${BUILDLINK_X11_DIR}
.endif
_BLNK_PROTECT_DIRS+=	${WRKDIR}
_BLNK_PROTECT_DIRS+=	${_BLNK_PASSTHRU_DIRS}

_BLNK_UNPROTECT_DIRS+=	/usr/include
_BLNK_UNPROTECT_DIRS+=	/usr/lib
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
_BLNK_UNPROTECT_DIRS+=	${PREFIX}
.endif
_BLNK_UNPROTECT_DIRS+=	${LOCALBASE}
.if defined(USE_X11) && ${X11_TYPE} != "modular"
_BLNK_UNPROTECT_DIRS+=	${X11BASE}
.endif
_BLNK_UNPROTECT_DIRS+=	${_BLNK_PASSTHRU_DIRS}
_BLNK_UNPROTECT_DIRS+=	${WRKDIR}
.if ${X11_TYPE} != "modular"
_BLNK_UNPROTECT_DIRS+=	${BUILDLINK_X11_DIR}
.endif
_BLNK_UNPROTECT_DIRS+=	${BUILDLINK_DIR}

# Resolve some important directories to their phyiscal paths as symlinks
# tend to confuse buildlink3.
#
_BLNK_PHYSICAL_PATH_VARS?=	WRKDIR LOCALBASE
.for _var_ in ${_BLNK_PHYSICAL_PATH_VARS}
.  if !defined(_BLNK_PHYSICAL_PATH.${_var_})
_BLNK_PHYSICAL_PATH.${_var_}!=						\
	if [ -d ${${_var_}} ]; then					\
		cd ${${_var_}}; ${PWD_CMD};				\
	else								\
		${ECHO} ${${_var_}};					\
	fi
.  endif
MAKEVARS+=	_BLNK_PHYSICAL_PATH.${_var_}
.endfor

#
# Add any package specified transformations (l:, etc.)
#
_BLNK_TRANSFORM+=	${BUILDLINK_TRANSFORM}
# Transform all references to the physical paths to some important
# directories into their given names.
#
.for _var_ in ${_BLNK_PHYSICAL_PATH_VARS}
.  if (${_BLNK_PHYSICAL_PATH.${_var_}} != ${${_var_}}) && \
      empty(${_var_}:M${_BLNK_PHYSICAL_PATH.${_var_}}/*)
_BLNK_TRANSFORM+=	mangle:${_BLNK_PHYSICAL_PATH.${_var_}}:${${_var_}}
.  endif
.endfor
#
# Strip trailing /. from options.
#
_BLNK_TRANSFORM+=	strip-slashdot:
#
# Protect work directories and the dependency directories from all the
# transformations we're about to do.
#
.for _dir_ in ${_BLNK_PROTECT_DIRS}
_BLNK_TRANSFORM+=	mangle:${_dir_}:${_BLNK_MANGLE_DIR.${_dir_}}
.endfor
#
# Transform /usr/lib/../lib* to /usr/lib* so the following transformation
# work.  (added by libtool on multlib Linux systems).
#
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
_BLNK_TRANSFORM+=	mangle:/usr/lib/../lib64:/usr/lib64
_BLNK_TRANSFORM+=	mangle:/usr/lib/../lib:/usr/lib
_BLNK_TRANSFORM+=	mangle:/usr/lib/../lib32:/usr/lib32
_BLNK_TRANSFORM+=	mangle:/usr/lib/../libx32:/usr/libx32
.endif
#
# Protect -I/usr/include/* and -L/usr/lib/* from transformations (these
# aren't part of the normal header or library search paths).
#
_BLNK_TRANSFORM+=	opt-sub:-I/usr/include:-I${_BLNK_MANGLE_DIR./usr/include}
_BLNK_TRANSFORM+=	opt-sub:-L/usr/lib:-L${_BLNK_MANGLE_DIR./usr/lib}
#
# Change any buildlink directories in runtime library search paths into
# the canonical actual installed paths.
#
_BLNK_TRANSFORM+=	rpath:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}:${LOCALBASE}
.if defined(USE_X11) && ${X11_TYPE} != "modular"
_BLNK_TRANSFORM+=	rpath:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}:${X11BASE}
.endif
#
# Protect some directories that we allow to be specified for the runtime
# library search path.
#
.for _dir_ in ${_BLNK_PASSTHRU_DIRS} ${_BLNK_PASSTHRU_RPATHDIRS}
_BLNK_TRANSFORM+=	rpath:${_dir_}:${_BLNK_MANGLE_DIR.${_dir_}}
.endfor
#
# Protect /usr/lib/* as they're all allowed to be specified for the
# runtime library search path.
#
_BLNK_TRANSFORM+=	sub-rpath:/usr/lib:${_BLNK_MANGLE_DIR./usr/lib}
#
# Change references to ${DEPOTBASE}/<pkg> into ${LOCALBASE} so that
# "overwrite" packages think headers and libraries for "pkgviews" packages
# are just found in the default view.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
_BLNK_TRANSFORM+=	depot:${DEPOTBASE}:${LOCALBASE}
.endif
#
# Convert direct paths to static libraries and libtool archives in
# ${LOCALBASE} or ${X11BASE} into references into ${BUILDLINK_DIR}.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
.  if defined(USE_X11) && ${X11_TYPE} != "modular"
_BLNK_TRANSFORM+=	P:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
.  endif
_BLNK_TRANSFORM+=	P:${LOCALBASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}
.endif
#
# Transform references to ${X11BASE} into ${BUILDLINK_X11_DIR}.
# (do so before transforming references to ${LOCALBASE} unless the
# ${X11BASE} path is contained in ${LOCALBASE}'s path)
#
.if defined(USE_X11) && empty(LOCALBASE:M${X11BASE}*) && ${X11_TYPE} != "modular"
_BLNK_TRANSFORM+=       I:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
_BLNK_TRANSFORM+=       L:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
.endif
#
# Transform references to ${LOCALBASE} into ${BUILDLINK_DIR}.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
_BLNK_TRANSFORM+=	I:${LOCALBASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}
_BLNK_TRANSFORM+=	L:${LOCALBASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_DIR}}
.endif
#
# Transform references to ${X11BASE} into ${BUILDLINK_X11_DIR}.
# (do so only after transforming references to ${LOCALBASE} if the
# ${X11BASE} path is contained in ${LOCALBASE}'s path)
#
.if defined(USE_X11) && !empty(LOCALBASE:M${X11BASE}*) && ${X11_TYPE} != "modular"
_BLNK_TRANSFORM+=	I:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
_BLNK_TRANSFORM+=	L:${X11BASE}:${_BLNK_MANGLE_DIR.${BUILDLINK_X11_DIR}}
.endif
#
# Protect any remaining references to ${PREFIX}, ${LOCALBASE}, or ${X11BASE}.
#
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
_BLNK_TRANSFORM+=	untransform:sub-mangle:${PREFIX}:${_BLNK_MANGLE_DIR.${PREFIX}}
.endif
_BLNK_TRANSFORM+=	untransform:sub-mangle:${LOCALBASE}:${_BLNK_MANGLE_DIR.${LOCALBASE}}
.if defined(USE_X11) && ${X11_TYPE} != "modular"
_BLNK_TRANSFORM+=	untransform:sub-mangle:${X11BASE}:${_BLNK_MANGLE_DIR.${X11BASE}}
.endif
#
# Explicitly remove everything else that's an absolute path, since we've
# already protected the ones we care about.
#
_BLNK_TRANSFORM+=       no-abspath
#
# Undo the protection for the directories that we allow to be specified
# for the runtime library search path.
#
.for _dir_ in ${_BLNK_PASSTHRU_DIRS} ${_BLNK_PASSTHRU_RPATHDIRS}
_BLNK_TRANSFORM+=	rpath:${_BLNK_MANGLE_DIR.${_dir_}}:${_dir_}
.endfor
#
# Undo the protection so the correct directory names are passed to the
# the wrappee.
#
.for _dir_ in ${_BLNK_UNPROTECT_DIRS}
_BLNK_TRANSFORM+=	mangle:${_BLNK_MANGLE_DIR.${_dir_}}:${_dir_}
.endfor

WRAPPER_TRANSFORM_CMDS+=	${_BLNK_TRANSFORM}

# Generate wrapper scripts for the compiler tools that sanitize the
# argument list by converting references to ${LOCALBASE} and ${X11BASE}
# into references to ${BUILDLINK_DIR} and ${BUILDLINK_X11_DIR}. These
# wrapper scripts are to be used instead of the actual compiler tools when
# building software.
#
.if defined(USE_LIBTOOL)
WRAPPEES+=		LIBTOOL
WRAPPEES+=		SHLIBTOOL
_LIBTOOL=		${WRAPPER_LIBTOOL}
_SHLIBTOOL=		${WRAPPER_SHLIBTOOL}
.endif
_WRAP_ALIASES.LIBTOOL=		libtool
_WRAP_ALIASES.SHLIBTOOL=	shlibtool
_WRAP_ENV.LIBTOOL=		PATH="${WRAPPER_BINDIR}:${_WRAP_PATH}"; export PATH
_WRAP_ENV.SHLIBTOOL=		${_WRAP_ENV.LIBTOOL}
_BLNK_LIBTOOL_FIX_LA=		${WRAPPER_TMPDIR}/libtool-fix-la

# We need to "unbuildlinkify" any libtool archives.
_BLNK_WRAP_LT_UNTRANSFORM_SED=	${SUBST_SED.unwrap}

# The libtool wrapper should do all of the same transformations as the
# compiler wrapper since the primary mode of operation of the wrapper
# assumes it's being in either compiler or link mode.
#
_WRAP_ARG_PP.LIBTOOL=		${_WRAP_ARG_PP.CC}

_WRAP_BUILDCMD.LIBTOOL=		${WRAPPER_TMPDIR}/buildcmd-libtool
_WRAP_CACHE.LIBTOOL=		${WRAPPER_TMPDIR}/cache-libtool
_WRAP_CACHE_BODY.LIBTOOL=	${WRAPPER_TMPDIR}/cache-body-libtool
_WRAP_CLEANUP.LIBTOOL=		${WRAPPER_TMPDIR}/cleanup-libtool
_WRAP_CMD_SINK.LIBTOOL=		${WRAPPER_TMPDIR}/cmd-sink-libtool
_WRAP_SCAN.LIBTOOL=		${WRAPPER_TMPDIR}/scan-libtool
_WRAP_TRANSFORM.LIBTOOL=	${WRAPPER_TMPDIR}/transform-libtool

_WRAP_BUILDCMD.SHLIBTOOL=	${_WRAP_BUILDCMD.LIBTOOL}
_WRAP_CACHE.SHLIBTOOL=		${_WRAP_CACHE.LIBTOOL}
_WRAP_CACHE_BODY.SHLIBTOOL=	${_WRAP_CACHE_BODY.LIBTOOL}
_WRAP_CLEANUP.SHLIBTOOL=	${_WRAP_CLEANUP.LIBTOOL}
_WRAP_CMD_SINK.SHLIBTOOL=	${_WRAP_CMD_SINK.LIBTOOL}
_WRAP_SCAN.SHLIBTOOL=		${_WRAP_SCAN.LIBTOOL}
_WRAP_TRANSFORM.SHLIBTOOL=	${_WRAP_TRANSFORM.LIBTOOL}

# Silently pass the appropriate flags to the compiler/linker commands so
# that headers and libraries in ${BUILDLINK_DIR}/{include,lib} are found
# before the system headers and libraries.
#
_BLNK_CPPFLAGS=			-I${BUILDLINK_DIR}/include
_BLNK_LDFLAGS=			-L${BUILDLINK_DIR}/lib
_WRAP_EXTRA_ARGS.CC+=		${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=		${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_WRAP_EXTRA_ARGS.CPP+=		${_BLNK_CPPFLAGS}
_WRAP_EXTRA_ARGS.FC+=		${_BLNK_CPPFLAGS} ${_BLNK_LDFLAGS}
_WRAP_EXTRA_ARGS.LD+=		${_BLNK_LDFLAGS}
_WRAP_EXTRA_ARGS.LIBTOOL+=	${_BLNK_LDFLAGS}
_WRAP_EXTRA_ARGS.SHLIBTOOL+=	${_BLNK_LDFLAGS}

${WRAPPER_TMPDIR}/libtool-fix-la: ${BUILDLINK_SRCDIR}/libtool-fix-la
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}${CAT} ${.ALLSRC}			\
		| ${SED} -e "s|@_BLNK_WRAP_LT_UNTRANSFORM_SED@|"${_BLNK_WRAP_LT_UNTRANSFORM_SED:Q}"|g" \
			 -e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"	\
			 -e "s|@DEPOTBASE@|${DEPOTBASE}|g"		\
			 -e "s|@LOCALBASE@|${LOCALBASE}|g"		\
			 -e "s|@WRKSRC@|${WRKSRC}|g"			\
			 -e "s|@BASENAME@|"${BASENAME:Q}"|g"		\
			 -e "s|@DIRNAME@|"${DIRNAME:Q}"|g"		\
			 -e "s|@EGREP@|"${EGREP:Q}"|g"			\
			 -e "s|@MV@|"${MV:Q}"|g"			\
			 -e "s|@PWD@|"${PWD_CMD:Q}"|g"			\
			 -e "s|@RM@|"${RM:Q}"|g"			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/buildcmd-libtool: ${BUILDLINK_SRCDIR}/buildcmd-libtool
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/cleanup-libtool:					\
		${BUILDLINK_SRCDIR}/cleanup-libtool			\
		${_BLNK_LIBTOOL_FIX_LA}
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}					\
	${CAT} ${BUILDLINK_SRCDIR}/cleanup-libtool			\
		| ${SED} -e "s|@_BLNK_LIBTOOL_FIX_LA@|"${_BLNK_LIBTOOL_FIX_LA:Q}"|g" \
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/cmd-sink-libtool: ${BUILDLINK_SRCDIR}/cmd-sink-libtool
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/scan-libtool: ${BUILDLINK_SRCDIR}/scan-libtool
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/transform-libtool: ${BUILDLINK_SRCDIR}/transform-libtool
	${RUN}${MKDIR} ${.TARGET:H}
	${RUN}${CAT} ${.ALLSRC}			\
		| ${SED} -e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g"	\
			 -e "s|@WRKSRC@|${WRKSRC}|g"			\
			 -e "s|@BASENAME@|"${BASENAME:Q}"|g"		\
			 -e "s|@DIRNAME@|"${DIRNAME:Q}"|g"		\
			 -e "s|@PWD@|"${PWD_CMD:Q}"|g"			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

WRAPPER_TARGETS+=	do-buildlink
.if !target(do-buildlink)
do-buildlink:
	@${DO_NADA}
.endif

.endif
###
### END: after the barrier
###

.PHONY: show-buildlink3
show-buildlink3:
	@${SH} ${PKGSRCDIR}/mk/buildlink3/show-buildlink3.sh ${BUILDLINK_TREE}
