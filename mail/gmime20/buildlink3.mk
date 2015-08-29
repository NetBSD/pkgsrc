# $NetBSD: buildlink3.mk,v 1.2 2015/08/29 22:58:21 joerg Exp $

BUILDLINK_TREE+=	gmime20

.if !defined(GMIME20_BUILDLINK3_MK)
GMIME20_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime20+=	gmime20>=2.1.7
BUILDLINK_PKGSRCDIR.gmime20?=	../../mail/gmime20

.include "../../devel/glib2/buildlink3.mk"
.endif # GMIME20_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime20
