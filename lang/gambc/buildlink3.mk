# $NetBSD: buildlink3.mk,v 1.3 2023/04/26 20:53:23 nikita Exp $

BUILDLINK_TREE+=	gambc

.if !defined(GAMBC_BUILDLINK3_MK)
GAMBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gambc+=	gambc>=4.9.4
BUILDLINK_PKGSRCDIR.gambc?=	../../lang/gambc

.include "../../mk/dlopen.buildlink3.mk"
.endif # GAMBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gambc
