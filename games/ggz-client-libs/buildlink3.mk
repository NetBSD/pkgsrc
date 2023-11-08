# $NetBSD: buildlink3.mk,v 1.18 2023/11/08 13:19:13 wiz Exp $

BUILDLINK_TREE+=	ggz-client-libs

.if !defined(GGZ_CLIENT_LIBS_BUILDLINK3_MK)
GGZ_CLIENT_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ggz-client-libs+=	ggz-client-libs>=0.0.14.1
BUILDLINK_ABI_DEPENDS.ggz-client-libs+=	ggz-client-libs>=0.0.14.1nb19
BUILDLINK_PKGSRCDIR.ggz-client-libs?=	../../games/ggz-client-libs

.include "../../games/libggz/buildlink3.mk"
.endif # GGZ_CLIENT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ggz-client-libs
