# $NetBSD: buildlink3.mk,v 1.10 2016/02/29 20:00:44 jperkin Exp $

BUILDLINK_TREE+=	R

.if !defined(R_BUILDLINK3_MK)
R_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R+=	R>=1.7.0
BUILDLINK_ABI_DEPENDS.R+=	R>=2.2.1nb2
BUILDLINK_PKGSRCDIR.R?=	../../math/R
.endif # R_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_TREE+=	-R
