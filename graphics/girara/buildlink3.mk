# $NetBSD: buildlink3.mk,v 1.29 2025/04/24 14:14:20 wiz Exp $

BUILDLINK_TREE+=	girara

.if !defined(GIRARA_BUILDLINK3_MK)
GIRARA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.girara+=	girara>=0.2.8
BUILDLINK_ABI_DEPENDS.girara+=	girara>=0.4.4nb4
BUILDLINK_PKGSRCDIR.girara?=	../../graphics/girara

.include "../../x11/gtk3/buildlink3.mk"
.endif # GIRARA_BUILDLINK3_MK

BUILDLINK_TREE+=	-girara
