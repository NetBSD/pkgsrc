# $NetBSD: hacks.mk,v 1.1 2006/01/22 22:16:25 schwarz Exp $

.if !defined(DOCXX_HACKS_MK)
DOCXX_HACKS_MK=	# defined

### [Sat Jan 14 19:03:02 CET 2006: schwarz]
### make sys/types.h not conflict with inttypes.h
### (issue is specific to IRIX 5.3)
###
.if ${LOWER_OPSYS} == "irix5.3"
PKG_HACKS+=		sys_types_h-inttypes_h-conflict
CONFIGURE_ENV+=		ac_cv_header_inttypes_h="no"
CONFIGURE_ENV+=		jm_ac_cv_header_inttypes_h="no"
CONFIGURE_ENV+=		gt_cv_header_inttypes_h="no"
.endif

.endif
