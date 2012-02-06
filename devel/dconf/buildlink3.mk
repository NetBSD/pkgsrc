# $NetBSD: buildlink3.mk,v 1.3 2012/02/06 12:39:48 wiz Exp $

BUILDLINK_TREE+=	dconf

.if !defined(DCONF_BUILDLINK3_MK)
DCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dconf+=	dconf>=0.5.1
BUILDLINK_ABI_DEPENDS.dconf?=	dconf>=0.5.1nb2
BUILDLINK_PKGSRCDIR.dconf?=	../../devel/dconf

.include "../../devel/glib2/buildlink3.mk"
.endif	# DCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-dconf
