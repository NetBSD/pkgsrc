# SPDX-License-Identifier: BSD-2-Clause
#
#	$Id: Generic.mk,v 1.3 2024/07/15 09:10:10 jperkin Exp $
#

.LIBS:		.a

tools  ?= \
	ar \
	lorder \
	ranlib \
	tsort

.for t in ${tools}
${t:tu} := ${t:${M_whence}}
.endfor

# need to make sure this is set
MACHINE_ARCH.${MACHINE} ?= ${MACHINE}
.if empty(MACHINE_ARCH)
MACHINE_ARCH = ${MACHINE_ARCH.${MACHINE}}
.endif

.if !empty(TSORT)
TSORT += -q
.endif


