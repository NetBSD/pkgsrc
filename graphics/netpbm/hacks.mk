# $NetBSD: hacks.mk,v 1.7 2008/02/08 10:34:19 tnn Exp $

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
.if !empty(MACHINE_PLATFORM:MIRIX-5.3-*)
PKG_HACKS+=		sys_types_h-inttypes_h-conflict
post-wrapper:
		${MKDIR} ${BUILDLINK_DIR}/include/sys && ${GREP} -v '^typedef.*[^u_]int[12368]*_t;' /usr/include/sys/types.h > ${BUILDLINK_DIR}/include/sys/types.h
# should match int8_t, int16_t, and int32_t (only)
.endif

### [ Sun Mar  5 20:19:52 CET 2006 : schwarz ]
### work around bug in Apple's gcc-4.0.0
### that shows up when compiling frame.c
###
.if ${OPSYS} == "Darwin" && !empty(PKGSRC_COMPILER:Mgcc)
_BAD_GCC_BUILD!=	${CC} --version | (${GREP} -c '^powerpc-apple-darwin8-gcc-4\.0\.0.*build\ 4061' || ${TRUE})
. if ${_BAD_GCC_BUILD} == "1"
PKG_HACKS+=		apple-gcc-4-bug
BUILDLINK_TRANSFORM+=	rm:-finline-floor # unknown option to gcc-3.3
BUILDLINK_TRANSFORM+=	rm:-mpowerpc64 # prevent internal compiler error
#					 with gcc-3.3 when compiling exif.c
post-wrapper:
		${SED} -e s,/gcc,/gcc-3.3, ${WRKDIR}/.gcc/bin/gcc > ${WRKDIR}/.gcc/bin/gcc-3.3 && ${MV} -f ${WRKDIR}/.gcc/bin/gcc-3.3 ${WRKDIR}/.gcc/bin/gcc && ${CHMOD} a+rx ${WRKDIR}/.gcc/bin/gcc
# use gcc-3.3 instead of gcc-4.0.0
. endif
.endif

.endif
