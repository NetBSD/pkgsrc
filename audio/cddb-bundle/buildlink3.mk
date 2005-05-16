# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/05/16 09:40:59 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CDDB_BUNDLE_BUILDLINK3_MK:=	${CDDB_BUNDLE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cddb-bundle
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncddb-bundle}
BUILDLINK_PACKAGES+=	cddb-bundle

.if !empty(CDDB_BUNDLE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.cddb-bundle+=	cddb-bundle>=0.2
BUILDLINK_PKGSRCDIR.cddb-bundle?=	../../audio/cddb-bundle
.endif	# CDDB_BUNDLE_BUILDLINK3_MK

.include "../../devel/gnustep-make/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
