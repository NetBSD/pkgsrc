# $NetBSD: bsd.wrapper.mk,v 1.4 2004/09/26 21:38:03 jlam Exp $
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

.if ${PKG_DEBUG_LEVEL} > 0
ECHO_WRAPPER_MSG?=	${ECHO}
.else
ECHO_WRAPPER_MSG?=	${TRUE}
.endif
WRAPPER_DIR=		${WRKDIR}/.wrapper
WRAPPER_BINDIR=		${WRAPPER_DIR}/bin
WRAPPER_TMPDIR=		${WRAPPER_DIR}/tmp
WRAPPER_SRCDIR=		${.CURDIR}/../../mk/wrapper
WRAPPER_SHELL=		${SH}
_WRAP_VARS_MK=		${WRAPPER_DIR}/vars.mk

.if exists(${_WRAP_VARS_MK})
.  include "${_WRAP_VARS_MK}"
.endif

.PHONY: do-wrapper

# USE_BUILDLINK3 == "no" implies NO_BUILDLINK
.if !empty(USE_BUILDLINK3:M[nN][oO])
NO_BUILDLINK=	yes
.endif
.if !defined(NO_BUILDLINK)
.  include "../../mk/buildlink3/bsd.buildlink3.mk"
.endif

# Create the saved variables Makefile fragment to pass variables
# through to sub-make processes invoked on the same Makefile.
#
do-wrapper: ${_WRAP_VARS_MK}

# Prepend ${WRAPPER_BINDIR} to the PATH so that the wrappers are found
# first when searching for executables.
#
PREPEND_PATH+=		${WRAPPER_BINDIR}

###
### BEGIN: after "wrapper" phase
###
.if !empty(PHASES_AFTER_WRAPPER:M${PKG_PHASE})

WRAPPER_DEBUG?=		yes
CONFIGURE_ENV+=		WRAPPER_DEBUG="${WRAPPER_DEBUG}"
MAKE_ENV+=		WRAPPER_DEBUG="${WRAPPER_DEBUG}"
SCRIPTS_ENV+=		WRAPPER_DEBUG="${WRAPPER_DEBUG}"

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
CONFIGURE_ENV+=		WRAPPER_UPDATE_CACHE="${WRAPPER_UPDATE_CACHE}"
MAKE_ENV+=		WRAPPER_UPDATE_CACHE="${WRAPPER_UPDATE_CACHE}"

