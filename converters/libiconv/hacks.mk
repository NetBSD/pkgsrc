# $NetBSD: hacks.mk,v 1.5 2023/11/14 17:51:58 adam Exp $

.if !defined(LIBICONV_HACKS_MK)
LIBICONV_HACKS_MK=	# defined

### [Fri Dec 30 21:00:59 CET 2005 : schwarz]
### make sys/types.h not conflict with inttypes.h
### (issue is specific to IRIX 5.3)
###
.if ${MACHINE_PLATFORM:MIRIX-5.3-*}
PKG_HACKS+=		sys_types_h-inttypes_h-conflict
post-wrapper:
	${MKDIR} ${BUILDLINK_DIR}/include/sys && ${GREP} -v '^typedef.*[^u_]int[12368]*_t;' /usr/include/sys/types.h > ${BUILDLINK_DIR}/include/sys/types.h
# should match int8_t, int16_t, and int32_t (only)
.endif

.endif
