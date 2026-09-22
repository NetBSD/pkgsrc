# $NetBSD: buildlink3.mk,v 1.1 2026/09/22 13:31:37 kikadf Exp $

BUILDLINK_TREE+=	typescript

.if !defined(TYPESCRIPT_BUILDLINK3_MK)
TYPESCRIPT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.typescript?=	build

BUILDLINK_API_DEPENDS.typescript+=	typescript>=6.0.3
BUILDLINK_PKGSRCDIR.typescript?=	../../lang/typescript
.endif	# TYPESCRIPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-typescript
