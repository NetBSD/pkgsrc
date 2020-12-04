# $NetBSD: buildlink3.mk,v 1.12 2020/12/04 04:56:09 riastradh Exp $

BUILDLINK_TREE+=	samba

.if !defined(SAMBA_BUILDLINK3_MK)
SAMBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.samba+=	samba>=3.0.7<4.0
BUILDLINK_ABI_DEPENDS.samba+=	samba>=3.6.25nb26
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # SAMBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-samba