# Only do the (expensive) reordering step if we have reordering
# transformations.
#
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
_WRAP_PATH=		${PATH:S/${WRAPPER_BINDIR}://:S/:${WRAPPER_BINDIR}//}
WRAPPER_VARS+=		_WRAP_PATH
.endif

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
# XXX The following is a workaround until I can find time to fix this
# XXX more completely (jlam).
.if ${CPP:N-*} != ${CC}
WRAPPEES+=	CPP
.endif
WRAPPEES+=	CXX
WRAPPEES+=	FC
.if defined(USE_X11)
IMAKE?=		${X11BASE}/bin/imake
WRAPPEES+=	IMAKE
.endif
WRAPPEES+=	LD

.for _wrappee_ in ${WRAPPEES}
_WRAPPEES+=	${_wrappee_}
.endfor

_WRAP_ALIASES.AS=	as
_WRAP_ALIASES.CC=	cc gcc
_WRAP_ALIASES.CXX=	c++ g++ CC
_WRAP_ALIASES.CPP=	cpp
_WRAP_ALIASES.FC=	f77 g77
_WRAP_ALIASES.IMAKE=	imake
_WRAP_ALIASES.LD=	ld

# _WRAP_*.<wrappee> variables represent "template methods" of the main
# wrapper script.  This allows individual wrappers to be customized to
# some degree:
#
_WRAP_ENV?=			PATH="${_WRAP_PATH}"; export PATH
_WRAP_EMPTY_FILE?=		${WRAPPER_TMPDIR}/empty
_WRAP_ARG_SOURCE?=		${WRAPPER_TMPDIR}/arg-source
_WRAP_BUILDCMD?=		${WRAPPER_TMPDIR}/buildcmd
_WRAP_CACHE?=			${WRAPPER_TMPDIR}/cache
_WRAP_CACHE_HEADER?=		${WRAPPER_TMPDIR}/cache-header
_WRAP_CACHE_BODY?=		${WRAPPER_TMPDIR}/cache-body
_WRAP_CACHE_FOOTER?=		${WRAPPER_TMPDIR}/cache-footer
_WRAP_CLEANUP?=			${_WRAP_EMPTY_FILE}
_WRAP_CMD_SINK?=		${WRAPPER_TMPDIR}/cmd-sink
_WRAP_GEN_REORDER?=		${WRAPPER_TMPDIR}/gen-reorder
_WRAP_GEN_TRANSFORM?=		${WRAPPER_TMPDIR}/gen-transform
_WRAP_LOG?=			${WRKLOG}
_WRAP_LOGIC?=			${WRAPPER_TMPDIR}/logic
_WRAP_REORDERLIBS?=		${WRAPPER_TMPDIR}/reorderlibs
_WRAP_SCAN?=			${_WRAP_EMPTY_FILE}
_WRAP_SHELL_LIB?=		${WRAPPER_TMPDIR}/shell-lib
_WRAP_SKIP_TRANSFORM?=		yes
_WRAP_TRANSFORM?=		${_WRAP_EMPTY_FILE}
_WRAP_TRANSFORM_SED?=		# empty
_WRAP_TRANSFORM_SEDFILE?=	${WRAPPER_TMPDIR}/transform.sed
_WRAP_UNTRANSFORM_SEDFILE?=	${WRAPPER_TMPDIR}/untransform.sed

# Generate the transformation sedfiles if we need them.
.if !empty(_WRAP_TRANSFORM_CMDS)
do-wrapper: ${_WRAP_TRANSFORM_SEDFILE} ${_WRAP_UNTRANSFORM_SEDFILE}
_WRAP_TRANSFORM_SED+=	-f ${_WRAP_TRANSFORM_SEDFILE}
_UNWRAP_SED=		-f ${_WRAP_UNTRANSFORM_SEDFILE}
.endif

.for _wrappee_ in ${_WRAPPEES}
_WRAPPER_SH.${_wrappee_}=		${WRAPPER_SRCDIR}/wrapper.sh
_WRAP_ENV.${_wrappee_}?=		${_WRAP_ENV}
_WRAP_EXTRA_ARGS.${_wrappee_}?=		# empty
_WRAP_ARG_SOURCE.${_wrappee_}?=		${_WRAP_ARG_SOURCE}
_WRAP_BUILDCMD.${_wrappee_}?=		${_WRAP_BUILDCMD}
_WRAP_CACHE.${_wrappee_}?=		${_WRAP_CACHE}
_WRAP_CACHE_HEADER.${_wrappee_}?=	${_WRAP_CACHE_HEADER}
_WRAP_CACHE_BODY.${_wrappee_}?=		${_WRAP_CACHE_BODY}
_WRAP_CACHE_FOOTER.${_wrappee_}?=	${_WRAP_CACHE_FOOTER}
_WRAP_CLEANUP.${_wrappee_}?=		${_WRAP_CLEANUP}
_WRAP_CMD_SINK.${_wrappee_}?=		${_WRAP_CMD_SINK}
_WRAP_LOG.${_wrappee_}?=		${_WRAP_LOG}
_WRAP_LOGIC.${_wrappee_}?=		${_WRAP_LOGIC}
_WRAP_SCAN.${_wrappee_}?=		${_WRAP_SCAN}
_WRAP_TRANSFORM.${_wrappee_}?=		${_WRAP_TRANSFORM}
_WRAP_TRANSFORM_SED.${_wrappee_}?=	${_WRAP_TRANSFORM_SED}
.  if !empty(_WRAP_TRANSFORM_SED.${_wrappee_})
_WRAP_SKIP_TRANSFORM.${_wrappee_}?=	no
.  else
_WRAP_SKIP_TRANSFORM.${_wrappee_}?=	${_WRAP_SKIP_TRANSFORM}
.  endif
.endfor

.if !empty(PKGSRC_COMPILER:Maix-xlc)
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-aix-xlc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${_WRAP_CMD_SINK.CC}
.endif

.if !empty(PKGSRC_COMPILER:Mmipspro)
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-mipspro-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-mipspro-cc
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.endif

.if !empty(PKGSRC_COMPILER:Mmipspro-ucode)
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-mipspro-ucode-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-mipspro-ucode-cc
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
_WRAP_CACHE_BODY.CC=	${WRAPPER_TMPDIR}/cache-body-sunpro-cc
_WRAP_TRANSFORM.CC=	${WRAPPER_TMPDIR}/transform-sunpro-cc
_WRAP_CACHE_BODY.CXX=	${_WRAP_CACHE_BODY.CC}
_WRAP_TRANSFORM.CXX=	${_WRAP_TRANSFORM.CC}
.endif

_WRAP_CMD_SINK.LD=		${WRAPPER_TMPDIR}/cmd-sink-ld
_WRAP_TRANSFORM_SED.IMAKE=	# empty

# XXX
# XXX This section is ${OPSYS}-specific and shouldn't be here.
# XXX
.if ${OPSYS} == "Interix"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-interix-gcc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${WRAPPER_TMPDIR}/cmd-sink-interix-ld
.elif ${OPSYS} == "UnixWare"
_WRAP_CMD_SINK.CC=	${WRAPPER_TMPDIR}/cmd-sink-unixware-gcc
_WRAP_CMD_SINK.CXX=	${_WRAP_CMD_SINK.CC}
_WRAP_CMD_SINK.LD=	${_WRAP_CMD_SINK.CC}
.endif

# Filter to scrunch shell scripts by removing comments and empty lines.
_WRAP_SH_CRUNCH_FILTER=							\
	${GREP} -v "^\#[^!]" | ${GREP} -v "^[ 	][ 	]*\#" |		\
	${GREP} -v "^\#$$" | ${GREP} -v "^[ 	]*$$"

_WRAP_SUBST_SED=							\
	-e "s|@CAT@|${CAT:Q}|g"						\
	-e "s|@ECHO@|${ECHO:Q}|g"					\
	-e "s|@EXPR@|${EXPR:Q}|g"					\
	-e "s|@SED@|${SED:Q}|g"						\
	-e "s|@TEST@|${TEST:Q}|g"					\
	-e "s|@WRAPPER_SHELL@|${WRAPPER_SHELL:Q}|g"			\
	-e "s|@_WRAP_LOG@|${_WRAP_LOG:Q}|g"				\
	-e "s|@_WRAP_REORDERLIBS@|${_WRAP_REORDERLIBS:Q}|g"		\
	-e "s|@_WRAP_SHELL_LIB@|${_WRAP_SHELL_LIB:Q}|g"

.for _wrappee_ in ${_WRAPPEES}
.  if defined(PKG_${_wrappee_})
_WRAP_PKG_${_wrappee_}=	${PKG_${_wrappee_}}
.  else
_WRAP_PKG_${_wrappee_}=	${${_wrappee_}}
.  endif

WRAPPER_${_wrappee_}= \
	${WRAPPER_BINDIR}/${_WRAP_PKG_${_wrappee_}:T:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
${_wrappee_}:=	${WRAPPER_${_wrappee_}:T}

_WRAP_SUBST_SED.${_wrappee_}=						\
	-e "s|@_WRAP_ENV@|${_WRAP_ENV.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_EXTRA_ARGS@|${_WRAP_EXTRA_ARGS.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_ARG_SOURCE@|${_WRAP_ARG_SOURCE.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_BUILDCMD@|${_WRAP_BUILDCMD.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_CACHE@|${_WRAP_CACHE.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_CACHE_HEADER@|${_WRAP_CACHE_HEADER.${_wrappee_}:Q}|g" \
	-e "s|@_WRAP_CACHE_BODY@|${_WRAP_CACHE_BODY.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_CACHE_FOOTER@|${_WRAP_CACHE_FOOTER.${_wrappee_}:Q}|g" \
	-e "s|@_WRAP_CLEANUP@|${_WRAP_CLEANUP.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_CMD_SINK@|${_WRAP_CMD_SINK.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_LOG@|${_WRAP_LOG.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_LOGIC@|${_WRAP_LOGIC.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_SCAN@|${_WRAP_SCAN.${_wrappee_}:Q}|g"		\
	-e "s|@_WRAP_SKIP_TRANSFORM@|${_WRAP_SKIP_TRANSFORM.${_wrappee_}:Q}|g" \
	-e "s|@_WRAP_TRANSFORM@|${_WRAP_TRANSFORM.${_wrappee_}:Q}|g"	\
	-e "s|@_WRAP_TRANSFORM_SED@|${_WRAP_TRANSFORM_SED.${_wrappee_}:Q}|g" \
	${_WRAP_SUBST_SED}

_WRAP_COOKIE.${_wrappee_}=	${WRAPPER_DIR}/.wrapper_${_wrappee_}_done

do-wrapper: ${_WRAP_COOKIE.${_wrappee_}}
${_WRAP_COOKIE.${_wrappee_}}:						\
		${_WRAPPER_SH.${_wrappee_}}				\
		${_WRAP_ARG_SOURCE.${_wrappee_}}			\
		${_WRAP_BUILDCMD.${_wrappee_}}				\
		${_WRAP_CACHE.${_wrappee_}}				\
		${_WRAP_CLEANUP.${_wrappee_}}				\
		${_WRAP_CMD_SINK.${_wrappee_}}				\
		${_WRAP_LOGIC.${_wrappee_}}				\
		${_WRAP_REORDERLIBS}					\
		${_WRAP_SCAN.${_wrappee_}}				\
		${_WRAP_SHELL_LIB}					\
		${_WRAP_TRANSFORM.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_WRAPPER_MSG}			\
		"=> Creating wrapper: ${WRAPPER_${_wrappee_}}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	wrappee="${_WRAP_PKG_${_wrappee_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}"; \
        gen_wrapper=yes;						\
	case $${wrappee} in						\
	/*)								\
		absdir=;						\
		;;							\
	*)								\
		save_IFS="$$IFS";					\
		IFS=":";						\
		for dir in $${PATH}; do					\
			case $${dir} in					\
			*${BUILDLINK_DIR}*)				\
				;;					\
			*)						\
				if [ -f $${dir}/$${wrappee} ] ||	\
				   [ -h $${dir}/$${wrappee} ] &&	\
				   [ -x $${dir}/$${wrappee} ]; then	\
					absdir=$${dir}/;		\
					wrappee=$${absdir}$${wrappee};	\
					break;				\
				fi;					\
				;;					\
			esac;						\
		done;							\
		IFS="$$save_IFS";					\
		if [ ! -x "$${wrappee}" ]; then				\
			gen_wrapper=no;					\
			${ECHO_WRAPPER_MSG} "Warning: unable to create \`$${wrappee}' wrapper script"; \
		fi;							\
		;;							\
	esac;								\
	case $$gen_wrapper in						\
	yes)								\
		${MKDIR} ${WRAPPER_${_wrappee_}:H};			\
		${CAT} ${_WRAPPER_SH.${_wrappee_}} |			\
		${SED}	${_WRAP_SUBST_SED.${_wrappee_}}			\
			-e "s|@WRAPPEE@|$${absdir}${_WRAP_PKG_${_wrappee_}:Q}|g" | \
		${_WRAP_SH_CRUNCH_FILTER}				\
		> ${WRAPPER_${_wrappee_}};				\
		${CHMOD} +x ${WRAPPER_${_wrappee_}};			\
		;;							\
	esac
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${.TARGET}

.  for _alias_ in ${_WRAP_ALIASES.${_wrappee_}:S/^/${WRAPPER_BINDIR}\//}
.    if !target(${_alias_})
do-wrapper: ${_alias_}
${_alias_}: ${_WRAP_COOKIE.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -x ${_alias_} -a -x ${WRAPPER_${_wrappee_}} ]; then	\
		${ECHO_WRAPPER_MSG} "=> Linking wrapper: ${_alias_}";	\
		${LN} -f ${WRAPPER_${_wrappee_}} ${_alias_};		\
	fi
.    endif
.  endfor
.endfor	# _WRAPPEES

.for _target_ in ${WRAPPER_TARGETS}
do-wrapper: ${_target_}
.endfor

${WRAPPER_TMPDIR}/cmd-sink-aix-xlc:					\
		${WRAPPER_SRCDIR}/cmd-sink-aix-xlc
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/cmd-sink-interix-gcc:					\
		${WRAPPER_SRCDIR}/cmd-sink-interix-gcc
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/cmd-sink-ld:						\
		${WRAPPER_SRCDIR}/cmd-sink-ld
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/cmd-sink-unixware-gcc:				\
		${WRAPPER_SRCDIR}/cmd-sink-unixware-gcc
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/transform-mipspro-cc:					\
		${WRAPPER_SRCDIR}/transform-mipspro-cc
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/transform-mipspro-ucode-cc:				\
		${WRAPPER_SRCDIR}/transform-mipspro-ucode-cc
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

${WRAPPER_TMPDIR}/transform-sunpro-cc:					\
		${WRAPPER_SRCDIR}/transform-sunpro-cc
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}

.if !target(${_WRAP_GEN_REORDER})
${_WRAP_GEN_REORDER}: 							\
		${_WRAP_SHELL_LIB}					\
		${WRAPPER_SRCDIR}/gen-reorder.sh
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CAT} ${WRAPPER_SRCDIR}/gen-reorder.sh				\
		| ${SED} ${_WRAP_SUBST_SED}				\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.endif

.if !target(${_WRAP_GEN_TRANSFORM})
${_WRAP_GEN_TRANSFORM}:							\
		${_WRAP_SHELL_LIB}					\
		${WRAPPER_SRCDIR}/gen-transform.sh
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CAT} ${WRAPPER_SRCDIR}/gen-transform.sh			\
		| ${SED} ${_WRAP_SUBST_SED}				\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.endif

.if !target(${_WRAP_REORDERLIBS})
${_WRAP_REORDERLIBS}: ${_WRAP_GEN_REORDER}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${_WRAP_GEN_REORDER} ${WRAPPER_REORDER_CMDS} > ${.TARGET}
.endif

.  if !target(${_WRAP_SHELL_LIB})
${_WRAP_SHELL_LIB}: ${.CURDIR}/../../mk/scripts/shell-lib
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.if !target(${_WRAP_TRANSFORM_SEDFILE})
${_WRAP_TRANSFORM_SEDFILE}: ${_WRAP_GEN_TRANSFORM}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${_WRAP_GEN_TRANSFORM} transform ${_WRAP_TRANSFORM_CMDS}	\
		> ${.TARGET}
.endif

.if !target(${_WRAP_UNTRANSFORM_SEDFILE})
${_WRAP_UNTRANSFORM_SEDFILE}: ${_WRAP_GEN_TRANSFORM}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${_WRAP_GEN_TRANSFORM} untransform ${_WRAP_TRANSFORM_CMDS}	\
		> ${.TARGET}
.endif

.for _wrappee_ in ${_WRAPPEES}
.  if !target$(${_WRAP_EMPTY_FILE})
${_WRAP_EMPTY_FILE}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif

.  if !target(${_WRAP_ARG_SOURCE.${_wrappee_}})
${_WRAP_ARG_SOURCE.${_wrappee_}}: ${WRAPPER_SRCDIR}/arg-source
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_BUILDCMD.${_wrappee_}})
${_WRAP_BUILDCMD.${_wrappee_}}: ${WRAPPER_SRCDIR}/buildcmd
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_CACHE.${_wrappee_}})
${_WRAP_CACHE.${_wrappee_}}:						\
		${_WRAP_CACHE_HEADER.${_wrappee_}}			\
		${_WRAP_CACHE_BODY.${_wrappee_}}			\
		${_WRAP_CACHE_FOOTER.${_wrappee_}}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_CACHE_HEADER.${_wrappee_}})
${_WRAP_CACHE_HEADER.${_wrappee_}}: ${WRAPPER_SRCDIR}/cache-header
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_CACHE_BODY.${_wrappee_}})
${_WRAP_CACHE_BODY.${_wrappee_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${.TARGET}
.  endif

.  if !target(${_WRAP_CACHE_FOOTER.${_wrappee_}})
${_WRAP_CACHE_FOOTER.${_wrappee_}}: ${WRAPPER_SRCDIR}/cache-footer
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_CMD_SINK.${_wrappee_}})
${_WRAP_CMD_SINK.${_wrappee_}}: ${WRAPPER_SRCDIR}/cmd-sink
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif

.  if !target(${_WRAP_LOGIC.${_wrappee_}})
${_WRAP_LOGIC.${_wrappee_}}: ${WRAPPER_SRCDIR}/logic
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${.ALLSRC}			\
		| ${_WRAP_SH_CRUNCH_FILTER} > ${.TARGET}
.  endif
.endfor	# _WRAPPEES

.if !target(${_WRAP_VARS_MK})
${_WRAP_VARS_MK}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${.TARGET}.tmp
.  for _var_ in ${WRAPPER_VARS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "${_var_}=	${${_var_}}" >> ${.TARGET}.tmp
.  endfor
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${.TARGET}.tmp ]; then					\
		${SORT} -u ${.TARGET}.tmp > ${.TARGET};			\
		${RM} -f ${.TARGET}.tmp;				\
	fi 
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.endif

# UNWRAP_PATTERNS and UNWRAP_FILES list shell globs and files relative to
# ${WRKSRC} that need to be "unwrapped".
#
UNWRAP_PATTERNS?=	# empty
_UNWRAP_PATTERNS=	${UNWRAP_PATTERNS}
_UNWRAP_PATTERNS+=	*-config
_UNWRAP_PATTERNS+=	*Conf.sh
_UNWRAP_PATTERNS+=	*.pc
_UNWRAP_PATTERNS_FIND=	\
	\( ${_UNWRAP_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)
UNWRAP_FILES?=		# empty
_UNWRAP_FILES=		\
	${UNWRAP_FILES}	\
	`${FIND} . ${_UNWRAP_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${SORT} -u`
_UNWRAP_SED?=		# empty

SUBST_CLASSES+=		unwrap
SUBST_STAGE.unwrap=	post-build
SUBST_MESSAGE.unwrap=	"Unwrapping files-to-be-installed."
SUBST_FILES.unwrap=	${_UNWRAP_FILES}
SUBST_SED.unwrap=	${_UNWRAP_SED}
.if defined(WRAPPER_DEBUG) && !empty(WRAPPER_DEBUG:M[yY][eE][sS])
SUBST_POSTCMD.unwrap=	${DO_NADA}
.endif

.endif	# PHASES_AFTER_WRAPPER
###
### END: after "wrapper" phase
###

.if !target(do-wrapper)
do-wrapper:
	@${DO_NADA}
.endif
