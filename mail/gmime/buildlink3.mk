# $NetBSD: buildlink3.mk,v 1.13 2010/09/07 19:04:15 adam Exp $

BUILDLINK_TREE+=	gmime

.if !defined(GMIME_BUILDLINK3_MK)
GMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.4.0
BUILDLINK_PKGSRCDIR.gmime?=	../../mail/gmime

.include "../../devel/glib2/buildlink3.mk"
.endif # GMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime
