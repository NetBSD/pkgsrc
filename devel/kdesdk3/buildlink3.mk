# $NetBSD: buildlink3.mk,v 1.4 2005/03/23 22:33:47 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDESDK_BUILDLINK3_MK:=	${KDESDK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdesdk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdesdk}
BUILDLINK_PACKAGES+=	kdesdk

.if !empty(KDESDK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdesdk+=	kdesdk>=3.2.0
BUILDLINK_RECOMMENDED.kdesdk?=	kdesdk>=3.4.0
BUILDLINK_PKGSRCDIR.kdesdk?=	../../devel/kdesdk3
.endif	# KDESDK_BUILDLINK3_MK

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
