# $Id: cpuflags.mk,v 1.2 2001/12/24 13:25:47 abs Exp $
# Makefile include fragment to simplify use of cpuflags in pkgsrc
# abs@netbsd.org - freely distributable, no warrenties, stick no bills.

# Try to optimise based on CPU
# Does not affect Imakefiles, and any package that overrides CFLAGS/CXXFLAGS
# Sets five variables:
#
#	CPU_FLAGS	The output of cpuflags
#	CFLAGS		Has CPU_FLAGS appended
#	CXXFLAGS	Has CPU_FLAGS appended
#
#	CPU_DIR		CPU_FLAGS with spaces stripped (eg: for use in PACKAGES)
#	LOWER_CPU_DIR	As CPU_FLAGS but all lower case
#

.if ! defined(CPU_FLAGS)
CPU_FLAGS!=/usr/pkg/bin/cpuflags
CPU_DIR!=echo ${CPU_FLAGS} | sed 's/ //'
LOWER_CPU_DIR!=echo ${CPU_DIR} | tr A-Z a-z
MAKE_ENV+=CPU_FLAGS=${CPU_FLAGS} CPU_DIR=${CPU_DIR}
CFLAGS+=${CPU_FLAGS}
CXXFLAGS+=${CPU_FLAGS}
.endif
