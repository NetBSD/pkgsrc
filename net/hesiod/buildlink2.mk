# $NetBSD: buildlink2.mk,v 1.5 2004/02/05 07:17:15 jlam Exp $

.if !defined(HESIOD_BUILDLINK2_MK)
HESIOD_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

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

.if !empty(PREFER_PKGSRC:M[yY][eE][sS]) || \
    !empty(PREFER_PKGSRC:Mhesiod)
_NEED_HESIOD=	YES
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
