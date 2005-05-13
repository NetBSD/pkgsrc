# $NetBSD: make.mk,v 1.8 2005/05/13 21:00:12 rillig Exp $
#
# This Makefile fragment creates a tool called "make" under ${TOOLS_DIR}
# that corresponds to the make program used to build the package.
# This lets a bare "make" invoke the correct program if called from
# within a makefile or script.  It also sets MAKE_PROGRAM to the path
# of that make program.  Lastly, pass ${MAKE_PROGRAM} to GNU configure
# scripts in the MAKE variable so that the scripts will embed the
# correct path to the make program used to build the package
# into the generated Makefiles.
#

# Define MAKE_PROGRAM to be the "make" used to build the package.
.if !empty(_USE_TOOLS:Mgmake)
MAKE_PROGRAM=		${GMAKE}
.elif !empty(_USE_TOOLS:Mimake) && defined(_IMAKE_MAKE)
MAKE_PROGRAM=		${_IMAKE_MAKE}
.else
MAKE_PROGRAM=		${MAKE}
.endif

TOOLS_CREATE+=		make
TOOLS_REAL_CMD.make=	${MAKE_PROGRAM}

CONFIGURE_ENV+=		MAKE=${MAKE_PROGRAM:T:Q}
