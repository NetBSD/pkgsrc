# $Id: cpuflags.mk,v 1.5 2002/07/16 10:42:45 abs Exp $
# Makefile include fragment to simplify use of cpuflags in pkgsrc
# abs@netbsd.org - freely distributable, no warrenties, stick no bills.

# Try to optimise based on CPU
# Does not affect any package that overrides CFLAGS/CXXFLAGS/CCOPTIONS
# Sets five variables:
#
#	CPU_FLAGS	The output of cpuflags
#	CFLAGS		Has CPU_FLAGS appended
#	CXXFLAGS	Has CPU_FLAGS appended
#
#	CPU_DIR		CPU_FLAGS with spaces stripped (eg: for use in PACKAGES)

.ifndef CPU_FLAGS

xCPU_FLAGS!=/usr/pkg/bin/cpuflags
xCPU_DIR!=echo ${CPU_FLAGS} | sed 's/ //'
# Make the flags available to sub makes
.MAKEFLAGS+=CPU_FLAGS="${xCPU_FLAGS}" CPU_DIR="${xCPU_DIR}"
CPU_FLAGS=${xCPU_FLAGS}
CPU_DIR=${xCPU_DIR}
.endif

.ifdef BSD_PKG_MK

# Try to catch the various package mechanisms
CFLAGS+=${CPU_FLAGS}
CXXFLAGS+=${CPU_FLAGS}
# Override CCOPTIONS for imake
MAKE_FLAGS+=CCOPTIONS="${CPU_FLAGS}"

.else

# Assume we are in the standard build system, only touch COPTS
COPTS+=${CPU_FLAGS}

.endif
