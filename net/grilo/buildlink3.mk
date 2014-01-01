# $NetBSD: buildlink3.mk,v 1.6 2014/01/01 11:52:07 wiz Exp $

BUILDLINK_TREE+=	grilo

.if !defined(GRILO_BUILDLINK3_MK)
GRILO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grilo+=	grilo>=0.2.2
BUILDLINK_ABI_DEPENDS.grilo?=	grilo>=0.2.6nb2
BUILDLINK_PKGSRCDIR.grilo?=	../../net/grilo

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.endif	# GRILO_BUILDLINK3_MK

BUILDLINK_TREE+=	-grilo
