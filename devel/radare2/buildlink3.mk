# $NetBSD: buildlink3.mk,v 1.8 2020/01/18 21:48:09 jperkin Exp $

BUILDLINK_TREE+=	radare2

.if !defined(RADARE2_BUILDLINK3_MK)
RADARE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.radare2+=	radare2>=2.3.0
BUILDLINK_ABI_DEPENDS.radare2+=	radare2>=3.6.0nb2
BUILDLINK_PKGSRCDIR.radare2?=	../../devel/radare2

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.endif	# RADARE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-radare2
