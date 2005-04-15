# $NetBSD: rpcgen.mk,v 1.1 2005/04/15 00:00:21 jlam Exp $

# Create an rpcgen script that correctly sets the CPP environment
# variable to a stat(2)able path to a C preprocessor, then invokes
# the real rpcgen.
#
.if !defined(TOOLS_REAL_CMD.rpcgen)
TOOLS_EXECDIRS.rpcgen?=	${TOOLS_EXECDIRS}
.  for _d_ in ${TOOLS_EXECDIRS.rpcgen}
.    if exists(${_d_}/rpcgen)
TOOLS_REAL_CMD.rpcgen?=	${_d_}/rpcgen
.    endif
.  endfor
.  undef _d_
TOOLS_REAL_CMD.rpcgen?=	${FALSE}
.endif
TOOLS_CMD.rpcgen=	${TOOLS_DIR}/bin/rpcgen
.if ${OPSYS} == "NetBSD"
TOOLS_ARGS.rpcgen?=	-b
.endif
RPCGEN?=		rpcgen

.if !target(${TOOLS_CMD.rpcgen})
override-tools: ${TOOLS_CMD.rpcgen}
${TOOLS_CMD.rpcgen}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	( ${ECHO} '#!'${TOOLS_SHELL:Q};					\
	  ${ECHO} 'wrapperlog="$${TOOLS_WRAPPER_LOG-'${_TOOLS_WRAP_LOG:Q}'}"'; \
	  ${ECHO} 'CPP='${WRAPPER_BINDIR:Q}'/cpp"; export CPP';		\
	  ${ECHO} '${ECHO} "[*] '${TOOLS_CMD.rpcgen:Q}' $$*" >> $$wrapperlog'; \
	  ${ECHO} '${ECHO} "<.> '${TOOLS_REAL_CMD.rpcgen:Q} ${TOOLS_ARGS.rpcgen:Q}' $$*" >> $$wrapperlog'; \
	  ${ECHO} ${TOOLS_REAL_CMD.rpcgen:Q} ${TOOLS_ARGS.rpcgen:Q} '"$$@"'; \
	) > ${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}${CHMOD} +x ${.TARGET}
.endif
