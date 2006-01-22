# $NetBSD: hacks.mk,v 1.3 2006/01/22 21:36:31 schwarz Exp $

.if !defined(NETPBM_HACKS_MK)
NETPBM_HACKS_MK=	# defined

### [historic : ???]
### gcc optimization fixes
###
.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
PKG_HACKS+=		optimization
GCC_REQD+=		2.95.3
.endif
.if ${MACHINE_ARCH} == "alpha"
PKG_HACKS+=		optimization
GCC_REQD+=		3.0
.endif

### [Mon Jan 24 20:47:14 UTC 2005 : tv]
### substitute for <inttypes.h> on Interix
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		standard-headers
MAKE_FLAGS+=		INTTYPES_H='<sys/types.h>'
.endif

### [Fri Dec 30 21:00:59 CET 2005 : schwarz]
### make sys/types.h not conflict with inttypes.h
### (issue is specific to IRIX 5.3)
###
.if ${LOWER_OPSYS} == "irix5.3"
PKG_HACKS+=		sys_types_h-inttypes_h-conflict
post-wrapper:
		${MKDIR} ${BUILDLINK_DIR}/include/sys && ${GREP} -v '^typedef.*[^u_]int[12368]*_t;' /usr/include/sys/types.h > ${BUILDLINK_DIR}/include/sys/types.h
# should match int8_t, int16_t, and int32_t (only)
.endif

.endif
