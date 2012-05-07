# $NetBSD: buildlink3.mk,v 1.3 2012/05/07 01:53:53 dholland Exp $

BUILDLINK_TREE+=	samba

.if !defined(SAMBA_BUILDLINK3_MK)
SAMBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.samba+=	samba>=3.0.7
BUILDLINK_ABI_DEPENDS.samba+=	samba>=3.0.34nb1
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba30

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # SAMBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-samba
