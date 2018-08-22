# $NetBSD: bsd.wrapper.mk,v 1.100 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2005 The NetBSD Foundation, Inc.
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

# Package-settable variables:
#
# WRAPPER_REORDER_CMDS
#	A list of library reordering specifications to make sure that the
#	linker sees the libraries in the correct order.
#
#	Each of the specifications has the form reorder:l:foo:bar, which
#	means that -lfoo will always come before -lbar in the linker
#	command line.
#
# Keywords: libs order reorder wrapper
#

.include "../../mk/wrapper/wrapper-defs.mk"

.PHONY: generate-wrappers

.include "../../mk/buildlink3/bsd.buildlink3.mk"

# Prepend ${WRAPPER_BINDIR} to the PATH so that the wrappers are found
# first when searching for executables.
#
PREPEND_PATH+=		${WRAPPER_BINDIR}

###
### BEGIN: after the barrier
###
.if exists(${_COOKIE.barrier})

_WRAPPER_DEBUG?=	no
CONFIGURE_ENV+=		WRAPPER_DEBUG=${_WRAPPER_DEBUG:Q}
MAKE_ENV+=		WRAPPER_DEBUG=${_WRAPPER_DEBUG:Q}
SCRIPTS_ENV+=		WRAPPER_DEBUG="${_WRAPPER_DEBUG}"

# The caching code, which greatly speeds up the build process, doesn't
# work correctly on certain platforms.
#
_WRAP_BROKEN_CACHE=	Darwin-5.*-*

.if !defined(WRAPPER_UPDATE_CACHE)
WRAPPER_UPDATE_CACHE?=	yes
.  for _pattern_ in ${_WRAP_BROKEN_CACHE}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
WRAPPER_UPDATE_CACHE=	no
.    endif
.  endfor
.endif
CONFIGURE_ENV+=		WRAPPER_UPDATE_CACHE=${WRAPPER_UPDATE_CACHE:Q}
MAKE_ENV+=		WRAPPER_UPDATE_CACHE=${WRAPPER_UPDATE_CACHE:Q}

# Only do the (expensive) reordering step if we have reordering
# transformations.

WRAPPER_REORDER_CMDS?=	# empty
.if !empty(WRAPPER_REORDER_CMDS)
MAKE_ENV+=	WRAPPER_REORDER=yes
.endif

# Remove rpath options if _USE_RPATH is "no".
.if defined(_USE_RPATH) && !empty(_USE_RPATH:M[nN][oO])
_WRAP_TRANSFORM_CMDS+=	no-rpath
.endif

# Add any package-specified transformations.
_WRAP_TRANSFORM_CMDS+=	${WRAPPER_TRANSFORM_CMDS}

