# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/24 06:01:06 jlam Exp $

.if !defined(HESIOD_BUILDLINK2_MK)
HESIOD_BUILDLINK2_MK=	# defined

BUILDLINK_DEPENDS.hesiod?=	hesiod>=3.0.2
BUILDLINK_PKGSRCDIR.hesiod?=	../../net/hesiod

.if defined(USE_HESIOD)
_NEED_HESIOD=		YES
.else
.  if exists(/usr/include/hesiod.h)
_NEED_HESIOD=		NO
.  else
_NEED_HESIOD=		YES
.  endif
.endif

.if ${_NEED_HESIOD} == "YES"
BUILDLINK_PACKAGES+=	hesiod
EVAL_PREFIX+=		BUILDLINK_PREFIX.hesiod=hesiod
BUILDLINK_PREFIX.hesiod_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.hesiod=	/usr
.endif

BUILDLINK_FILES.hesiod=		include/hesiod.h
#
# if lib/libhesiod.* does not exists assume hesiod service is included in libc
#
BUILDLINK_FILES.hesiod+=	lib/libhesiod.*

BUILDLINK_TARGETS+=	hesiod-buildlink

hesiod-buildlink: _BUILDLINK_USE

.endif	# HESIOD_BUILDLINK2_MK
