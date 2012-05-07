# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:53:13 dholland Exp $

BUILDLINK_TREE+=	cddb-bundle

.if !defined(CDDB_BUNDLE_BUILDLINK3_MK)
CDDB_BUNDLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cddb-bundle+=	cddb-bundle>=0.2
BUILDLINK_ABI_DEPENDS.cddb-bundle+=	cddb-bundle>=0.2nb1
BUILDLINK_PKGSRCDIR.cddb-bundle?=	../../audio/cddb-bundle

.endif # CDDB_BUNDLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cddb-bundle
