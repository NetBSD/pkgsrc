# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:12 joerg Exp $

BUILDLINK_TREE+=	samba

.if !defined(SAMBA_BUILDLINK3_MK)
SAMBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.samba+=	samba>=3.0.7
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # SAMBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-samba
