# $NetBSD: buildlink3.mk,v 1.3 2021/12/08 16:02:19 adam Exp $

BUILDLINK_TREE+=	gmime3

.if !defined(GMIME3_BUILDLINK3_MK)
GMIME3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime3+=	gmime3>=3.0
BUILDLINK_ABI_DEPENDS.gmime3?=	gmime3>=3.2.7nb1
BUILDLINK_PKGSRCDIR.gmime3?=	../../mail/gmime3

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.endif # GMIME3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime3
