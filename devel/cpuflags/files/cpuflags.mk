# $Id: cpuflags.mk,v 1.1 2001/06/29 11:24:51 abs Exp $
# Makefile include fragment to simplify use of cpuflags in pkgsrc
# abs@netbsd.org - freely distributable, no warrenties, stick no bills.

# Try to optimise based on CPU
# Does not affect Imakefiles, and any package that overrides CFLAGS/CXXFLAGS
# Sets four variables:
#
#	CPU_FLAGS	The output of cpuflags
#	CPU_DIR		CPU_FLAGS with spaces stripped (eg: for use in PACKAGES)
#	CFLAGS		Has CPU_FLAGS appended
#	CXXFLAGS	Has CPU_FLAGS appended
#

.if ! defined(CPU_FLAGS)
CPU_FLAGS!=/usr/pkg/bin/cpuflags
CPU_DIR!=echo ${CPU_FLAGS} | sed 's/ //'
MAKE_ENV+=CPU_FLAGS=${CPU_FLAGS} CPU_DIR=${CPU_DIR}
CFLAGS+=${CPU_FLAGS}
CXXFLAGS+=${CPU_FLAGS}
.endif
