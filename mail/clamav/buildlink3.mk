# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 22:39:25 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CLAMAV_BUILDLINK3_MK:=	${CLAMAV_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	clamav
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclamav}
BUILDLINK_PACKAGES+=	clamav
BUILDLINK_ORDER+=	clamav

.if !empty(CLAMAV_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.60nb1
BUILDLINK_ABI_DEPENDS.clamav+=	clamav>=0.88nb1
BUILDLINK_PKGSRCDIR.clamav?=	../../mail/clamav
.endif	# CLAMAV_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
