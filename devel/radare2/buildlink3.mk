# $NetBSD: buildlink3.mk,v 1.14 2022/06/28 11:33:42 wiz Exp $

BUILDLINK_TREE+=	radare2

.if !defined(RADARE2_BUILDLINK3_MK)
RADARE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.radare2+=	radare2>=5.1.0
BUILDLINK_ABI_DEPENDS.radare2+=	radare2>=5.1.1nb5
BUILDLINK_PKGSRCDIR.radare2?=	../../devel/radare2

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.endif	# RADARE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-radare2
