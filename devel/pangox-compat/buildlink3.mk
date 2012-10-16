# $NetBSD: buildlink3.mk,v 1.1 2012/10/16 17:50:03 wiz Exp $

BUILDLINK_TREE+=	pangox-compat

.if !defined(PANGOX_COMPAT_BUILDLINK3_MK)
PANGOX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pangox-compat+=	pangox-compat>=0.0.1
BUILDLINK_PKGSRCDIR.pangox-compat?=	../../devel/pangox-compat

.include "../../devel/pango/buildlink3.mk"
.endif	# PANGOX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pangox-compat
