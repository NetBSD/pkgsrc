# $Id: cpuflags.mk,v 1.4 2002/06/27 20:49:02 abs Exp $
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
#	LOWER_CPU_DIR	As CPU_FLAGS but all lower case


.ifndef CPU_FLAGS

CPU_FLAGS!=/usr/pkg/bin/cpuflags
CPU_DIR!=echo ${CPU_FLAGS} | sed 's/ //'
LOWER_CPU_DIR!=echo ${CPU_DIR} | tr A-Z a-z
# Make the flags available to make
MAKE_ENV+=CPU_FLAGS=${CPU_FLAGS} CPU_DIR=${CPU_DIR} LOWER_CPU_DIR=${LOWER_CPU_DIR}

.endif

.ifdef BSD_PKG_MK

# Try to catch the varuous package mechanisms
CFLAGS+=${CPU_FLAGS}
CXXFLAGS+=${CPU_FLAGS}
# Override CCOPTIONS for imake
MAKE_FLAGS+=CCOPTIONS=${CPU_FLAGS}

.else

# Assume we are in the standard build system, only touch COPTS
COPTS+=${CPU_FLAGS}

.endif
