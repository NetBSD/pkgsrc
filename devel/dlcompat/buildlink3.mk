# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:12 joerg Exp $

BUILDLINK_TREE+=	dlcompat

.if !defined(DLCOMPAT_BUILDLINK3_MK)
DLCOMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dlcompat+=	dlcompat>=20030629
BUILDLINK_PKGSRCDIR.dlcompat?=	../../devel/dlcompat
BUILDLINK_LDFLAGS.dlcompat+=	-ldl
.endif # DLCOMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dlcompat
