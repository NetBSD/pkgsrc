# $NetBSD: make.mk,v 1.1 2005/04/15 00:00:21 jlam Exp $

# Always provide a symlink from ${TOOLS_DIR}/bin/make to the "make"
# used to build the package.  This lets a bare "make" invoke the
# correct program if called from within a makefile or script.
#
TOOLS_SYMLINK+=		make
TOOLS_CMD.make=		${TOOLS_DIR}/bin/make
.if !empty(MAKE_PROGRAM:M/*)
TOOLS_REAL_CMD.make=	${MAKE_PROGRAM}
.endif
