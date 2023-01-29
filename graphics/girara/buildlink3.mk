# $NetBSD: buildlink3.mk,v 1.18 2023/01/29 21:14:40 ryoon Exp $

BUILDLINK_TREE+=	girara

.if !defined(GIRARA_BUILDLINK3_MK)
GIRARA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.girara+=	girara>=0.2.8
BUILDLINK_ABI_DEPENDS.girara?=	girara>=0.3.7nb3
BUILDLINK_PKGSRCDIR.girara?=	../../graphics/girara

.include "../../x11/gtk3/buildlink3.mk"
.endif # GIRARA_BUILDLINK3_MK

BUILDLINK_TREE+=	-girara
