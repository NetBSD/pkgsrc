# $Id: cpuflags.mk,v 1.20 2009/01/28 23:30:50 abs Exp $
# Makefile include fragment to simplify use of cpuflags in pkgsrc
# abs@absd.org - freely distributable, no warrenties, stick no bills.

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

. if exists(${.PARSEDIR}/cpuflags.sh)
_CPUFLAGS_SH=${SH} ${.PARSEDIR}/cpuflags.sh
. else
_CPUFLAGS_SH=@PREFIX@/bin/cpuflags
. endif

. if defined(CCPATH)
CPU_FLAGS!=${_CPUFLAGS_SH} ${CCPATH}
. elif defined(BSD_PKG_MK) || ${USETOOLS:Uyes} == "no"
CPU_FLAGS!=${_CPUFLAGS_SH} ${CC}
. else
CPU_FLAGS!=${_CPUFLAGS_SH}
. endif
_CPUFLAGS_SH=

.endif # CPU_FLAGS

.ifndef CPU_DIR
CPU_DIR!=echo ${CPU_FLAGS} | sed 's/ //g'
.endif

.if !defined(MAKEFLAGS) || empty(MAKEFLAGS:MCPU_FLAGS)
MAKEFLAGS+=CPU_FLAGS=${CPU_FLAGS:Q} CPU_DIR=${CPU_DIR:Q}	# For sub makes
.endif

.ifdef BSD_PKG_MK			# Try to catch various package opts
CFLAGS+=${CPU_FLAGS}
CXXFLAGS+=${CPU_FLAGS}
MAKE_FLAGS+=CCOPTIONS="${CPU_FLAGS}"	# Override CCOPTIONS for imake

.elif !defined(IMAGESIZE) && ${DBG} != "-Os"
# Assume in base system & not building space optimised distrib, set COPTS
COPTS?=${CPU_FLAGS} ${DEFCOPTS}
# Include ${DEFCOPTS} and set ?= to allow overriding in kernel builds

.endif
