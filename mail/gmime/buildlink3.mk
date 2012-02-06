# $NetBSD: buildlink3.mk,v 1.16 2012/02/06 12:40:50 wiz Exp $

BUILDLINK_TREE+=	gmime

.if !defined(GMIME_BUILDLINK3_MK)
GMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.1.7
BUILDLINK_ABI_DEPENDS.gmime?=	gmime>=2.2.25nb4
BUILDLINK_PKGSRCDIR.gmime?=	../../mail/gmime

.include "../../devel/glib2/buildlink3.mk"
.endif # GMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime
