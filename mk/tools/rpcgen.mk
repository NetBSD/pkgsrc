# $NetBSD: rpcgen.mk,v 1.4 2005/05/09 01:11:58 jlam Exp $

# Create an rpcgen script that correctly sets the CPP environment
# variable to a stat(2)able path to a C preprocessor, then invokes
# the real rpcgen.
#
TOOLS_CREATE+=		rpcgen
.if !defined(TOOLS_REAL_CMD.rpcgen)
TOOLS_EXECDIRS.rpcgen?=	/bin /sbin /usr/bin /usr/sbin
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
TOOLS_REAL_ARGS.rpcgen?=	-b
.endif
TOOLS_REAL_CMDLINE.rpcgen=	\
	CPP=${WRAPPER_BINDIR:Q}/cpp ${TOOLS_REAL_CMD.rpcgen} ${TOOLS_REAL_ARGS.rpcgen}

# Make ${RPCGEN} call the "rpcgen" through the PATH, which should find
# the rpcgen tool wrapper.
#
RPCGEN?=	rpcgen
