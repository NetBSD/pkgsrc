# $NetBSD: buildlink2.mk,v 1.2 2002/09/19 01:26:42 jlam Exp $

.if !defined(T1LIB_BUILDLINK2_MK)
T1LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		t1lib
BUILDLINK_DEPENDS.t1lib?=	t1lib>=1.3.1
BUILDLINK_PKGSRCDIR.t1lib?=	../../fonts/t1lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.t1lib=t1lib
BUILDLINK_PREFIX.t1lib_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.t1lib=		include/t1lib.h
BUILDLINK_FILES.t1lib+=		include/t1libx.h
BUILDLINK_FILES.t1lib+=		lib/libt1.*
BUILDLINK_FILES.t1lib+=		lib/libt1x.*

BUILDLINK_TARGETS+=	t1lib-buildlink

t1lib-buildlink: _BUILDLINK_USE

.endif	# T1LIB_BUILDLINK2_MK
