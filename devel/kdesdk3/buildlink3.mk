# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDESDK_BUILDLINK3_MK:=	${KDESDK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdesdk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdesdk}
BUILDLINK_PACKAGES+=	kdesdk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdesdk

.if !empty(KDESDK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.kdesdk+=	kdesdk>=3.5.0nb1
BUILDLINK_ABI_DEPENDS.kdesdk?=	kdesdk>=3.5.2nb1
BUILDLINK_PKGSRCDIR.kdesdk?=	../../devel/kdesdk3
.endif	# KDESDK_BUILDLINK3_MK

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
