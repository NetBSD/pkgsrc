# $NetBSD: buildlink3.mk,v 1.5 2012/05/07 01:53:21 dholland Exp $

BUILDLINK_TREE+=	dconf

.if !defined(DCONF_BUILDLINK3_MK)
DCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dconf+=	dconf>=0.5.1
BUILDLINK_ABI_DEPENDS.dconf+=	dconf>=0.5.1nb3
BUILDLINK_PKGSRCDIR.dconf?=	../../devel/dconf

.include "../../devel/glib2/buildlink3.mk"
.endif	# DCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-dconf
