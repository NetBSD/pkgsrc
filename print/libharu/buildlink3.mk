# $NetBSD: buildlink3.mk,v 1.1 2021/05/04 14:12:05 prlw1 Exp $

BUILDLINK_TREE+=	libharu

.if !defined(LIBHARU_BUILDLINK3_MK)
LIBHARU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libharu+=	libharu>=2.4.0
BUILDLINK_PKGSRCDIR.libharu?=	../../print/libharu

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# LIBHARU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libharu
