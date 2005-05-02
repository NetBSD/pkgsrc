# $NetBSD: bsd.tools.mk,v 1.13 2005/05/02 04:35:59 jlam Exp $
#
# This Makefile fragment creates tools under ${TOOLS_DIR} that are
# found before similarly-named tools in the system path.
#
# There are two ways to generate the tool: either create a wrapper script
# or create a symlink:
#
#    TOOLS_WRAP is a whitespace-separated list of tools for which a
#	wrapper script is created.
#
#    TOOLS_SYMLINK is a whitespace-separated list of tools for which a
#	symlink is created.
#
# The following variables specify the details of each <tool>:
#
#    TOOLS_CMD.<tool> is the path to the tool under ${TOOLS_DIR}.  This
#	variable is optional, and if left unspecified it is either
#	derived from TOOLS_REAL_CMD.<tool> for symlinks, or placed in
#	the "bin" directory for wrappers by default.
#
#    TOOLS_REAL_CMD.<tool> is the path to the actual command that is
#	invoked when ${TOOLS_CMD.<tool>} is called.  If <tool> should
#	be a symlink, then this variable is required and should be a
#	full path.  If <tool> should be a wrapper, then this variable
#	is required unless TOOLS_REAL_CMDLINE.<tool> is defined (see
#	below).
#
# The following variables specify further details of each <tool> and
# are used only by tools listed in TOOLS_WRAP:
#
#    TOOLS_ARGS.<tool> additional arguments that are passed to the real
#	command ahead of any command-line arguments.  This variable is
#	optional.
#
#    TOOLS_REAL_CMDLINE.<tool> specifies the full command-line to invoke
#	in the wrapper script when <tool> is called.  This variable is
#	optional, and if left unspecified, then this is built up from
#	TOOLS_REAL_CMD.<tool> and TOOLS_ARGS.<tool> by default.
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

.if !defined(BSD_TOOLS_MK)
BSD_TOOLS_MK=	defined

.include "../../mk/bsd.prefs.mk"

# Prepend ${TOOLS_DIR}/bin to the PATH so that our scripts are found
# first when searching for executables.
#
TOOLS_DIR=	${WRKDIR}/.tools
PREPEND_PATH+=	${TOOLS_DIR}/bin

TOOLS_SHELL?=		${SH}
_TOOLS_WRAP_LOG=	${WRKLOG}

.PHONY: do-tools override-tools
do-tools: override-tools
override-tools: .OPTIONAL

USE_TOOLS?=		# empty

# Include the other mk/tools/*.mk files here that help specify the
# wrappers and symlinks that will be created by this file.  Order
# matters!
#
.include "../../mk/tools/automake.mk"
.include "../../mk/tools/autoconf.mk"
.include "../../mk/tools/texinfo.mk"
.include "../../mk/tools/rpcgen.mk"
.include "../../mk/tools/replace.mk"
.include "../../mk/tools/perl.mk"
.include "../../mk/tools/make.mk"

######################################################################

.for _t_ in ${TOOLS_NOOP}
TOOLS_WRAP+=			${_t_}
TOOLS_CMD.${_t_}?=		${TOOLS_DIR}/bin/${_t_}
TOOLS_REAL_CMDLINE.${_t_}?=	exit 0
.endfor
.undef _t_

.for _t_ in ${TOOLS_BROKEN}
TOOLS_WRAP+=			${_t_}
TOOLS_CMD.${_t_}?=		${TOOLS_DIR}/bin/${_t_}
TOOLS_REAL_CMDLINE.${_t_}?=	exit 1
.endfor
.undef _t_

.for _t_ in ${TOOLS_GNU_MISSING}
TOOLS_WRAP+=			${_t_}
TOOLS_REAL_CMD.${_t_}?=		${PKGSRCDIR}/mk/gnu-config/missing
TOOLS_REAL_CMDLINE.${_t_}?=	${TOOLS_REAL_CMD.${_t_}} ${_t_:T:C/-[0-9].*$//}
.endfor
.undef _t_

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

# The default wrapper script will invoke the real command, followed by
# any arguments specified in TOOLS_ARGS.*, followed by any command-line
# arguments passed to the wrapper script.  By default, the wrapper in
# ${TOOLS_DIR} will be in the "bin" directory and will be called <tool>.
#
.for _t_ in ${TOOLS_WRAP}
TOOLS_REAL_CMD.${_t_}?=		${FALSE}
TOOLS_ARGS.${_t_}?=		# empty
TOOLS_REAL_CMDLINE.${_t_}?=	${TOOLS_REAL_CMD.${_t_}} ${TOOLS_ARGS.${_t_}} "$$@"
TOOLS_CMD.${_t_}?=		${TOOLS_DIR}/bin/${_t_}

# Small optimization: exec the command if it points to a real command
# (specified by a full path).
#
.  if !empty(TOOLS_REAL_CMDLINE.${_t_}:C/^/_asdf_/1:M_asdf_/*)
_TOOLS_EXEC.${_t_}=		exec
.  else
_TOOLS_EXEC.${_t_}=		# empty
.  endif

.  if !empty(TOOLS_CMD.${_t_}:M${TOOLS_DIR}/*) && \
      !target(${TOOLS_CMD.${_t_}})
override-tools: ${TOOLS_CMD.${_t_}}
${TOOLS_CMD.${_t_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} '#!'${TOOLS_SHELL:Q};					\
	  ${ECHO} 'wrapperlog="$${TOOLS_WRAPPER_LOG-'${_TOOLS_WRAP_LOG:Q}'}"'; \
	  ${ECHO} '${ECHO} "[*] "'${TOOLS_CMD.${_t_}:Q}'" $$*" >> $$wrapperlog'; \
	  ${ECHO} '${ECHO} "<.> "'${TOOLS_REAL_CMDLINE.${_t_}:Q}' >> $$wrapperlog'; \
	  ${ECHO} ${_TOOLS_EXEC.${_t_}:Q} ${TOOLS_REAL_CMDLINE.${_t_}:Q}; \
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  endif
.endfor
.undef _t_

######################################################################

# By default, the symlinked tool in ${TOOLS_DIR} will be in the "bin"
# directory and will be called <tool>.
#
.for _t_ in ${TOOLS_SYMLINK}
TOOLS_REAL_CMD.${_t_}?=	${FALSE}
TOOLS_CMD.${_t_}?=	${TOOLS_DIR}/bin/${_t_}

.  if !empty(TOOLS_CMD.${_t_}:M${TOOLS_DIR}/*) && \
      !target(${TOOLS_CMD.${_t_}}) && exists(${TOOLS_REAL_CMD.${_t_}})
override-tools: ${TOOLS_CMD.${_t_}}
${TOOLS_CMD.${_t_}}: ${TOOLS_REAL_CMD.${_t_}}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -sf ${TOOLS_REAL_CMD.${_t_}} ${.TARGET}
.  endif
.endfor
.undef _t_

.endif	# BSD_TOOLS_MK
