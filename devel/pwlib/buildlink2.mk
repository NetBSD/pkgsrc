# $NetBSD: buildlink2.mk,v 1.1 2002/12/23 15:05:10 wiz Exp $
#

.if !defined(PWLIB_BUILDLINK2_MK)
PWLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pwlib
BUILDLINK_DEPENDS.pwlib?=	pwlib>=1.4.4nb2
BUILDLINK_PKGSRCDIR.pwlib?=	../../devel/pwlib

EVAL_PREFIX+=	BUILDLINK_PREFIX.pwlib=pwlib
BUILDLINK_PREFIX.pwlib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pwlib+=	include/ptclib/*.h
BUILDLINK_FILES.pwlib+=	include/ptlib/unix/ptlib/*.h
BUILDLINK_FILES.pwlib+=	include/ptlib/unix/ptlib/*.inl
BUILDLINK_FILES.pwlib+=	include/ptlib/*.h
BUILDLINK_FILES.pwlib+=	include/ptlib/*.inl
BUILDLINK_FILES.pwlib+=	include/ptlib.h
BUILDLINK_FILES.pwlib+=	lib/libpt.*

BUILDLINK_TARGETS+=	pwlib-buildlink

pwlib-buildlink: _BUILDLINK_USE

.endif	# PWLIB_BUILDLINK2_MK
