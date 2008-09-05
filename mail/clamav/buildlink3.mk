# $NetBSD: buildlink3.mk,v 1.15.6.1 2008/09/05 11:41:53 ghen Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CLAMAV_BUILDLINK3_MK:=	${CLAMAV_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	clamav
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclamav}
BUILDLINK_PACKAGES+=	clamav
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}clamav

.if ${CLAMAV_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.94
BUILDLINK_PKGSRCDIR.clamav?=	../../mail/clamav
.endif	# CLAMAV_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
