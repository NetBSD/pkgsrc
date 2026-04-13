# $NetBSD: buildlink3.mk,v 1.1 2026/04/13 15:19:36 kikadf Exp $

BUILDLINK_TREE+=	libopeninput

.if !defined(LIBOPENINPUT_BUILDLINK3_MK)
LIBOPENINPUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopeninput+=	libopeninput>=1.30.2
BUILDLINK_ABI_DEPENDS.libopeninput+=	libopeninput>=1.30.2
BUILDLINK_PKGSRCDIR.libopeninput?=	../../devel/libopeninput

.include "../../devel/input-headers/buildlink3.mk"

.endif # LIBOPENINPUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopeninput
