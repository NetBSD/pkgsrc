# $NetBSD: buildlink3.mk,v 1.13 2016/12/04 05:17:09 ryoon Exp $

BUILDLINK_TREE+=	grilo

.if !defined(GRILO_BUILDLINK3_MK)
GRILO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grilo+=	grilo>=0.2.2
BUILDLINK_ABI_DEPENDS.grilo?=	grilo>=0.2.7nb7
BUILDLINK_PKGSRCDIR.grilo?=	../../net/grilo

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# GRILO_BUILDLINK3_MK

BUILDLINK_TREE+=	-grilo
