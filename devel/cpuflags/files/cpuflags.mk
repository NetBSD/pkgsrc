# $Id: cpuflags.mk,v 1.6 2002/07/19 09:31:05 abs Exp $
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

CPU_FLAGS!=/usr/pkg/bin/cpuflags
CPU_DIR!=echo ${CPU_FLAGS} | sed 's/ //'
MAKEFLAGS+=CPU_FLAGS=${CPU_FLAGS} CPU_DIR="${CPU_DIR}" 		# For sub makes

.endif

.ifdef BSD_PKG_MK			# Try to catch various package opts
CFLAGS+=${CPU_FLAGS}
CXXFLAGS+=${CPU_FLAGS}
MAKE_FLAGS+=CCOPTIONS="${CPU_FLAGS}"	# Override CCOPTIONS for imake

.else					# Assume in base system, only COPTS
COPTS+=${CPU_FLAGS}

.endif
