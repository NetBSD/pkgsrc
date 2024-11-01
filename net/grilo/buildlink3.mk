# $NetBSD: buildlink3.mk,v 1.43 2024/11/01 12:53:51 wiz Exp $

BUILDLINK_TREE+=	grilo

.if !defined(GRILO_BUILDLINK3_MK)
GRILO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grilo+=	grilo>=0.3
BUILDLINK_ABI_DEPENDS.grilo+=	grilo>=0.3.16nb2
BUILDLINK_PKGSRCDIR.grilo?=	../../net/grilo

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.endif	# GRILO_BUILDLINK3_MK

BUILDLINK_TREE+=	-grilo
