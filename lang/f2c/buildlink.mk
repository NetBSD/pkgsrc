# $NetBSD: buildlink.mk,v 1.2 2001/07/20 01:54:47 jlam Exp $
#
# This Makefile fragment is included by packages that use f2c.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.f2c to the dependency pattern
#     for the version of f2c desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(F2C_BUILDLINK_MK)
F2C_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.f2c?=	f2c>=20001205nb3
DEPENDS+=		${BUILDLINK_DEPENDS.f2c}:../../lang/f2c

EVAL_PREFIX+=		BUILDLINK_PREFIX.f2c=f2c
BUILDLINK_FILES.f2c=	include/f2c.h
BUILDLINK_FILES.f2c+=	lib/libf2c.*
BUILDLINK_FILES.f2c+=	lib/libf2c_p.a
BUILDLINK_FILES.f2c+=	lib/libf2c_pic.a
BUILDLINK_FILES.f2c+=	lib/libF77.*
BUILDLINK_FILES.f2c+=	lib/libF77_p.a
BUILDLINK_FILES.f2c+=	lib/libF77_pic.a
BUILDLINK_FILES.f2c+=	lib/libI77.*
BUILDLINK_FILES.f2c+=	lib/libI77_p.a
BUILDLINK_FILES.f2c+=	lib/libI77_pic.a

BUILDLINK_TARGETS.f2c=	f2c-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.f2c}

pre-configure: ${BUILDLINK_TARGETS.f2c}
f2c-buildlink: _BUILDLINK_USE

.endif	# F2C_BUILDLINK_MK
