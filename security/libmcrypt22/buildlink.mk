# $NetBSD: buildlink.mk,v 1.1.1.1 2002/04/12 18:59:36 jlam Exp $
#
# This Makefile fragment is included by packages that use libmcrypt22.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libmcrypt22 to the dependency pattern
#     for the version of GNU libmcrypt22 desired.
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBMCRYPT22_BUILDLINK_MK)
LIBMCRYPT22_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libmcrypt22?=	libmcrypt22>=2.2.7
DEPENDS+=	${BUILDLINK_DEPENDS.libmcrypt22}:../../security/libmcrypt22

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmcrypt22=libmcrypt22
BUILDLINK_PREFIX.libmcrypt22_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmcrypt22=	include/libmcrypt22/mcrypt.h
BUILDLINK_FILES.libmcrypt22+=	lib/libmcrypt22.*

BUILDLINK_TRANSFORM.libmcrypt22=	-e "s|include/libmcrypt22/|include/|g"
BUILDLINK_TRANSFORM.libmcrypt22+=	-e "s|libmcrypt22\.|libmcrypt.|g"
REPLACE_LIBNAMES_SED+=			-e "s|-lmcrypt|-lmcrypt22|g"

BUILDLINK_TARGETS.libmcrypt22=	# empty
BUILDLINK_TARGETS.libmcrypt22+=	libmcrypt22-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libmcrypt22}

pre-configure: ${BUILDLINK_TARGETS.libmcrypt22}
libmcrypt22-buildlink: _BUILDLINK_USE

.endif	# LIBMCRYPT22_BUILDLINK_MK
