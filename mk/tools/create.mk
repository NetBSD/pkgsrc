# $NetBSD: create.mk,v 1.8 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2005, 2006 The NetBSD Foundation, Inc.
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
#

#
# This Makefile fragment creates tools under ${TOOLS_DIR} that are
# found before similarly-named tools in the system path.
#
#    TOOLS_CREATE is a whitespace-separated list of tools for which a
#       corresponding tool is created.  Either a wrapper script or a
#       symlink is created depending on the tool that is being
#	overridden.
#
# The following variables specify the details of each <tool>:
#
#    TOOLS_CMD.<tool> is the path to the tool under ${TOOLS_DIR}.  This
#	variable is optional, and if left unspecified it defaults to
#	${TOOLS_DIRS}/bin/<tool>.
#
#    TOOLS_ALIASES.<tool> is a whitespace-separated list of names for
#	which <tool> should also be created under ${TOOLS_DIR}.
#
#    TOOLS_PATH.<tool> is the path to the actual command that is
#	invoked when ${TOOLS_CMD.<tool>} is called.  If <tool> should
#	be a symlink, then this variable is required and should be a
#	full path.  If <tool> should be a wrapper, then this variable
#	is required unless TOOLS_SCRIPT.<tool> is defined (see below).
#
# The following variables specify further details of each <tool> and
# if set, cause a wrapper script to be created.
#
#    TOOLS_ARGS.<tool> additional arguments that are passed to the real
#	command ahead of any command-line arguments.  This variable is
#	optional.
#
#    TOOLS_SCRIPT.<tool> specifies the Bourne-shell scriptlet to embed
#	in the wrapper script that is executed when <tool> is called.
# 	This variable is optional, and if left unspecified, then this
# 	is built up from TOOLS_PATH.<tool> and TOOLS_ARGS.<tool> by
# 	default.
#
# The following variables provide shortcuts for creating certain classes
# of tools:
#
#    TOOLS_NOOP is a list of tools that do nothing and return true.
#
#    TOOLS_BROKEN is a list of tools that do nothing and return false.
#
#    TOOLS_GNU_MISSING is a list of tools for which the GNU missing
#	script is invoked in place of the real tool.  This is used
#	primarily to hide GNU auto* tools.
#
#    TOOLS_FAIL is a list of tools that return false and record their
#	call in the .warning directory, which is later shown.
#

######################################################################

.for _t_ in ${TOOLS_NOOP}
TOOLS_CREATE+=		${_t_}
TOOLS_SCRIPT.${_t_}?=	exit 0
.endfor

.for _t_ in ${TOOLS_BROKEN}
TOOLS_CREATE+=		${_t_}
TOOLS_SCRIPT.${_t_}?=	exit 1
.endfor

.for _t_ in ${TOOLS_FAIL}
TOOLS_CREATE+=		${_t_}
TOOLS_SCRIPT.${_t_}?=	\
	${DELAYED_WARNING_MSG} "Please add USE_TOOLS+=${_t_} to the package Makefile."; \
	${FAIL_MSG} "To use this tool, add USE_TOOLS+=${_t_} to the package Makefile."
.endfor

.for _t_ in ${TOOLS_GNU_MISSING}
TOOLS_CREATE+=		${_t_}
TOOLS_PATH.${_t_}?=	${PKGSRCDIR}/mk/gnu-config/missing
TOOLS_SCRIPT.${_t_}?=	${TOOLS_PATH.${_t_}} ${_t_:T:C/-[0-9].*$//}
.endfor

######################################################################

# These tools are used in the targets that actually create the wrappers
# and symlinks.  We define them here so that as a fallback, we'll just
# use the ones in the PATH.  This makes the tools framework more
# standalone.

CHMOD?=         chmod
ECHO?=          echo
FALSE?=         false
LN?=            ln
MKDIR?=         mkdir -p

######################################################################

# If the command line was defined, then we create a wrapper.
# If the real command isn't a full path, then we create a wrapper.
# If some command arguments were given, then we create a wrapper.
# Otherwise, we create a symlink.
#
# By default, the tool in ${TOOLS_DIR} will be in the "bin" directory
# and will be called <tool>.
#
# The default wrapper script will invoke the real command, followed
# by any arguments specified in TOOLS_ARGS.*, followed by any
# command-line arguments passed to the wrapper script.
#
.for _t_ in ${TOOLS_CREATE}
TOOLS_CMD.${_t_}?=		${TOOLS_DIR}/bin/${_t_}
TOOLS_PATH.${_t_}?=		${FALSE}
TOOLS_SCRIPT_DFLT.${_t_}=	\
	${TOOLS_PATH.${_t_}} ${TOOLS_ARGS.${_t_}} "$$@"

override-tools: ${TOOLS_CMD.${_t_}}

# Note: if you get a warning about a doubly-defined target here, you are
# probably adding a program to USE_TOOLS that is not a valid tool name.
# For instance, "split" is handled outside of the tools framework.
${TOOLS_CMD.${_t_}}:
	${RUN} ${TEST} -d ${.TARGET:H:Q} || ${MKDIR} ${.TARGET:H:Q}
	${RUN}								\
	if ${TEST} -n ${TOOLS_SCRIPT.${_t_}:Q}""; then			\
		create=wrapper;						\
		script=${TOOLS_SCRIPT.${_t_}:Q};			\
	elif ${TEST} -n ${TOOLS_PATH.${_t_}:Q}""; then			\
		if ${TEST} -n ${TOOLS_ARGS.${_t_}:Q}""; then		\
			create=wrapper;					\
			script=${TOOLS_SCRIPT_DFLT.${_t_}:Q};		\
		else							\
			case ${TOOLS_PATH.${_t_}:Q}"" in		\
			/*)	create=symlink ;;			\
			*)	create=wrapper;				\
				script=${TOOLS_SCRIPT_DFLT.${_t_}:Q};	\
			esac;						\
		fi;							\
	else								\
		create=symlink;						\
	fi;								\
	case "$$create" in						\
	wrapper)							\
		{ ${ECHO} '#!'${TOOLS_SHELL:Q};				\
		  ${ECHO} 'wrapperlog="$${TOOLS_WRAPPER_LOG-'${_TOOLS_WRAP_LOG:Q}'}"'; \
		  ${ECHO} '${ECHO} "[*] "'${.TARGET:Q}'" $$@" >> $$wrapperlog'; \
		  ${ECHO} "${ECHO} \"<.> $$script\" >> \$$wrapperlog";	\
		  ${ECHO} "$$script";					\
		} > ${.TARGET:Q};					\
		${CHMOD} +x ${.TARGET:Q};				\
		;;							\
	*)								\
		${LN} -fs ${TOOLS_PATH.${_t_}:Q} ${.TARGET:Q};	\
		;;							\
	esac
.  for _a_ in ${TOOLS_ALIASES.${_t_}}
	${RUN}								\
	${TEST} ${.TARGET:Q} = ${.TARGET:H:Q}/${_a_} ||			\
		${LN} -fs ${.TARGET:T:Q} ${.TARGET:H:Q}/${_a_}
.  endfor
.  if defined(_OPSYS_EXE_SUFFIX) && !empty(_OPSYS_EXE_SUFFIX)
	${RUN}								\
	${TEST} ${.TARGET:E:Q} = ${_OPSYS_EXE_SUFFIX:E:Q} ||		\
		${LN} -fs ${.TARGET:T:Q} ${.TARGET:Q}${_OPSYS_EXE_SUFFIX}
.  endif
.endfor
