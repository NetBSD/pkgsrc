# $NetBSD: bsd.tools.mk,v 1.2 2005/04/15 07:33:43 jlam Exp $
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
#    TOOLS_CMD.<tool> is the path to the tool under ${TOOLS_DIR}
#
#    TOOLS_REAL_CMD.<tool> is the path to the actual command that is
#	invoked when ${TOOLS_CMD.<tool>} is called.
#
# If TOOLS_REAL_CMD.<tool> isn't provided, then we search for the a tool
# with the name "<tool>" in ${TOOLS_EXECDIRS.<tool>}, which defaults to
# ${TOOLS_EXECDIRS} == "/bin /sbin /usr/bin /usr/sbin".
#
# The following variables specify further details of each <tool> and
# are used only by tools listed in TOOLS_WRAP:
#
#    TOOLS_ARGS.<tool> additional arguments that are passed to the real
#	command ahead of any command-line arguments.
#
#    TOOLS_REAL_CMDLINE.<tool> specifies the full command-line to invoke
#	in the wrapper script when <tool> is called.  By default, this
#	is built up from TOOLS_REAL_CMD.<tool> and TOOLS_ARGS.<tool>.
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
TOOLS_EXECDIRS=	/bin /sbin /usr/bin /usr/sbin

TOOLS_SHELL?=		${SH}
_TOOLS_WRAP_LOG=	${WRKLOG}

.PHONY: do-tools override-tools
do-tools: override-tools
override-tools: .OPTIONAL

USE_TOOLS?=		# empty

.include "../../mk/tools/automake.mk"
.include "../../mk/tools/autoconf.mk"
.include "../../mk/tools/coreutils.mk"
.include "../../mk/tools/findutils.mk"
.include "../../mk/tools/texinfo.mk"
.include "../../mk/tools/rpcgen.mk"
.include "../../mk/tools/replace.mk"
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

# If TOOLS_REAL_CMD.<tool> isn't defined, then search the directories
# listed in TOOLS_EXECDIRS.<tool> for something called <tool>.  The
# default wrapper script will invoke the real command, followed by
# any arguments specified in TOOLS_ARGS.*, followed by any command-line
# arguments passed to the wrapper script.
#
.for _t_ in ${TOOLS_WRAP}
.  if !defined(TOOLS_REAL_CMD.${_t_})
TOOLS_EXECDIRS.${_t_}?=		${TOOLS_EXECDIRS}
.    for _d_ in ${TOOLS_EXECDIRS.${_t_}}
.      if exists(${_d_}/${_t_})
TOOLS_REAL_CMD.${_t_}?=		${_d_}/${_t_}
.      endif
.    endfor
.    undef _d_
TOOLS_REAL_CMD.${_t_}?=		${FALSE}
.  endif
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
	  ${ECHO} '${ECHO} "[*] '${TOOLS_CMD.${_t_}:Q}' $$*" >> $$wrapperlog'; \
	  ${ECHO} '${ECHO} "<.> '${TOOLS_REAL_CMDLINE.${_t_}:Q}'" >> $$wrapperlog'; \
	  ${ECHO} ${_TOOLS_EXEC.${_t_}:Q} ${TOOLS_REAL_CMDLINE.${_t_}:Q}; \
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.  endif
.endfor
.undef _t_

######################################################################

# If TOOLS_REAL_CMD.<tool> isn't defined, then search the directories
# listed in TOOLS_EXECDIRS.<tool> for something called <tool>.  By
# default, the symlinked tool in ${TOOLS_DIR} will have the same name as
# the real command.
#
.for _t_ in ${TOOLS_SYMLINK}
.  if !defined(TOOLS_REAL_CMD.${_t_})
TOOLS_EXECDIRS.${_t_}?=		${TOOLS_EXECDIRS}
.    for _d_ in ${TOOLS_EXECDIRS.${_t_}}
.      if exists(${_d_}/${_t_})
TOOLS_REAL_CMD.${_t_}?=		${_d_}/${_t_}
.      endif
.    endfor
.    undef _d_
TOOLS_REAL_CMD.${_t_}?=		${FALSE}
.  endif
TOOLS_CMD.${_t_}?=	\
	${TOOLS_REAL_CMD.${_t_}:C/.*\/${TOOLS_REAL_CMD.${_t_}:H:T}\//${TOOLS_DIR}\/${TOOLS_REAL_CMD.${_t_}:H:T}\//}

.  if !empty(TOOLS_CMD.${_t_}:M${TOOLS_DIR}/*) && \
      !target(${TOOLS_CMD.${_t_}}) && exists(${TOOLS_REAL_CMD.${_t_}})
override-tools: ${TOOLS_CMD.${_t_}}
${TOOLS_CMD.${_t_}}: ${TOOLS_REAL_CMD.${_t_}}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} -x "${TOOLS_REAL_CMD.${_t_}}"; then		\
		${MKDIR} ${.TARGET:H};					\
		${LN} -sf ${TOOLS_REAL_CMD.${_t_}} ${.TARGET};	\
	fi
.  endif
.endfor
.undef _t_

.endif	# BSD_TOOLS_MK
