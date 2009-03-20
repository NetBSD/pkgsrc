# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:23:52 joerg Exp $

BUILDLINK_TREE+=	cddb-bundle

.if !defined(CDDB_BUNDLE_BUILDLINK3_MK)
CDDB_BUNDLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cddb-bundle+=	cddb-bundle>=0.2
BUILDLINK_ABI_DEPENDS.cddb-bundle?=	cddb-bundle>=0.2nb1
BUILDLINK_PKGSRCDIR.cddb-bundle?=	../../audio/cddb-bundle

.include "../../devel/gnustep-make/buildlink3.mk"
.endif # CDDB_BUNDLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cddb-bundle
