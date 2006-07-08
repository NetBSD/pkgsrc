# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 22:38:59 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CDDB_BUNDLE_BUILDLINK3_MK:=	${CDDB_BUNDLE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cddb-bundle
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncddb-bundle}
BUILDLINK_PACKAGES+=	cddb-bundle
BUILDLINK_ORDER+=	cddb-bundle

.if !empty(CDDB_BUNDLE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cddb-bundle+=	cddb-bundle>=0.2
BUILDLINK_ABI_DEPENDS.cddb-bundle?=	cddb-bundle>=0.2nb1
BUILDLINK_PKGSRCDIR.cddb-bundle?=	../../audio/cddb-bundle
.endif	# CDDB_BUNDLE_BUILDLINK3_MK

.include "../../devel/gnustep-make/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
