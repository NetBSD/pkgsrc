# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:49 joerg Exp $

BUILDLINK_TREE+=	gambc

.if !defined(GAMBC_BUILDLINK3_MK)
GAMBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gambc+=	gambc>=4.2.6
BUILDLINK_PKGSRCDIR.gambc?=	../../lang/gambc

.include "../../mk/dlopen.buildlink3.mk"
.endif # GAMBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gambc