# _WRAP_PATH is the path we embed in the wrapper scripts for subsequent
# calls to the toolchain.  We don't need to wrap them again because they
# are already being called with the correct arguments.
#
.if !defined(_WRAP_PATH)
_WRAP_PATH=	${PATH:S/${WRAPPER_BINDIR}://:S/:${WRAPPER_BINDIR}//}
.endif
MAKEVARS+=	_WRAP_PATH

# Generate wrapper scripts for the compiler tools.  These wrapper
# scripts are to be used instead of the actual compiler tools when
# building software.
#
# WRAPPER_CC, WRAPPER_LD, etc. are the full paths to the wrapper
# scripts.
#
# _WRAP_ALIASES.CC, _WRAP_ALIASES.LD, etc. are the other names by
# which each wrapper may be invoked.
#
WRAPPEES+=	AS
WRAPPEES+=	CC
WRAPPEES+=	CPP
WRAPPEES+=	CXX
WRAPPEES+=	FC
.if !empty(USE_TOOLS:C/:.*//:Mimake)
IMAKE?=		${X11BASE}/bin/imake
WRAPPEES+=	IMAKE
.endif
WRAPPEES+=	LD
WRAPPEES+=	AR
WRAPPEES+=	RANLIB

.if !empty(PKGSRC_COMPILER:Mxlc) && ${OPSYS} == "AIX"
CC_R?=		${_XLC_DIR}/bin/cc_r
WRAPPEES+=	CC_R
CXX_R?=		${_XLC_DIR}/bin/c++_r
WRAPPEES+=	CXX_R
.endif

_WRAPPEE_UNIQUE_CMDS=	# empty
.for _wrappee_ in ${WRAPPEES}
_WRAPPEES+=		${_wrappee_}
_WRAPPEE_${_wrappee_}=	${${_wrappee_}:T:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.  if empty(_WRAPPEE_UNIQUE_CMDS:M${_WRAPPEE_${_wrappee_}})
_WRAPPEE_UNIQUE_CMDS+=	${_WRAPPEE_${_wrappee_}}
_WRAPPEES_UNIQUE+=	${_wrappee_}
.  endif
.endfor	# WRAPPEES

.for _wrappee_ in ${_WRAPPEES}
#
# Strip the leading paths from the toolchain variables since we manipulate
# the PATH to use the correct executable.
#
.  if empty(${_wrappee_}:C/^/_asdf_/1:N_asdf_*)
${_wrappee_}:=		${${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//:T}
.  else
${_wrappee_}:=		${${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//:T} ${${_wrappee_}:C/^/_asdf_/1:N_asdf_*}
.  endif
#
# WRAPPER_<wrappee> is the full path to the wrapper script, plus any
# trailing arguments to <wrappee>.
#
WRAPPER_${_wrappee_}=	${WRAPPER_BINDIR}/${${_wrappee_}}
.endfor	# _WRAPPEES

_WRAP_ALIASES.AS=	as
_WRAP_ALIASES.CC=	cc gcc ada
_WRAP_ALIASES.CXX=	c++ g++ CC cxx
_WRAP_ALIASES.CPP=	cpp
_WRAP_ALIASES.FC=	f77 g77 gfortran
_WRAP_ALIASES.IMAKE=	imake
_WRAP_ALIASES.LD=	ld
_WRAP_ALIASES.AR=	ar
_WRAP_ALIASES.RANLIB=	ranlib

# _WRAP_*.<wrappee> variables represent "template methods" of the main
# wrapper script.  This allows individual wrappers to be customized to
# some degree:
#
_WRAP_ENV?=			PATH="${_WRAP_PATH}"; export PATH
_WRAP_EMPTY_FILE?=		${WRAPPER_TMPDIR}/empty
_WRAP_ARG_PP?=			${_WRAP_EMPTY_FILE}
_WRAP_ARG_PP_MAIN?=		${WRAPPER_TMPDIR}/arg-pp-main
_WRAP_ARG_SOURCE?=		${WRAPPER_TMPDIR}/arg-source
_WRAP_BUILDCMD?=		${WRAPPER_TMPDIR}/buildcmd
_WRAP_CACHE?=			${WRAPPER_TMPDIR}/cache
_WRAP_CACHE_BODY?=		${WRAPPER_TMPDIR}/cache-body
_WRAP_CLEANUP?=			${_WRAP_EMPTY_FILE}
_WRAP_CMD_SINK?=		${WRAPPER_TMPDIR}/cmd-sink
_WRAP_GEN_REORDER?=		${WRAPPER_TMPDIR}/gen-reorder
_WRAP_GEN_TRANSFORM?=		${WRAPPER_TMPDIR}/gen-transform
_WRAP_LOG?=			${WRKLOG}
_WRAP_LOGIC?=			${WRAPPER_TMPDIR}/logic
_WRAP_REORDERLIBS?=		${WRAPPER_TMPDIR}/reorderlibs
_WRAP_SCAN?=			${WRAPPER_TMPDIR}/scan
_WRAP_SHELL_LIB?=		${WRAPPER_TMPDIR}/shell-lib
_WRAP_SUBR_SH?=			${WRAPPER_TMPDIR}/wrapper-subr.sh
_WRAP_SKIP_TRANSFORM?=		no
_WRAP_TRANSFORM?=		${_WRAP_EMPTY_FILE}
_WRAP_TRANSFORM_SED?=		# empty
_WRAP_TRANSFORM_SEDFILE?=	${WRAPPER_TMPDIR}/transform.sed
_WRAP_UNTRANSFORM_SEDFILE?=	${WRAPPER_TMPDIR}/untransform.sed

# Generate the transformation sedfiles if we need them.
.if !empty(_WRAP_TRANSFORM_CMDS)
generate-wrappers: ${_WRAP_TRANSFORM_SEDFILE} ${_WRAP_UNTRANSFORM_SEDFILE}
_WRAP_TRANSFORM_SED+=	-f ${_WRAP_TRANSFORM_SEDFILE}
_UNWRAP_SED=		-f ${_WRAP_UNTRANSFORM_SEDFILE}
.endif

.for _wrappee_ in ${_WRAPPEES}
_WRAPPER_SH.${_wrappee_}=		${WRAPPER_SRCDIR}/wrapper.sh
_WRAP_ENV.${_wrappee_}?=		${_WRAP_ENV}
_WRAP_EXTRA_ARGS.${_wrappee_}?=		# empty
_WRAP_ARG_PP.${_wrappee_}?=		${_WRAP_ARG_PP}
_WRAP_ARG_PP_MAIN.${_wrappee_}?=	${_WRAP_ARG_PP_MAIN}
_WRAP_ARG_SOURCE.${_wrappee_}?=		${_WRAP_ARG_SOURCE}
_WRAP_BUILDCMD.${_wrappee_}?=		${_WRAP_BUILDCMD}
_WRAP_CACHE.${_wrappee_}?=		${_WRAP_CACHE}
_WRAP_CACHE_BODY.${_wrappee_}?=		${_WRAP_CACHE_BODY}
_WRAP_CLEANUP.${_wrappee_}?=		${_WRAP_CLEANUP}
_WRAP_CMD_SINK.${_wrappee_}?=		${_WRAP_CMD_SINK}
_WRAP_LOG.${_wrappee_}?=		${_WRAP_LOG}
_WRAP_LOGIC.${_wrappee_}?=		${_WRAP_LOGIC}
_WRAP_SCAN.${_wrappee_}?=		${_WRAP_SCAN}
_WRAP_TRANSFORM.${_wrappee_}?=		${_WRAP_TRANSFORM}
_WRAP_TRANSFORM_SED.${_wrappee_}?=	${_WRAP_TRANSFORM_SED}
_WRAP_SKIP_TRANSFORM.${_wrappee_}?=	${_WRAP_SKIP_TRANSFORM}
_WRAP_TYPE.${_wrappee_}?=		${_wrappee_}
.endfor	# _WRAPPEES

.if !empty(PKGSRC_COMPILER:Micc)
.  if !empty(CC_VERSION:M8.1) || !empty(CC_VERSION:M9.0)
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-icc81-cc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
.  else
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-icc-cc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
.  endif
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-icc-cc
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-icc-cc
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.endif

.if !empty(PKGSRC_COMPILER:Mmipspro)
_WRAP_ARG_PP.CC=	${WRAPPER_TMPDIR}/arg-pp-mipspro-cc
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-mipspro-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-mipspro-cc
_WRAP_ARG_PP.CXX=	${_WRAP_ARG_PP.CC}
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.endif

.if !empty(PKGSRC_COMPILER:Mmipspro-ucode)
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-mipspro-ucode-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-mipspro-ucode-cc
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.endif

.if !empty(PKGSRC_COMPILER:Mido)
_WRAP_CACHE_BODY.CC=    ${WRAPPER_TMPDIR}/cache-body-ido-cc
_WRAP_TRANSFORM.CC=     ${WRAPPER_TMPDIR}/transform-ido-cc
# enable C++ style (//) commments with the IDO cc
# just in case increase the optimization threshold from the default 1000
_WRAP_EXTRA_ARGS.CC+=	-Xcpluscomm -Olimit 6000
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-sunpro-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-sunpro-cc
_WRAP_ARG_PP.CXX=	${WRAPPER_TMPDIR}/arg-pp-sunpro-cxx
_WRAP_CACHE.CXX=	${WRAPPER_TMPDIR}/cache-sunpro-cxx
_WRAP_CACHE_BODY.CXX=	${WRAPPER_TMPDIR}/cache-body-sunpro-cxx
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
_WRAP_CMD_SINK.CXX=	${WRAPPER_TMPDIR}/cmd-sink-sunpro-cxx
_WRAP_CACHE_BODY.CPP=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CPP=	${_WRAP_TRANSFORM.CC}
.endif

.if !empty(PKGSRC_COMPILER:Mxlc)
.  if ${OPSYS} == "AIX"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-aix-xlc
_WRAP_CMD_SINK.CC_R=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.CPP=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.CXX_R=	${_WRAP_CMD_SINK.CC}
.  elif ${OPSYS} == "Darwin"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-darwin-xlc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-xlc-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-xlc-cc
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.  else
PKG_FAIL_REASON+=	"xlc unsupported on ${OPSYS}"
.  endif
.endif

.if !empty(PKGSRC_COMPILER:Mccc)
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-ccc-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-ccc-cc
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.endif

.if !empty(PKGSRC_COMPILER:Mgcc)
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-gcc
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
. if ${_PKGSRC_MKPIE} != "no"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-mkpie-gcc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${WRAPPER_TMPDIR}/cmd-sink-mkpie-ld
MKPIE_CFLAGS=		${_MKPIE_CFLAGS.gcc}
.export MKPIE_CFLAGS
MKPIE_LDFLAGS=		${_MKPIE_LDFLAGS.gcc}
.export MKPIE_LDFLAGS
. endif
.endif

_WRAP_CMD_SINK.LD=		${WRAPPER_TMPDIR}/cmd-sink-ld
_WRAP_SKIP_TRANSFORM.IMAKE=	yes

# XXX
# XXX This section is ${OPSYS}-specific and shouldn't be here.
# XXX
.if ${OPSYS} == "Interix"
_WRAP_EXTRA_ARGS.CC+=	-D_ALL_SOURCE
_WRAP_EXTRA_ARGS.CXX+=	-D_ALL_SOURCE
_WRAP_EXTRA_ARGS.CPP+=	-D_ALL_SOURCE
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-interix-gcc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${WRAPPER_TMPDIR}/cmd-sink-interix-ld
.elif ${OPSYS} == "Darwin"
_WRAP_ARG_PP.CC=	${WRAPPER_TMPDIR}/arg-pp-darwin-gcc
_WRAP_ARG_PP.CXX=	${_WRAP_ARG_PP.CC}
_WRAP_ARG_PP.LD=	${_WRAP_ARG_PP.CC}
.elif ${OPSYS} == "UnixWare"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-unixware-gcc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${_WRAP_CMD_SINK.CC}
.elif ${OPSYS} == "OSF1"
_WRAP_EXTRA_ARGS.CC+=	-D_POSIX_PII_SOCKET
_WRAP_EXTRA_ARGS.CXX+=	-D_POSIX_PII_SOCKET -D__USE_STD_IOSTREAM
_WRAP_EXTRA_ARGS.CPP+=	-D_POSIX_PII_SOCKET
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-osf1-cc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${WRAPPER_TMPDIR}/cmd-sink-osf1-ld
.elif ${OPSYS} == "HPUX"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-hpux-cc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${WRAPPER_TMPDIR}/cmd-sink-hpux-ld
.elif ${OPSYS} == "AIX"
_WRAP_CMD_SINK.CC?=	${WRAPPER_TMPDIR}/cmd-sink-aix-cc
_WRAP_CMD_SINK.CXX?=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${WRAPPER_TMPDIR}/cmd-sink-aix-ld
_WRAP_CACHE_BODY.CC?=	${WRAPPER_TMPDIR}/cache-body-aix-cc
_WRAP_CACHE_BODY.CC_R?=	${WRAPPER_TMPDIR}/cache-body-aix-cc
_WRAP_TRANSFORM.CC?=	${WRAPPER_TMPDIR}/transform-aix-cc
_WRAP_TRANSFORM.CC_R?=	${WRAPPER_TMPDIR}/transform-aix-cc
_WRAP_CACHE_BODY.CXX?=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX?=	${_WRAP_TRANSFORM.CC}
.elif ${OPSYS} == "IRIX"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-irix-cc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${WRAPPER_TMPDIR}/cmd-sink-irix-ld
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-cross-gcc
_WRAP_CMD_SINK.CPP=	${WRAPPER_TMPDIR}/cmd-sink-cross-cpp
_WRAP_CMD_SINK.CXX=	${WRAPPER_TMPDIR}/cmd-sink-cross-gxx
.endif

.if ${OPSYS} == "SunOS" && !empty(PKGSRC_COMPILER:Mgcc)
_WRAP_CMD_SINK.IMAKE=	${WRAPPER_TMPDIR}/cmd-sink-solaris-imake
_WRAP_CACHE_BODY.IMAKE=	${WRAPPER_TMPDIR}/cache-body-solaris-imake
.endif

# Filter to scrunch shell scripts by removing comments and empty lines.
_WRAP_SH_CRUNCH_FILTER= ${AWK} ' \
		/^\#!/ { print } \
		/^[[:space:]]*\#/ || NF == 0 { next } \
		/.*/ { print } \
		'

_WRAP_SUBST_SED=							\
	-e "s|@ABI@|${ABI:Q}|g"						\
	-e "s|@CAT@|${CAT:Q}|g"						\
	-e "s|@ECHO@|${ECHO:Q}|g"					\
	-e "s|@EXPR@|${EXPR:Q}|g"					\
	-e "s|@MV@|${MV}|g"						\
	-e "s|@SED@|${SED:Q}|g"						\
	-e "s|@TEST@|${TEST:Q}|g"					\
	-e "s|@WRAPPER_SHELL@|${WRAPPER_SHELL:Q}|g"			\
	-e "s|@_WRAP_LOG@|${_WRAP_LOG:Q}|g"				\
	-e "s|@_WRAP_REORDERLIBS@|${_WRAP_REORDERLIBS:Q}|g"		\
	-e "s|@_WRAP_SHELL_LIB@|${_WRAP_SHELL_LIB:Q}|g"			\
	-e "s|@_WRAP_SUBR_SH@|${_WRAP_SUBR_SH}|g"

.for _wrappee_ in ${_WRAPPEES}
_WRAP_SUBST_SED.${_wrappee_}=						\
	-e "s|@_WRAP_EMPTY_FILE@|${_WRAP_EMPTY_FILEQ}|g"		\
	-e "s|@_WRAP_ENV@|${_WRAP_ENV.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_EXTRA_ARGS@|${_WRAP_EXTRA_ARGS.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_ARG_PP@|${_WRAP_ARG_PP.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_ARG_PP_MAIN@|${_WRAP_ARG_PP_MAIN.${_wrappee_}:Q}|g" \
	-e "s|@_WRAP_ARG_SOURCE@|${_WRAP_ARG_SOURCE.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_BUILDCMD@|${_WRAP_BUILDCMD.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_CACHE@|${_WRAP_CACHE.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_CACHE_BODY@|${_WRAP_CACHE_BODY.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_CLEANUP@|${_WRAP_CLEANUP.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_CMD_SINK@|${_WRAP_CMD_SINK.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_LOG@|${_WRAP_LOG.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_LOGIC@|${_WRAP_LOGIC.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_SCAN@|${_WRAP_SCAN.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_SKIP_TRANSFORM@|${_WRAP_SKIP_TRANSFORM.${_wrappee_}:Q}|g" \
	-e "s|@_WRAP_TRANSFORM@|${_WRAP_TRANSFORM.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_TRANSFORM_SED@|${_WRAP_TRANSFORM_SED.${_wrappee_}:Q}|g" \
	-e "s|@_WRAP_TYPE@|${_WRAP_TYPE.${_wrappee_}}|g" \
	-e "s|@WRAPPER_DEBUG@|${_WRAPPER_DEBUG}|g"			\
	-e "s|@WRAPPER_UPDATE_CACHE@|${WRAPPER_UPDATE_CACHE}|g"		\
	${_WRAP_SUBST_SED}

_WRAP_COOKIE.${_wrappee_}=	${WRAPPER_DIR}/.wrapper_${_wrappee_}_done
.endfor	# _WRAPPEES

.for _wrappee_ in ${_WRAPPEES_UNIQUE}
PKG_${_wrappee_}?=	${${_wrappee_}}
generate-wrappers: ${_WRAP_COOKIE.${_wrappee_}}
${_WRAP_COOKIE.${_wrappee_}}:						\
		${_WRAPPER_SH.${_wrappee_}}				\
		${_WRAP_ARG_PP.${_wrappee_}}				\
		${_WRAP_ARG_PP_MAIN.${_wrappee_}}			\
		${_WRAP_ARG_SOURCE.${_wrappee_}}			\
		${_WRAP_BUILDCMD.${_wrappee_}}				\
		${_WRAP_CACHE.${_wrappee_}}				\
		${_WRAP_CLEANUP.${_wrappee_}}				\
		${_WRAP_CMD_SINK.${_wrappee_}}				\
		${_WRAP_LOGIC.${_wrappee_}}				\
		${_WRAP_REORDERLIBS}					\
		${_WRAP_SCAN.${_wrappee_}}				\
		${_WRAP_SHELL_LIB}					\
		${_WRAP_SUBR_SH}					\
		${_WRAP_TRANSFORM.${_wrappee_}}
	${RUN} 								\
	wrapper="${WRAPPER_${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}"; \
	if [ -x "$$wrapper" ]; then ${ECHO_BUILDLINK_MSG} "=> $$wrapper already exists. Skipping"; exit 0; fi; \
	${ECHO_BUILDLINK_MSG} "=> Creating ${_wrappee_} wrapper: $$wrapper"; \
        gen_wrapper=yes;						\
	wrappee="${PKG_${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}"; \
	case $$wrappee in						\
	/*)	;;							\
	*)	save_IFS="$$IFS";					\
		IFS=":";						\
		for dir in $${PATH}; do					\
			IFS="$$save_IFS";				\
			case $${dir} in					\
			*${WRAPPER_DIR}*)				\
				;;					\
			*)						\
				if ${TEST} -f "$${dir}/$$wrappee" -o	\
				   	   -h "$${dir}/$$wrappee"; then	\
					wrappee="$${dir}/$$wrappee";	\
					break;				\
				fi;					\
				;;					\
			esac;						\
		done;							\
		IFS="$$save_IFS";					\
		if ${TEST} ! -x "$$wrappee"; then			\
			gen_wrapper=no;					\
			${ECHO_BUILDLINK_MSG} "Warning: unable to generate ${_wrappee_} wrapper script: \`$$wrappee'"; \
		fi;							\
		;;							\
	esac;								\
	case $$gen_wrapper in						\
	yes)								\
		${MKDIR} `${DIRNAME} $$wrapper`;			\
		${CAT} ${_WRAPPER_SH.${_wrappee_}} |			\
		${SED}	${_WRAP_SUBST_SED.${_wrappee_}}			\
			-e "s|@WRAPPEE@|$$wrappee|g" |			\
		${_WRAP_SH_CRUNCH_FILTER}				\
		> $$wrapper;						\
		${CHMOD} +x $$wrapper;					\
		;;							\
	esac
	${RUN} ${TOUCH} ${TOUCH_FLAGS} ${.TARGET}

.  for _alias_ in ${_WRAP_ALIASES.${_wrappee_}:S/^/${WRAPPER_BINDIR}\//}
.    if !target(${_alias_})
generate-wrappers: ${_alias_}
${_alias_}: ${_WRAP_COOKIE.${_wrappee_}}
	${RUN} 								\
	wrapper="${WRAPPER_${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}"; \
	if [ ! -x ${.TARGET} -a -x $$wrapper ]; then			\
		${ECHO_BUILDLINK_MSG} "=> Linking ${_wrappee_} wrapper: ${.TARGET}"; \
		${LN} -f${WRAPPER_USE_SYMLINK:Ds} $$wrapper ${.TARGET};	\
	fi
.    endif
.  endfor
.endfor	# _WRAPPEES_UNIQUE

.for _target_ in ${WRAPPER_TARGETS}
generate-wrappers: ${_target_}
.endfor

.for w in \
	arg-pp-darwin-gcc \
	arg-pp-mipspro-cc \
	arg-pp-sunpro-cxx \
	cmd-sink-aix-cc \
	cmd-sink-aix-ld \
	cmd-sink-aix-xlc \
	cmd-sink-darwin-xlc \
	cmd-sink-icc-cc \
	cmd-sink-icc81-cc \
	cmd-sink-irix-cc \
	cmd-sink-irix-ld \
	cmd-sink-interix-gcc \
	cmd-sink-ld \
	cmd-sink-mkpie-gcc \
	cmd-sink-mkpie-ld \
	cmd-sink-osf1-cc \
	cmd-sink-osf1-ld \
	cmd-sink-hpux-cc \
	cmd-sink-hpux-ld \
	cmd-sink-solaris-imake \
	cmd-sink-sunpro-cxx \
	cmd-sink-unixware-gcc \
	transform-aix-cc \
	transform-ccc-cc \
	transform-gcc \
	transform-icc-cc \
	transform-ido-cc \
	transform-mipspro-cc \
	transform-mipspro-ucode-cc \
	transform-sunpro-cc \
	transform-xlc-cc \
	wrapper-subr.sh
${WRAPPER_TMPDIR}/${w}: ${WRAPPER_SRCDIR}/${w}
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.endfor

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
_WRAP_CROSS_GCC_FILTER+= ${SED}						\
	-e "s|@CROSS_DESTDIR@|${_CROSS_DESTDIR:Q}|g"			\
	-e "s|@PREFIX@|${PREFIX:Q}|g"
${WRAPPER_TMPDIR}/cmd-sink-cross-gcc: ${WRAPPER_SRCDIR}/cmd-sink-cross-gcc
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_CROSS_GCC_FILTER} |		\
	${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/cmd-sink-cross-cpp: ${WRAPPER_SRCDIR}/cmd-sink-cross-cpp
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_CROSS_GCC_FILTER} |		\
	${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/cmd-sink-cross-gxx: ${WRAPPER_SRCDIR}/cmd-sink-cross-gxx
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_CROSS_GCC_FILTER} |		\
	${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.endif

.if !target(${_WRAP_GEN_REORDER})
${_WRAP_GEN_REORDER}: 							\
		${_WRAP_SHELL_LIB}					\
		${WRAPPER_SRCDIR}/gen-reorder.sh
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} 								\
	${CAT} ${WRAPPER_SRCDIR}/gen-reorder.sh				\
		| ${SED} ${_WRAP_SUBST_SED}				\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
	${RUN} ${CHMOD} +x ${.TARGET}
.endif

.if !target(${_WRAP_GEN_TRANSFORM})
${_WRAP_GEN_TRANSFORM}:							\
		${_WRAP_SHELL_LIB}					\
		${WRAPPER_SRCDIR}/gen-transform.sh
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} 								\
	${CAT} ${WRAPPER_SRCDIR}/gen-transform.sh			\
		| ${SED} ${_WRAP_SUBST_SED}				\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
	${RUN} ${CHMOD} +x ${.TARGET}
.endif

.if !target(${_WRAP_REORDERLIBS})
${_WRAP_REORDERLIBS}: ${_WRAP_GEN_REORDER}
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${_WRAP_GEN_REORDER} ${WRAPPER_REORDER_CMDS} > ${.TARGET}
.endif

.  if !target(${_WRAP_SHELL_LIB})
${_WRAP_SHELL_LIB}: ${.CURDIR}/../../mk/scripts/shell-lib
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.if !target(${_WRAP_TRANSFORM_SEDFILE})
${_WRAP_TRANSFORM_SEDFILE}: ${_WRAP_GEN_TRANSFORM}
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${_WRAP_GEN_TRANSFORM} transform ${_WRAP_TRANSFORM_CMDS}	\
		> ${.TARGET}
.endif

.if !target(${_WRAP_UNTRANSFORM_SEDFILE})
${_WRAP_UNTRANSFORM_SEDFILE}: ${_WRAP_GEN_TRANSFORM}
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} 								\
	${_WRAP_GEN_TRANSFORM} untransform ${_WRAP_TRANSFORM_CMDS}	\
		> ${.TARGET}
.endif

.for _wrappee_ in ${_WRAPPEES}
.  if !target(${_WRAP_EMPTY_FILE})
${_WRAP_EMPTY_FILE}:
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif

.  if !target(${_WRAP_ARG_PP_MAIN.${_wrappee_}})
${_WRAP_ARG_PP_MAIN.${_wrappee_}}: ${WRAPPER_SRCDIR}/arg-pp-main
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_ARG_SOURCE.${_wrappee_}})
${_WRAP_ARG_SOURCE.${_wrappee_}}: ${WRAPPER_SRCDIR}/arg-source
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_BUILDCMD.${_wrappee_}})
${_WRAP_BUILDCMD.${_wrappee_}}: ${WRAPPER_SRCDIR}/buildcmd
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_CACHE.${_wrappee_}})
${_WRAP_CACHE.${_wrappee_}}:
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} echo "cache_lookup() { cachehit=no; }" > ${.TARGET}
.  endif

.  if !target(${_WRAP_CACHE_BODY.${_wrappee_}})
${_WRAP_CACHE_BODY.${_wrappee_}}:
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif

.  if !target(${_WRAP_CMD_SINK.${_wrappee_}})
${_WRAP_CMD_SINK.${_wrappee_}}: ${WRAPPER_SRCDIR}/cmd-sink
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_LOGIC.${_wrappee_}})
${_WRAP_LOGIC.${_wrappee_}}: ${WRAPPER_SRCDIR}/logic
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_SCAN.${_wrappee_}})
${_WRAP_SCAN.${_wrappee_}}: ${WRAPPER_SRCDIR}/scan
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${CAT} ${.ALLSRC} | ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif
.endfor	# _WRAPPEES

# UNWRAP_PATTERNS and UNWRAP_FILES list shell globs and files relative to
# ${WRKSRC} that need to be "unwrapped".
#
UNWRAP_PATTERNS?=	# empty
_UNWRAP_PATTERNS=	${UNWRAP_PATTERNS}
_UNWRAP_PATTERNS+=	*-config
_UNWRAP_PATTERNS+=	*Conf.sh
_UNWRAP_PATTERNS+=	*.pc
_UNWRAP_PATTERNS_FIND_cmd=	\
	cd ${WRKSRC} && \
	${ECHO} "__dummy-entry__" && \
	${FIND} . -type f \( ${_UNWRAP_PATTERNS:C/.*/-o -name "&"/g:S/-o//1} \) -print \
	| ${SED} -e 's|^\./||' \
	| ${SORT} -u
UNWRAP_FILES?=		# empty
_UNWRAP_FILES=		${UNWRAP_FILES}					\
			${_UNWRAP_PATTERNS_FIND_cmd:sh:N__dummy-entry__}
_UNWRAP_SED?=		# empty

SUBST_CLASSES+=		unwrap
SUBST_STAGE.unwrap=	post-build
SUBST_MESSAGE.unwrap=	Unwrapping files-to-be-installed.
SUBST_FILES.unwrap=	${_UNWRAP_FILES}
SUBST_SED.unwrap=	${_UNWRAP_SED}
.if defined(_WRAPPER_DEBUG) && !empty(_WRAPPER_DEBUG:M[yY][eE][sS])
_SUBST_KEEP.unwrap=	${CP} -f "$$file" "$$file.before-unwrap"
.endif

.endif
###
### END: after the barrier
###

######################################################################
######################################################################
######################################################################

_COOKIE.wrapper=	${WRKDIR}/.wrapper_done

.PHONY: wrapper
.if !target(wrapper)
.  if exists(${_COOKIE.wrapper})
wrapper:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
wrapper: check-vulnerable patch acquire-wrapper-lock ${_COOKIE.wrapper} release-wrapper-lock
.  else
wrapper: barrier
.  endif
.endif

.PHONY: acquire-wrapper-lock release-wrapper-lock
acquire-wrapper-lock: acquire-lock
release-wrapper-lock: release-lock

.if exists(${_COOKIE.wrapper})
${_COOKIE.wrapper}:
	@${DO_NADA}
.else
${_COOKIE.wrapper}: real-wrapper
.endif

.PHONY: real-wrapper
real-wrapper: wrapper-message wrapper-vars pre-wrapper do-wrapper post-wrapper wrapper-cookie error-check

.PHONY: wrapper-message
wrapper-message:
	@${PHASE_MSG} "Creating toolchain wrappers for ${PKGNAME}"

.PHONY: pre-wrapper do-wrapper post-wrapper

do-wrapper: generate-wrappers

.if !target(do-wrapper)
do-wrapper:
	@${DO_NADA}
.endif

.if !target(pre-wrapper)
pre-wrapper:
	@${DO_NADA}
.endif

.if !target(post-wrapper)
post-wrapper:
	@${DO_NADA}
.endif

.PHONY: wrapper-cookie
wrapper-cookie:
	${RUN} [ ! -f ${_COOKIE.wrapper} ]
	${RUN} ${MKDIR} ${_COOKIE.wrapper:H}
	${RUN} ${ECHO} ${PKGNAME} > ${_COOKIE.wrapper}
