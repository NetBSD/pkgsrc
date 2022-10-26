# $NetBSD: buildlink3.mk,v 1.15 2022/10/26 10:31:03 wiz Exp $

BUILDLINK_TREE+=	ggz-client-libs

.if !defined(GGZ_CLIENT_LIBS_BUILDLINK3_MK)
GGZ_CLIENT_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ggz-client-libs+=	ggz-client-libs>=0.0.14.1
BUILDLINK_ABI_DEPENDS.ggz-client-libs+=	ggz-client-libs>=0.0.14.1nb16
BUILDLINK_PKGSRCDIR.ggz-client-libs?=	../../games/ggz-client-libs

.include "../../games/libggz/buildlink3.mk"
.endif # GGZ_CLIENT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ggz-client-libs
