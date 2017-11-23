# $NetBSD: buildlink3.mk,v 1.1 2017/11/23 15:42:03 wiz Exp $

BUILDLINK_TREE+=	gmime3

.if !defined(GMIME3_BUILDLINK3_MK)
GMIME3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmime3+=	gmime3>=3.0
BUILDLINK_PKGSRCDIR.gmime3?=	../../mail/gmime3

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.endif # GMIME3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmime3
