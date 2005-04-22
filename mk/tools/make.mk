# $NetBSD: make.mk,v 1.2 2005/04/22 04:19:26 jlam Exp $

# Always provide a symlink from ${TOOLS_DIR}/bin/make to the "make"
# used to build the package.  This lets a bare "make" invoke the
# correct program if called from within a makefile or script.
#
TOOLS_SYMLINK+=		make
TOOLS_CMD.make=		${TOOLS_DIR}/bin/make
TOOLS_REAL_CMD.make=	${MAKE_PROGRAM}
