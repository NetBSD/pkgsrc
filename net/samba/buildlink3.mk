# $NetBSD: buildlink3.mk,v 1.9 2012/01/30 15:44:02 adam Exp $

BUILDLINK_TREE+=	samba

.if !defined(SAMBA_BUILDLINK3_MK)
SAMBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.samba+=	samba>=3.0.7
BUILDLINK_ABI_DEPENDS.samba+=	samba>=3.0.34nb1
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # SAMBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-samba
