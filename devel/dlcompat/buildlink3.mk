# $NetBSD: buildlink3.mk,v 1.14 2018/01/07 13:04:00 rillig Exp $

BUILDLINK_TREE+=	dlcompat

.if !defined(DLCOMPAT_BUILDLINK3_MK)
DLCOMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dlcompat+=	dlcompat>=20030629
BUILDLINK_PKGSRCDIR.dlcompat?=		../../devel/dlcompat
BUILDLINK_LDFLAGS.dlcompat+=		-ldl
.endif # DLCOMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dlcompat
