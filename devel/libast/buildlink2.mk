# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:51:17 wiz Exp $
#

.if !defined(LIBAST_BUILDLINK2_MK)
LIBAST_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libast
BUILDLINK_DEPENDS.libast?=	libast>=0.5nb3
BUILDLINK_PKGSRCDIR.libast?=	../../devel/libast

EVAL_PREFIX+=	BUILDLINK_PREFIX.libast=libast
BUILDLINK_PREFIX.libast_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libast+=	include/libast.h
BUILDLINK_FILES.libast+=	include/libast/*.h
BUILDLINK_FILES.libast+=	lib/libast.*

.include "../../devel/pcre/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"

BUILDLINK_TARGETS+=	libast-buildlink

libast-buildlink: _BUILDLINK_USE

.endif	# LIBAST_BUILDLINK2_MK
