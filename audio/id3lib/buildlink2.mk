# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:21:48 jlam Exp $

.if !defined(ID3LIB_BUILDLINK2_MK)
ID3LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		id3lib
BUILDLINK_DEPENDS.id3lib?=	id3lib>=3.8.0
BUILDLINK_PKGSRCDIR.id3lib?=	../../audio/id3lib

EVAL_PREFIX+=		BUILDLINK_PREFIX.id3lib=id3lib
BUILDLINK_PREFIX.id3lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.id3lib=		include/id3.h
BUILDLINK_FILES.id3lib+=	include/id3/*
BUILDLINK_FILES.id3lib+=	lib/libid3*.*

BUILDLINK_TARGETS+=	id3lib-buildlink

id3lib-buildlink: _BUILDLINK_USE

.endif	# ID3LIB_BUILDLINK2_MK
